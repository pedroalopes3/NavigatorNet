import airsim
import time
import os

# Configuração
OUTPUT_FILE = "FOTO_SATELITE_4K.png"
ALTITUDE = 800  # Altura suficiente para ver o bairro todo (ajuste se cortar casas)

def take_one_photo():
    client = airsim.MultirotorClient()
    client.confirmConnection()
    client.enableApiControl(True)

    print(f"1. A posicionar drone a {ALTITUDE}m de altura...")
    
    # Teletransportar para o centro (0,0) a olhar para baixo (-90 graus)
    client.simSetVehiclePose(
        airsim.Pose(
            airsim.Vector3r(0, 0, -ALTITUDE),
            airsim.to_quaternion(pitch=-1.57, roll=0, yaw=0)
        ),
        True
    )
    
    # Esperar 3 segundos para garantir que a imagem carrega completamente
    print("2. A aguardar renderização...")
    time.sleep(3)

    print("3. A capturar foto 4K...")
    # Pedir imagem comprimida (PNG) para garantir que não há erros de formato
    responses = client.simGetImages([
        airsim.ImageRequest("bottom_center", airsim.ImageType.Scene, False, True)
    ])
    
    if responses[0].image_data_uint8:
        airsim.write_file(OUTPUT_FILE, responses[0].image_data_uint8)
        print(f"\n[SUCESSO] Imagem guardada: {os.path.abspath(OUTPUT_FILE)}")
    else:
        print("[ERRO] A câmara não devolveu dados.")

    client.enableApiControl(False)

if __name__ == "__main__":
    take_one_photo()