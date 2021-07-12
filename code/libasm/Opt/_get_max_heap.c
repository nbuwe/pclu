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
/*
 * Work around a bug in gc-7.x that defines GC_jmp_buf in gc_priv.h
 * instead of declaring it.  Make it work with -fno-common.
 */
#define GC_jmp_buf GC_jmp_buf_libasm__get_max_heap
#include <gc/private/gc_priv.h>

errcode
_get_max_heap(CLUREF *ans)
{
    ans->num = GC_max_heapsize;	/* XXX: private */
    signal(ERR_ok);
}
#endif
