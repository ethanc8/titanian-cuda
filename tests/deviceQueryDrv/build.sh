#!/bin/bash
set -x

/usr/local/cuda-10.2/bin/nvcc deviceQueryDrv.cpp -lcuda -I. -L/home/titan/Projects/titanian-cuda/build/cuda-11.4/lib -o deviceQueryDrv