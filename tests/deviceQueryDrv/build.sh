#!/bin/bash
set +x

/usr/local/cuda-10.2/bin/nvcc deviceQueryDrv.cpp -lcuda -I. -o deviceQueryDrv