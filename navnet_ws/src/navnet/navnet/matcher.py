import os

import cv2
import numpy as np
import torch
from lightglue import LightGlue

from .models.superpoint import SuperPoint


class SPLightGlueMatcher:
    def __init__(self, custom_config=None):
        """
        Inicializa o SuperPoint e LightGlue.
        """
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        print(f"[SPLightGlueMatcher] A inicializar modelos no dispositivo: {self.device}")

        # Configurações padrão LightGlue
        self.config = {
            "superpoint": {
                "nms_radius": 4,
                "keypoint_threshold": 0.0005,
                "max_keypoints": 4096,
            },
            "lightglue": {
                "depth_confidence": 0.95,
                "width_confidence": 0.99,
                "filter_threshold": 0.1,  # substitui o match_threshold
            },
        }

        if custom_config is not None:
            if "superpoint" in custom_config:
                self.config["superpoint"].update(custom_config["superpoint"])
            if "lightglue" in custom_config:
                self.config["lightglue"].update(custom_config["lightglue"])

        # Iniciar os modelos
        self.superpoint = SuperPoint(self.config["superpoint"]).to(self.device)
        self.lightglue = LightGlue(features="superpoint", **self.config["lightglue"]).to(
            self.device
        )

        self.superpoint.eval()
        self.lightglue.eval()

    def _preprocess_image(self, img: np.ndarray) -> torch.Tensor:
        if len(img.shape) == 3:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        img_float = img.astype(np.float32) / 255.0
        tensor = torch.from_numpy(img_float)[None, None].to(self.device)
        return tensor

    @torch.no_grad()
    def match(self, img1: np.ndarray, img2: np.ndarray):
        tensor1 = self._preprocess_image(img1)
        tensor2 = self._preprocess_image(img2)

        pred1 = self.superpoint({"image": tensor1})
        pred2 = self.superpoint({"image": tensor2})

        # Extrair descriptores
        desc1 = pred1["descriptors"][0].unsqueeze(0)
        desc2 = pred2["descriptors"][0].unsqueeze(0)

        # LightGlue exige descriptores no formato [B, N, D], enquanto o SuperPoint antigo gera [B, D, N] (D=256)
        if desc1.shape[1] == 256:
            desc1 = desc1.transpose(1, 2)
            desc2 = desc2.transpose(1, 2)

        # Estrutura aninhada exigida pelo LightGlue
        data = {
            "image0": {
                "keypoints": pred1["keypoints"][0].unsqueeze(0),
                "keypoint_scores": pred1["scores"][0].unsqueeze(0),
                "descriptors": desc1,
            },
            "image1": {
                "keypoints": pred2["keypoints"][0].unsqueeze(0),
                "keypoint_scores": pred2["scores"][0].unsqueeze(0),
                "descriptors": desc2,
            },
        }

        # Inferência LightGlue
        pred = self.lightglue(data)

        # Extrair matches diretos [M, 2]
        matches = pred["matches"][0].cpu().numpy()

        if len(matches) == 0:
            return np.empty((2, 0)), np.empty((2, 0))

        # Obter as coordenadas físicas (X, Y)
        mkpts1 = pred1["keypoints"][0].cpu().numpy()[matches[:, 0]]
        mkpts2 = pred2["keypoints"][0].cpu().numpy()[matches[:, 1]]

        # Transpor para formato [2, N]
        return mkpts1.T, mkpts2.T
        # return kp1_out, kp2_out

    @torch.no_grad()
    def match_offline(self, img_cam: np.ndarray, map_features: dict, map_shape: tuple):
        torch.cuda.empty_cache()

        # SuperPoint apenas na câmara
        tensor_cam = self._preprocess_image(img_cam)
        pred_cam = self.superpoint({"image": tensor_cam})

        # O superpoint devolve  [256, N] lightglue exige [N, 256] rodar a matriz
        desc_cam = pred_cam["descriptors"][0].transpose(0, 1)
        desc_map = (
            torch.from_numpy(map_features["descriptors"]).float().to(self.device).transpose(0, 1)
        )

        # merdas para o lightglue
        feats0 = {
            "keypoints": pred_cam["keypoints"][0].unsqueeze(0),
            "scores": pred_cam["scores"][0].unsqueeze(0),
            "descriptors": desc_cam.unsqueeze(0),
            # O LightGlue precisa do tamanho da imagem [Largura, Altura]
            "image_size": torch.tensor(
                [[tensor_cam.shape[3], tensor_cam.shape[2]]], device=self.device
            ),
        }

        feats1 = {
            "keypoints": torch.from_numpy(map_features["keypoints"])
            .float()
            .unsqueeze(0)
            .to(self.device),
            "scores": torch.from_numpy(map_features["scores"]).float().unsqueeze(0).to(self.device),
            "descriptors": desc_map.unsqueeze(0),
            # map_shape vem do main.py como (Altura, Largura)
            "image_size": torch.tensor([[map_shape[1], map_shape[0]]], device=self.device),
        }

        # interação lightglue
        pred = self.lightglue({"image0": feats0, "image1": feats1})

        # extrair
        matches = pred["matches"][0].cpu().numpy()  # Array de shape [N, 2]

        if len(matches) == 0:
            return np.array([]), np.array([])

        # Índices dos matches válidos
        m0 = matches[:, 0]
        m1 = matches[:, 1]

        # Ir buscar as coordenadas usando os índices
        mkpts_cam = feats0["keypoints"][0].cpu().numpy()[m0]
        mkpts_map = feats1["keypoints"][0].cpu().numpy()[m1]

        return mkpts_cam.T, mkpts_map.T
