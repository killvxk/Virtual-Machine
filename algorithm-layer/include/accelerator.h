#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include <stdlib.h>
#include <stdarg.h>
#include <linux/kvm.h>

typedef void* (VCPUThread)(void *data);

typedef struct {
    size_t size;
    void *(*ctor)(void *_self, va_list *_params);
    void *(*dtor)(void *_self);
    void (*init)(void *_self);
    void (*createVM)(void *_self, int _ramSize);
    __u64 (*getVMRamBaseaddr)(void *_self);
    void (*initVCPU)(void *_self, int vcpuID, VCPUThread _thread);
    void (*runVM)(void *_self);
} Accelerator;

#endif
