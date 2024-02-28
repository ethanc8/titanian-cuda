#include <inttypes.h>
#include <stdio.h>

typedef struct NvRmGpuDeviceRec NvRmGpuDevice;
typedef enum {
    NvError_Success = 0,
    NvSuccess = NvError_Success,
} NvError;

extern NvError NvRmGpuDeviceGetBufferInfo(NvRmGpuDevice *hDevice) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmGpuDeviceGetBufferInfo");
    fprintf(stderr, "(%p, ...) is not supported\n", hDevice);
    return NvSuccess;
}

extern NvError NvRmGpuDeviceRegisterBuffer(NvRmGpuDevice *hDevice) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmGpuDeviceRegisterBuffer");
    fprintf(stderr, "(%p, ...) is not supported\n", hDevice);
    return NvSuccess;
}

extern NvError NvRmGpuTaskSchedulingGroupGetL2MaxWaysEvictLast(NvRmGpuDevice *hDevice, uint32_t* maxWays) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmGpuTaskSchedulingGroupGetL2MaxWaysEvictLast");
    fprintf(stderr, "(%p, %p) is not supported\n", hDevice, maxWays);
    return NvSuccess;
}

extern NvError NvRmGpuTaskSchedulingGroupSetL2MaxWaysEvictLast(NvRmGpuDevice *hDevice, uint32_t maxWays) {
    fprintf(stderr, "nvrm_gpu_titanian: WARNING: NvRmGpuTaskSchedulingGroupSetL2MaxWaysEvictLast");
    fprintf(stderr, "(%p, %"PRIu32") is not supported\n", hDevice, maxWays);
    return NvSuccess;
}