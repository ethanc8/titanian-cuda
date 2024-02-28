#!/bin/bash

mkdir -p build
$CC nvrm_gpu_titanian.c -shared -fPIC -o build/nvrm_gpu_titanian.so
$CC nvrm_host1x.c -shared -lnvrm_graphics -L/usr/lib/aarch64-linux-gnu/tegra -fPIC -o build/nvrm_host1x.so
$CC nvrm_mem.c -shared -lnvrm -fPIC -L/usr/lib/aarch64-linux-gnu/tegra -o build/nvrm_mem.so
$CC nvrm_sync.c -shared -lnvrm -fPIC -L/usr/lib/aarch64-linux-gnu/tegra -o build/nvrm_sync.so