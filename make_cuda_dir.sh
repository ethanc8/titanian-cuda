#!/bin/bash
set -x

mkdir -p build/cuda-11.4/lib
wget https://repo.download.nvidia.com/jetson/t194/pool/main/n/nvidia-l4t-cuda/nvidia-l4t-cuda_34.1.1-20220516211757_arm64.deb
dpkg-deb --raw-extract nvidia-l4t-cuda_34.1.1-20220516211757_arm64.deb build/nvidia-l4t-cuda
cp build/nvidia-l4t-cuda/usr/lib/aarch64-linux-gnu/tegra/* build/cuda-11.4/lib
cd nvrm_wrappers
./build.sh
cd ..
cp nvrm_wrappers/build/* build/cuda-11.4/lib
echo "Ready! Run"
echo "  export LD_LIBRARY_PATH=\"$(realpath build/cuda-11.4/lib):\$LD_LIBRARY_PATH\""
echo "to get started."