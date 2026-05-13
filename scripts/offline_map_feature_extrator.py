import os
import cv2
import torch
import numpy as np
from tqdm import tqdm
from navnet.models.superpoint import SuperPoint 


MAP_DIR = "/workspace/tiles_output" # Ajusta ao teu caminho
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"
SCALE = 0.5 

def extract_offline():
    print(f"A carregar SuperPoint em {DEVICE}...")
    superpoint = SuperPoint({
        "nms_radius": 4, 
        "keypoint_threshold": 0.005, 
        "max_keypoints": 1024
    }).to(DEVICE).eval()

    image_files = []
    for root, dirs, files in os.walk(MAP_DIR):
        for file in files:
            if file.endswith(".jpg") or file.endswith(".png"):
                image_files.append(os.path.join(root, file))

    print(f"Encontradas {len(image_files)} tiles para pré-processar.")

    for img_path in tqdm(image_files):
        npz_path = img_path.rsplit('.', 1)[0] + ".npz"
        if os.path.exists(npz_path): 
            continue # Salta se já foi processado

        img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
        if img is None: continue
        
        # Aplicar escala offline
        if SCALE != 1.0:
            img = cv2.resize(img, (int(img.shape[1] * SCALE), int(img.shape[0] * SCALE)))

        tensor = torch.from_numpy(img.astype(np.float32) / 255.0)[None, None].to(DEVICE)

        with torch.no_grad():
            pred = superpoint({'image': tensor})
        
        np.savez(
            npz_path,
            keypoints=pred['keypoints'][0].cpu().numpy(),
            scores=pred['scores'][0].cpu().numpy(),
            descriptors=pred['descriptors'][0].cpu().numpy()
        )

if __name__ == "__main__":
    extract_offline()