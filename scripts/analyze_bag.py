import os
import sys
import numpy as np

# Forçar o Matplotlib a trabalhar em "modo invisível"
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# Importações do ROS 2
import rosbag2_py
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message

def get_rosbag_options(path):
    storage_options = rosbag2_py.StorageOptions(uri=path, storage_id='sqlite3')
    converter_options = rosbag2_py.ConverterOptions(
        input_serialization_format='cdr', 
        output_serialization_format='cdr'
    )
    return storage_options, converter_options

def calculate_overall_error(errors):
    if not errors:
        return 0, 0, 0, 0
    
    valores_erro = [e['error'] for e in errors]
    erros_np = np.array(valores_erro)
    
    mean_error = np.mean(erros_np)
    median_error = np.median(erros_np)
    max_error = np.max(erros_np)
    min_error = np.min(erros_np)
    
    print("\n" + "="*40)
    print("📈 RELATÓRIO DE ERRO GLOBAL (PnP)")
    print("="*40)
    print(f"Erro Médio:   {mean_error:.2f} metros")
    print(f"Erro Mediano: {median_error:.2f} metros")
    print(f"Erro Máximo:  {max_error:.2f} metros")
    print(f"Erro Mínimo:  {min_error:.2f} metros")
    print(f"Total de Matches Válidos: {len(errors)}")
    print("="*40 + "\n")
    
    return mean_error, median_error, max_error, min_error

def plot_health_and_trajectory(true_gps, pnp_pos, errors):
    true_lat = [pt['lat'] for pt in true_gps]
    true_lon = [pt['lon'] for pt in true_gps]
    
    pnp_lat = [pt['lat'] for pt in pnp_pos]
    pnp_lon = [pt['lon'] for pt in pnp_pos]
    
    err_vals = [e['error'] for e in errors]
    err_times = [e['time'] for e in errors]
    
    if len(err_times) > 0:
        start_time = err_times[0]
        err_times = [(t - start_time) * 1e-9 for t in err_times]

    # ALTERAÇÃO: Criar a figura na horizontal (1 linha, 2 colunas) e mais larga (16x7)
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 7))
    fig.suptitle('Análise de Navegação Visual (PnP vs GPS)', fontsize=16, fontweight='bold')

    # ---------------------------------------------------------
    # GRÁFICO 1: Trajetória (Esquerda)
    # ---------------------------------------------------------
    ax1.plot(true_lon, true_lat, 'b-', label='True GPS (Sensor)', linewidth=2, alpha=0.7)
    ax1.scatter(pnp_lon, pnp_lat, c='r', label='Estimativa IA (PnP)', s=15, zorder=5)
    
    if true_lat:
        avg_lat = np.mean(true_lat)
        aspect_ratio = 1.0 / np.cos(np.radians(avg_lat))
        ax1.set_aspect(aspect_ratio)

    ax1.set_title('Trajetória do Drone', fontsize=12)
    ax1.set_xlabel('Longitude')
    ax1.set_ylabel('Latitude')
    ax1.legend()
    ax1.grid(True, linestyle='--', alpha=0.6)

    # ---------------------------------------------------------
    # GRÁFICO 2: Erro em Escala Logarítmica (Direita)
    # ---------------------------------------------------------
    ax2.plot(err_times, err_vals, 'k-', linewidth=1.2, label='Erro de Posição')
    
    ax2.set_yscale('log')
    
    # ALTERAÇÃO: O limite inferior agora é o erro mínimo (com proteção contra 0.0)
    min_error_real = min(err_vals) if err_vals else 1.0
    min_y = min_error_real if min_error_real > 0 else 0.001 
    ax2.set_ylim(bottom=min_y)

    limite_verde = 200.0
    limite_amarelo = 400.0
    max_erro_grafico = max(max(err_vals) * 1.5, 1000.0) if err_vals else 1000.0
    
    ax2.axhline(y=limite_verde, color='g', linestyle='--', linewidth=2, label='OK (<= 200m)')
    ax2.axhline(y=limite_amarelo, color='y', linestyle='--', linewidth=2, label='Aviso (<= 400m)')

    ax2.fill_between(err_times, min_y, limite_verde, color='green', alpha=0.15)
    ax2.fill_between(err_times, limite_verde, limite_amarelo, color='yellow', alpha=0.2)
    ax2.fill_between(err_times, limite_amarelo, max_erro_grafico, color='red', alpha=0.15)

    ax2.set_title('Métrica de Saúde: Erro de Translação (Log Scale)', fontsize=12)
    ax2.set_xlabel('Tempo (Segundos)')
    ax2.set_ylabel('Erro (Metros)')
    ax2.legend(loc='upper right')
    ax2.grid(True, which="both", linestyle='--', alpha=0.4)
    
    plt.tight_layout()
    output_file = 'resultados_pnp.png'
    plt.savefig(output_file, dpi=300)
    print(f"✅ Gráficos gerados com sucesso! Imagem guardada como: {output_file}")


def main():
    bag_path = "pnp_processed_run_v2"
    
    if not os.path.exists(bag_path):
        print(f"Erro: A pasta da bag '{bag_path}' não foi encontrada.")
        sys.exit(1)

    print(f"A abrir a bag: {bag_path}...")
    
    storage_options, converter_options = get_rosbag_options(bag_path)
    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)

    topic_types = reader.get_all_topics_and_types()
    type_map = {topic.name: topic.type for topic in topic_types}

    true_gps_data = []
    pnp_pos_data = []
    pnp_error_data = []

    count = 0
    topicos_alvo = ['/drone/true_gps', '/camera/pnp_position', '/camera/pnp_error']
    outliers_alt = 0
    outliers_err = 0

    while reader.has_next():
        (topic, data, t) = reader.read_next()
        count += 1
        
        if topic in topicos_alvo:
            msg_type = type_map[topic]
            msg_class = get_message(msg_type)
            msg = deserialize_message(data, msg_class)

            if topic == '/drone/true_gps':
                true_gps_data.append({'lat': msg.latitude, 'lon': msg.longitude, 'time': t})
                
            elif topic == '/camera/pnp_position':
                if 10.0 <= msg.altitude <= 1000.0:
                    pnp_pos_data.append({'lat': msg.latitude, 'lon': msg.longitude, 'time': t})
                else:
                    outliers_alt += 1
                
            elif topic == '/camera/pnp_error':
                if msg.data <= 1000.0:
                    pnp_error_data.append({'error': msg.data, 'time': t})
                else:
                    outliers_err += 1

    if outliers_alt > 0 or outliers_err > 0:
        print(f"🧹 Filtro de Outliers: Removidas {outliers_alt} altitudes inválidas e {outliers_err} erros > 1000m.")

    calculate_overall_error(pnp_error_data)

    if len(true_gps_data) > 0 and len(pnp_pos_data) > 0:
        plot_health_and_trajectory(true_gps_data, pnp_pos_data, pnp_error_data)
    else:
        print("⚠️ Aviso: Dados insuficientes para gerar os gráficos.")

if __name__ == '__main__':
    main()