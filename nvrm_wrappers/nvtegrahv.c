#include "nvtegrahv.h"

int NvHvCheckOsNative(void) {
    return Os_Non_Native;
}

int NvHvGetOsVmId(unsigned int *vmid) {
    return 1;
}

int NvHvGetSysinfoAddr(uint64_t *addr) {
    return 1;
}