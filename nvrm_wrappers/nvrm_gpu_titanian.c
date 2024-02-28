#include <inttypes.h>
#include <stdio.h>

typedef struct NvRmGpuDeviceRec NvRmGpuDevice;
typedef enum {
    NvError_Success = 0,
    NvSuccess = NvError_Success,
} NvError;

extern NvError NvRmGpuTaskSchedulingGroupSetL2MaxWaysEvictLast(NvRmGpuDevice *hDevice, uint32_t maxWays) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmGpuTaskSchedulingGroupSetL2MaxWaysEvictLast");
    fprintf(stderr, "(%p, %"PRIu32") is not supported\n", hDevice, maxWays);
    return NvSuccess;
}