/* Copyright Massachusetts Institute of Technology 1993 */

#include "pclu_err.h"
#include "pclu_sys.h"

#ifndef LINUX

errcode
_get_active_heap(CLUREF *ans)
{
    ans->num = blks_active * HBLKSIZE;
    signal(ERR_ok);
}

#else  /* LINUX */

#include <gc/gc.h>

errcode
_get_active_heap(CLUREF *ans)
{
    /*
     * This code used to peek at gc-7.2 internals.  The other "heap
     * size" fumction is _heap_size that also peeked at the gc
     * internals and returned just the GC_composite_in_use.  There was
     * probably some reason for that. (Also note that this function
     * returns bytes, and the other one returns words).
     */
#if 0
    ans->num = GC_composite_in_use + GC_atomic_in_use;
#endif
    ans->num = GC_get_heap_size();
    signal(ERR_ok);
}

#endif
