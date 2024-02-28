#!/bin/bash
set -x

mkdir -p build
gcc nvrm_gpu_titanian.c -shared -fPIC -o build/libnvrm_gpu_titanian.so
# This is a dirty trick, but in order to get libnvrm_gpu_titanian linked into everything we need to link it into the other libnvrm libraries.
gcc nvrm_host1x.c -shared -Wl,--no-as-needed -lnvrm_graphics -lnvrm_gpu_titanian -L/usr/lib/aarch64-linux-gnu/tegra -Lbuild -rdynamic -o build/libnvrm_host1x.so
gcc nvrm_mem.c -shared -Wl,--no-as-needed -lnvrm -lnvrm_gpu_titanian -L/usr/lib/aarch64-linux-gnu/tegra -Lbuild -rdynamic -o build/libnvrm_mem.so
gcc nvrm_sync.c -shared -Wl,--no-as-needed -lnvrm -lnvrm_gpu_titanian -L/usr/lib/aarch64-linux-gnu/tegra -Lbuild -rdynamic -o build/libnvrm_sync.so