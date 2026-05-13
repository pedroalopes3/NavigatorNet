import os

import cv2
import numpy as np
import torch

from .models.superglue import SuperGlue
from .models.superpoint import SuperPoint


class SPGlueMatcher:
    def __init__(self, custom_config=None):
        """
        Inicializa o SuperPoint e SuperGlue.
        """
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        print(f"[SPGlueMatcher] A inicializar modelos no dispositivo: {self.device}")

        # Configurações padrão
        self.config = {
            "superpoint": {
                "nms_radius": 4,
                "keypoint_threshold": 0.0005,
                "max_keypoints": 4096,
            },
            "superglue": {
                "weights": "outdoor",
                "sinkhorn_iterations": 50,
                "match_threshold": 0.2,
            },
        }

        if custom_config is not None:
            if "superpoint" in custom_config:
                self.config["superpoint"].update(custom_config["superpoint"])
            if "superglue" in custom_config:
                self.config["superglue"].update(custom_config["superglue"])

        # iniciar os modelos com os parametros (atualizados do yaml senao usa os default acima)
        self.superpoint = SuperPoint(self.config["superpoint"]).to(self.device)
        self.superglue = SuperGlue(self.config["superglue"]).to(self.device)

        # 2. Bloquear os modelos em modo de inferência (muito importante para não gastar RAM)
        self.superpoint.eval()
        self.superglue.eval()

    def _preprocess_image(self, img: np.ndarray) -> torch.Tensor:
        """
        Converte uma imagem numpy (OpenCV) para o formato Tensor exigido pelo PyTorch [1, 1, H, W].
        """
        if len(img.shape) == 3:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # O SuperPoint precisa que os pixeis estejam entre 0.0 e 1.0 (float32)
        img_float = img.astype(np.float32) / 255.0

        # Adicionar as dimensões de Batch (1) e Canal (1)
        tensor = torch.from_numpy(img_float)[None, None].to(self.device)
        return tensor

    @torch.no_grad()  # Desliga o cálculo de gradientes para dobrar a velocidade de execução
    def match(self, img1: np.ndarray, img2: np.ndarray):
        """
        Executa o pipeline completo.
        Retorna:
            kp1 (np.ndarray): Array de shape [2, N] com coordenadas (x, y) na img1
            kp2 (np.ndarray): Array de shape [2, N] com coordenadas (x, y) na img2
        """
        # Converter para Tensores
        tensor1 = self._preprocess_image(img1)
        tensor2 = self._preprocess_image(img2)

        # Extrair keypoints e descritores com o SuperPoint
        pred1 = self.superpoint({"image": tensor1})
        pred2 = self.superpoint({"image": tensor2})

        # Preparar o dicionário gigante de dados que o SuperGlue exige
        data = {
            "image0": tensor1,
            "image1": tensor2,
            "keypoints0": pred1["keypoints"][0].unsqueeze(0),
            "keypoints1": pred2["keypoints"][0].unsqueeze(0),
            "scores0": pred1["scores"][0].unsqueeze(0),
            "scores1": pred2["scores"][0].unsqueeze(0),
            "descriptors0": pred1["descriptors"][0].unsqueeze(0),
            "descriptors1": pred2["descriptors"][0].unsqueeze(0),
        }

        # Fazer o match das características com o SuperGlue
        pred = self.superglue(data)

        # Extrair os índices e filtrar apenas os "matches" válidos (onde índice > -1)
        matches = pred["matches0"][0].cpu().numpy()
        valid = matches > -1

        # Obter as coordenadas físicas (X, Y) dos pixeis originais
        mkpts1 = pred1["keypoints"][0].cpu().numpy()[valid]
        mkpts2 = pred2["keypoints"][0].cpu().numpy()[matches[valid]]

        # O output atual é [N, 2]. Fazemos a transposta (.T) para ficar no formato [2, N]
        kp1_out = mkpts1.T
        kp2_out = mkpts2.T

        return kp1_out, kp2_out

    @torch.no_grad()
    def match_offline(self, img_cam: np.ndarray, map_features: dict, map_shape: tuple):
        torch.cuda.empty_cache()

        # 1. SuperPoint apenas na câmara
        tensor_cam = self._preprocess_image(img_cam)
        pred_cam = self.superpoint({"image": tensor_cam})

        # 2. Construir dados cruzando GPU em tempo real com Disco pré-calculado
        data = {
            "image0": tensor_cam,
            # Placeholder vazio para o mapa. O SuperGlue só precisa das dimensões, não dos píxeis!
            "image1": torch.empty((1, 1, map_shape[0], map_shape[1]), device=self.device),
            "keypoints0": pred_cam["keypoints"][0].unsqueeze(0),
            "scores0": pred_cam["scores"][0].unsqueeze(0),
            "descriptors0": pred_cam["descriptors"][0].unsqueeze(0),
            
            # Dados que vieram do .npz (Mover para o GPU)
            "keypoints1": torch.from_numpy(map_features["keypoints"]).float().unsqueeze(0).to(self.device),
            "scores1": torch.from_numpy(map_features["scores"]).float().unsqueeze(0).to(self.device),
            "descriptors1": torch.from_numpy(map_features["descriptors"]).float().unsqueeze(0).to(self.device),
        }

        # 3. SuperGlue executa o match final
        pred = self.superglue(data)

        # 4. Extrair e validar
        matches = pred["matches0"][0].cpu().numpy()
        valid = matches > -1

        mkpts_cam = pred_cam["keypoints"][0].cpu().numpy()[valid]
        mkpts_map = map_features["keypoints"][matches[valid]]

        return mkpts_cam.T, mkpts_map.T