import os

import cv2
import numpy as np
import torch
import torchvision.transforms as T
from PIL import Image

# Import the specific NetVLAD model architecture you downloaded
# (Adjust this import based on the specific PyTorch repo you use)
from navnet.models.NetVLAD.netvlad import get_netvlad_model


class NetVLADExtractor:
    def __init__(self, weight_path: str):
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        print(f"[NetVLAD] Initializing VGG-16 NetVLAD on {self.device}...")

        if not os.path.exists(weight_path):
            raise FileNotFoundError(f"NetVLAD weights not found at: {weight_path}")

        # 1. Load the model architecture and weights
        self.model = get_netvlad_model()
        checkpoint = torch.load(weight_path, map_location=self.device, weights_only=False)
        self.model.load_state_dict(checkpoint["state_dict"], strict=False)
        self.model.to(self.device)
        self.model.eval()

        # 2. Standard ImageNet Preprocessing (Required for VGG-16 backbone)
        self.transform = T.Compose(
            [
                T.Resize((480, 640)),  # NetVLAD can handle rectangles, unlike TransGeo!
                T.ToTensor(),
                T.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
            ]
        )
        print("[NetVLAD] Initialization complete.")

    @torch.no_grad()
    def extract_fingerprint(self, cv_img: np.ndarray) -> np.ndarray:
        if cv_img is None:
            return np.array([])

        # OpenCV BGR to RGB
        img_rgb = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        pil_img = Image.fromarray(img_rgb)

        # Preprocess and push to GPU
        tensor_img = self.transform(pil_img).unsqueeze(0).to(self.device)

        # Extract the global descriptor (usually a 4096-dimensional vector)
        feature_vector = self.model(tensor_img)

        # Flatten and return to CPU
        return feature_vector.cpu().numpy().flatten()
