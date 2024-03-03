#!/bin/bash
set -x

/usr/local/cuda-10.2/bin/nvcc cuDarkViewer.cpp -lcuda -I. -o cuDarkViewer