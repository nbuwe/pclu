/* Copyright Massachusetts Institute of Technology 1993 */

#include "pclu_err.h"
#include "pclu_sys.h"

#ifndef LINUX

errcode
_get_max_heap(CLUREF *ans)
{
    ans->num = blks_hard_limit * HBLKSIZE;
    signal(ERR_ok);
}

#else  /* LINUX */

#include <gc/gc.h>

errcode
_get_max_heap(CLUREF *ans)
{
    /*
     * In gc 7.2 and before - you can peek at private GC_max_heapsize,
     * but it is zero when the heap is not limited.  Use public API
     * instead to estimate it.  I'm pretty certain this CLU API is
     * provided effectively FYI only, so the exact number is not that
     * important.  Technically, we can just signal not_applicable :)
     *
     * We use the unsynchronized version of the public API since we
     * have no threads.
     *
     * Also note that this returns the number of bytes, unlike
     * _free_space that returns the number machine words.
     */
    size_t estimate
        = GC_get_heap_size()        /* allocations + overhead */
        + GC_get_free_bytes()       /* mapped and available for allocation */
        + GC_get_unmapped_bytes();  /* returned to OS, can be mapped back */

    ans->num = estimate;
    signal(ERR_ok);
}
#endif
