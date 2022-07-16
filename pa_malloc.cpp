
#include "config.h"
#include "PartitionAlloc.h"
//#include <malloc.h>

static WTF::PartitionAllocatorGeneric pa;
static bool pa_inited;

static void ensure_inited() {
    if (!pa_inited) {
        pa.init();
        pa_inited = true;
    }
}

extern "C" {
    //void* malloc_hook(size_t size, const void* _caller) {
    void* malloc(size_t size) {
        ensure_inited();
        return WTF::partitionAllocGeneric(pa.root(), size);
    }

    void* realloc(void* alloc, size_t size) {
        ensure_inited();
        return WTF::partitionReallocGeneric(pa.root(), alloc, size);
    }

    void free(void* alloc) {
        WTF::partitionFreeGeneric(pa.root(), alloc);
    }

    void aligned_alloc(size_t alignment, size_t size) {
        return WTF::partitionAlignedAlloc(pa.root(), alignment, size);
    }
}

/*
// force initialization before main
struct Initer {
    Initer() {
        ensure_inited();
        __malloc_hook = malloc_hook;
        __free_hook = free_hook;
        __realloc_hook = realloc_hook;
    }
};

static Initer _initer;
*/

