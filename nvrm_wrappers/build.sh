#!/bin/bash

$CC nvrm_gpu_titanian.c -shared -fPIC -o build/nvrm_gpu_titanian.so
$CC nvrm_host1x.c -shared -lnvrm_graphics -fPIC -o build/nvrm_host1x.so
$CC nvrm_mem.c -shared -lnvrm -fPIC -o build/nvrm_mem.so
$CC nvrm_sync.c -shared -lnvrm -fPIC -o build/nvrm_sync.so