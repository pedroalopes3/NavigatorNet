import os
from glob import glob

from setuptools import find_packages, setup

package_name = "navnet"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.py")),
        (os.path.join('share', package_name, 'params'), glob('params/*.yaml')),
    ],
    package_data={
        "navnet.models": ["weights/*.pth"],
    },
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="root",
    maintainer_email="pedroafdlopes@tecnico.ulisboa.pt",
    description="TODO: Package description",
    license="TODO: License declaration",
    extras_require={
        "test": [
            "pytest",
        ],
    },
    entry_points={
        "console_scripts": ["navnet_node = navnet.main:main"],
    },
)
