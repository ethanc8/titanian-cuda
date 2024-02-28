#include <inttypes.h>
#include <stdio.h>

typedef enum {
    NvError_Success = 0,
    NvSuccess = NvError_Success,
} NvError;

extern NvError NvRmMemQueryHeapManager(void *thingy) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmMemQueryHeapManager");
    fprintf(stderr, "(%p, ...) is not supported\n", thingy);
    return NvSuccess;
}