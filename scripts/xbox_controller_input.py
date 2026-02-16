import airsim
import pygame
import time
import sys

# --- CONFIGURAÇÕES ---
SPEED = 5.0          # Velocidade máxima (m/s)
ROTATION_SPEED = 30  # Velocidade de rotação (graus/s)
CLIMB_SPEED = 3.0    # Velocidade de subida/descida (m/s)

def connect_airsim():
    print("A conectar ao AirSim...")
    client = airsim.MultirotorClient()
    client.confirmConnection()
    client.enableApiControl(True)
    print("Conectado! Pressione 'A' no comando para descolar.")
    return client

def main():
    # Inicializar Pygame para ler o comando
    pygame.init()
    pygame.joystick.init()

    if pygame.joystick.get_count() == 0:
        print("ERRO: Nenhum comando detetado! Verifique o Bluetooth/Cabo.")
        sys.exit(1)

    # Configurar o primeiro comando encontrado
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"Comando detetado: {joystick.get_name()}")

    client = connect_airsim()
    
    # Estado inicial
    is_flying = False

    try:
        while True:
            # Processar eventos do Pygame (botões)
            for event in pygame.event.get():
                if event.type == pygame.JOYBUTTONDOWN:
                    # Botão A (Index 0) -> Descolar
                    if event.button == 0: 
                        print("A descolar...")
                        client.armDisarm(True)
                        client.takeoffAsync().join()
                        is_flying = True
                    
                    # Botão B (Index 1) -> Aterrar
                    elif event.button == 1:
                        print("A aterrar...")
                        client.landAsync().join()
                        client.armDisarm(False)
                        is_flying = False
                    
                    # Botão X (Index 2) -> Tirar Foto VGL
                    elif event.button == 2:
                        print("FOTO!")
                        responses = client.simGetImages([airsim.ImageRequest("3", airsim.ImageType.Scene)])
                        airsim.write_file(f"foto_{time.time()}.png", responses[0].image_data_uint8)

            if is_flying:
                # Ler Eixos Analógicos (Valores entre -1.0 e 1.0)
                # Nota: Os índices dos eixos podem variar ligeiramente entre comandos Xbox One/Series X
                # Geralmente: 0=LS_X, 1=LS_Y, 2=LT, 3=RS_X, 4=RS_Y, 5=RT
                
                # Stick Esquerdo: Movimento Planar (Pitch/Roll)
                # Invertemos o Y (axis 1) porque "para cima" no stick é negativo (-1)
                vx = -joystick.get_axis(1) * SPEED  # Frente/Trás
                vy = joystick.get_axis(0) * SPEED   # Esquerda/Direita
                
                # Stick Direito: Yaw e Altitude
                yaw = joystick.get_axis(2) * ROTATION_SPEED # Rotação (Atenção: verifique se é eixo 2 ou 3)
                vz = -joystick.get_axis(3) * CLIMB_SPEED    # Subir/Descer (Atenção: verifique se é eixo 3 ou 4)

                # Zona morta (Deadzone) para evitar deriva se o stick estiver solto
                if abs(vx) < 0.1: vx = 0
                if abs(vy) < 0.1: vy = 0
                if abs(yaw) < 0.1: yaw = 0
                if abs(vz) < 0.1: vz = 0

                # Enviar comando de velocidade para o drone
                # moveByVelocityBodyFrameAsync move relativo à frente do drone
                # vz positivo = descer, vz negativo = subir (sistema NED)
                client.moveByVelocityBodyFrameAsync(
                    vx, vy, -vz, # Invertemos vz de novo para ser intuitivo (cima=subir)
                    0.1, 
                    airsim.DrivetrainType.MaxDegreeOfFreedom, 
                    airsim.YawMode(True, yaw)
                ).join()

            time.sleep(0.05) # Loop a 20Hz

    except KeyboardInterrupt:
        print("\nA sair...")
        client.enableApiControl(False)
        pygame.quit()

if __name__ == "__main__":
    main()