#!/bin/bash

clang nvrm_gpu_titanian.c -shared -fPIC -o build/nvrm_gpu_titanian.so
clang nvrm_host1x.c -shared -lnvrm_graphics -fPIC -o build/nvrm_host1x.so
clang nvrm_mem.c -shared -lnvrm -fPIC -o build/nvrm_mem.so
clang nvrm_sync.c -shared -lnvrm -fPIC -o build/nvrm_sync.so