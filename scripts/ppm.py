import os
import json
import click
import requests
import mercantile
import math  # Adicionado para cálculos trigonométricos
from concurrent.futures import ThreadPoolExecutor, as_completed
from tqdm import tqdm

http_session = requests.Session()
http_session.headers.update({
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
})

def calculate_ppm(latitude, zoom, high_res=False):
    """
    Calcula Pixels Per Meter (PPM) para uma latitude e zoom específicos.
    Fórmula: S = (C * cos(lat)) / 2^(zoom + 8) -> Meters Per Pixel
    PPM = 1 / S
    """
    C = 40075016.686
    lat_rad = math.radians(latitude)
    
    exponent = 9 if high_res else 8
    
    meters_per_pixel = (C * math.cos(lat_rad)) / (2**(zoom + exponent))
    ppm = 1.0 / meters_per_pixel
    return ppm

def fetch_and_save_tile(tile, output_dir, high_res=False):
    if high_res:
        url = f"https://mt1.google.com/vt/lyrs=s&x={tile.x}&y={tile.y}&z={tile.z}&scale=2"
        tile_size = 512
    else:
        url = f"https://mt1.google.com/vt/lyrs=s&x={tile.x}&y={tile.y}&z={tile.z}"
        tile_size = 256

    filename = f"{tile.z}_{tile.x}_{tile.y}.jpg"
    filepath = os.path.join(output_dir, filename)
    
    bounds = mercantile.bounds(tile)
    tile_info = {
        "filename": filename,
        "bounds": {"west": bounds.west, "south": bounds.south, "east": bounds.east, "north": bounds.north}
    }

    if os.path.exists(filepath):
        return True, tile_info, tile_size

    try:
        response = http_session.get(url, timeout=5)
        if response.status_code == 200:
            with open(filepath, 'wb') as f:
                f.write(response.content)
            return True, tile_info, tile_size
    except requests.RequestException:
        pass
    return False, None, tile_size

@click.command()
@click.option('--bbox', nargs=4, type=float, required=True, help="West South East North")
@click.option('--zoom', '-z', type=int, multiple=True, required=True, help="Zoom levels (ex: -z 18 -z 19)")
@click.option('--out-dir', '-o', type=click.Path(), default="tiles_output")
@click.option('--workers', '-w', type=int, default=10)
@click.option('--high-res', is_flag=True)
def main(bbox, zoom, out_dir, workers, high_res):
    west, south, east, north = bbox
    center_lat = (south + north) / 2
    os.makedirs(out_dir, exist_ok=True)
    
    click.echo(f"Área: {west}, {south}, {east}, {north}")
    click.echo("-" * 40)
    
    ppm_data = {}
    for z in zoom:
        ppm = calculate_ppm(center_lat, z, high_res)
        ppm_data[z] = ppm
        click.echo(f"Zoom {z} | PPM: {ppm:.4f} px/m | Resolução: {1/ppm:.4f} m/px")
    
    click.echo("-" * 40)

    for z in zoom:
        tiles = list(mercantile.tiles(west, south, east, north, zooms=[z]))
        success_count = 0
        metadata = []
        
        zoom_dir = os.path.join(out_dir, str(z))
        os.makedirs(zoom_dir, exist_ok=True)

        with ThreadPoolExecutor(max_workers=workers) as executor:
            futures = {executor.submit(fetch_and_save_tile, t, zoom_dir, high_res): t for t in tiles}
            for f in tqdm(as_completed(futures), total=len(tiles), desc=f"Zoom {z}"):
                success, info, _ = f.result()
                if success:
                    success_count += 1
                    # A LINHA INFO["PPM"] FOI REMOVIDA DAQUI
                    metadata.append(info)

        # Guardar metadata com informação de PPM e High-Res no topo
        with open(os.path.join(zoom_dir, "metadata.json"), "w") as f:
            json.dump({
                "zoom": z, 
                "center_lat": center_lat, 
                "ppm": ppm_data[z], 
                "high_res": high_res,
                "tiles": metadata
            }, f, indent=4)

if __name__ == '__main__':
    main()