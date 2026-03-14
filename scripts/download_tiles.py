import os
import json
import click
import requests
import mercantile
from concurrent.futures import ThreadPoolExecutor, as_completed
from tqdm import tqdm
from PIL import Image



http_session = requests.Session()
http_session.headers.update({
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
})

def fetch_and_save_tile(tile, output_dir, high_res=False):
    """Fetches a single tile, saves it, and calculates its bounding box."""
    # Determine URL and tile pixel size based on high_res flag
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
@click.option('--zoom', '-z', type=int, required=True, help="Target zoom level")
@click.option('--out-dir', '-o', type=click.Path(), default="tiles_output", help="Output directory")
@click.option('--workers', '-w', type=int, default=10, help="Concurrent downloads")
@click.option('--high-res', is_flag=True, help="Use scale=2 to pull 512px retina tiles")
def main(bbox, zoom, out_dir, workers, high_res):
    """Downloads Google Map tiles """
    west, south, east, north = bbox
    os.makedirs(out_dir, exist_ok=True)
    
    tiles = list(mercantile.tiles(west, south, east, north, zooms=[zoom]))
    total_tiles = len(tiles)
    
    click.echo(f"Bounding Box: {west}, {south}, {east}, {north}")
    click.echo(f"Zoom Level: {zoom} | Total tiles: {total_tiles} | High-Res: {high_res}")
    
    success_count = 0
    metadata = []
    actual_tile_size = 256

    # Download Phase
    with ThreadPoolExecutor(max_workers=workers) as executor:
        future_to_tile = {
            executor.submit(fetch_and_save_tile, tile, out_dir, high_res): tile 
            for tile in tiles
        }
        
        for future in tqdm(as_completed(future_to_tile), total=total_tiles, desc="Downloading Tiles"):
            success, tile_info, tile_size = future.result()
            actual_tile_size = tile_size  # Track size for stitching
            if success:
                success_count += 1
                metadata.append(tile_info)

    # Save Metadata
    metadata_path = os.path.join(out_dir, "metadata.json")
    with open(metadata_path, "w") as f:
        json.dump(metadata, f, indent=4)

if __name__ == '__main__':
    main()