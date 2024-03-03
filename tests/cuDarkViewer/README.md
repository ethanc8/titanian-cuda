# `cuDarkViewer`

This utility prints the addresses of the functions in the CUDA Dark API, plus the function names if [ZLUDA](https://github.com/vosen/ZLUDA/blob/master/zluda_dark_api/src/lib.rs#L197) defines them. These addresses likely differ between versions of `libcuda.so`, and are not exported as symbols, so the lookup tables returned by `cuGetExportTable` are the only way to get these functions. This utility also functions as an example of how to actually read these lookup tables.

## TODO

* [x] Incorporate [data from ZLUDA](https://github.com/vosen/ZLUDA/blob/master/zluda_dark_api/src/lib.rs#L197) 
* [x] Incorporate [data from THAPI](https://github.com/argonne-lcf/THAPI/blob/a5ac1cf6741cc9a1cc1fe17ba34d0fdecfeb8d73/cuda/cuda_export_tables.yaml#L82)
* [ ] Create DWARF debugging data