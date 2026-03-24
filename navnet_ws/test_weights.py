import os
from ament_index_python.packages import get_package_share_directory

try:
    # Get the actual package name from the first directory in install
    import glob
    installed_dirs = glob.glob('/workspace/install/*/share/*/')
    if installed_dirs:
        pkg_name = os.path.basename(installed_dirs[0].rstrip('/'))
        print(f"Found package: {pkg_name}")
        
        pkg_dir = get_package_share_directory(pkg_name)  
        weights_dir = os.path.join(pkg_dir, 'weights')  
        print(f"Package dir: {pkg_dir}")
        print(f"Weights dir: {weights_dir}")
        print(f"Exists: {os.path.exists(weights_dir)}")
        if os.path.exists(weights_dir):
            print(f"Contents: {os.listdir(weights_dir)}")
except Exception as e:
    import traceback
    print(f"Error: {e}")
    traceback.print_exc()
