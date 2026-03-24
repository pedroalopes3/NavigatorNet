import os
import json
import click
import requests
import mercantile
from concurrent.futures import ThreadPoolExecutor, as_completed
from tqdm import tqdm

http_session = requests.Session()
http_session.headers.update({
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
})

def fetch_and_save_tile(tile, output_dir, high_res=False):
    """Fetches a single tile, saves it, and calculates its bounding box."""
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
        "bounds": {
            "west": bounds.west,
            "south": bounds.south,
            "east": bounds.east,
            "north": bounds.north
        }
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
@click.option('--bbox', nargs=4, type=float, required=True, 
              help="Bounding box: west south east north")
# MUDANÇA: multiple=True permite usares -z 16 -z 17 no mesmo comando!
@click.option('--zoom', '-z', multiple=True, type=int, required=True, help="Target zoom level(s)")
@click.option('--out-dir', '-o', type=click.Path(), default="tiles_output", help="Output directory")
@click.option('--workers', '-w', type=int, default=10, help="Concurrent downloads")
@click.option('--high-res', is_flag=True, help="Use scale=2 to pull 512px retina tiles")
def main(bbox, zoom, out_dir, workers, high_res):
    """Downloads Google Map tiles"""
    west, south, east, north = bbox
    
    click.echo(f"Bounding Box: {west}, {south}, {east}, {north}")
    click.echo(f"Zoom Levels: {zoom} | High-Res: {high_res}")
    
    # MUDANÇA: Agora iteramos sobre todos os zooms passados no comando
    for z in zoom:
        # 1. Cria a pasta específica para o zoom (ex: tiles_output/16)
        zoom_dir = os.path.join(out_dir, str(z))
        os.makedirs(zoom_dir, exist_ok=True)
        
        tiles = list(mercantile.tiles(west, south, east, north, zooms=[z]))
        total_tiles = len(tiles)
        
        click.echo(f"\n--- A processar Zoom {z} ({total_tiles} tiles) ---")
        
        success_count = 0
        metadata_tiles = []

        # Download Phase
        with ThreadPoolExecutor(max_workers=workers) as executor:
            future_to_tile = {
                # MUDANÇA: Passamos o 'zoom_dir' em vez do 'out_dir' geral
                executor.submit(fetch_and_save_tile, tile, zoom_dir, high_res): tile 
                for tile in tiles
            }
            
            for future in tqdm(as_completed(future_to_tile), total=total_tiles, desc=f"Downloading Z={z}"):
                success, tile_info, tile_size = future.result()
                if success:
                    success_count += 1
                    metadata_tiles.append(tile_info)

        # MUDANÇA: Estrutura o JSON exatamente como o MapRepoManager gosta
        metadata_dict = {
            "zoom": z,
            "high_res": high_res,
            "ppm": 0.0,  # O teu MapManager recalcula isto internamente, pode ficar a 0
            "tiles": metadata_tiles
        }

        # Guarda o metadata.json DENTRO da pasta do zoom
        metadata_path = os.path.join(zoom_dir, "metadata.json")
        with open(metadata_path, "w") as f:
            json.dump(metadata_dict, f, indent=4)

if __name__ == '__main__':
    main()