#!/bin/bash
set -x

mkdir -p build/cuda-11.4/lib
wget https://repo.download.nvidia.com/jetson/t194/pool/main/n/nvidia-l4t-cuda/nvidia-l4t-cuda_34.1.1-20220516211757_arm64.deb
dpkg-deb --raw-extract nvidia-l4t-cuda_34.1.1-20220516211757_arm64.deb build/nvidia-l4t-cuda
wget https://repo.download.nvidia.com/jetson/t194/pool/main/n/nvidia-l4t-3d-core/nvidia-l4t-3d-core_34.1.1-20220516211757_arm64.deb
dpkg-deb --raw-extract nvidia-l4t-3d-core_34.1.1-20220516211757_arm64.deb build/nvidia-l4t-3d-core
wget https://repo.download.nvidia.com/jetson/t194/pool/main/n/nvidia-l4t-core/nvidia-l4t-core_34.1.1-20220516211757_arm64.deb
dpkg-deb --raw-extract nvidia-l4t-core_34.1.1-20220516211757_arm64.deb build/nvidia-l4t-core
cp build/nvidia-l4t-cuda/usr/lib/aarch64-linux-gnu/tegra/* build/cuda-11.4/lib
# cp build/nvidia-l4t-core/usr/lib/aarch64-linux-gnu/tegra/libnvrm* build/cuda-11.4/lib
rm build/cuda-11.4/lib/libcuda.so
ln -s libcuda.so.1.1 build/cuda-11.4/lib/libcuda.so
ln -s libcuda.so.1.1 build/cuda-11.4/lib/libcuda.so.1
cd nvrm_wrappers
./build.sh
cd ..
cp nvrm_wrappers/build/* build/cuda-11.4/lib
echo "Ready! Run"
echo "  export LD_LIBRARY_PATH=\"$(realpath build/cuda-11.4/lib):\$LD_LIBRARY_PATH\""
echo "to get started."