#!/bin/bash
set -x

mkdir -p build
gcc nvrm_gpu_titanian.c -shared -fPIC -o build/libnvrm_gpu_titanian.so
gcc nvrm_host1x.c -shared -Wl,--no-as-needed -lnvrm_graphics -L/usr/lib/aarch64-linux-gnu/tegra -rdynamic -o build/libnvrm_host1x.so
gcc nvrm_mem.c -shared -Wl,--no-as-needed -lnvrm -L/usr/lib/aarch64-linux-gnu/tegra -rdynamic -o build/libnvrm_mem.so
gcc nvrm_sync.c -shared -Wl,--no-as-needed -lnvrm -L/usr/lib/aarch64-linux-gnu/tegra -rdynamic -o build/libnvrm_sync.so