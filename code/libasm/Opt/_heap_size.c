/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_heap_size		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#ifdef LINUX
#include <gc/gc.h>
#else
extern int composite_in_use;
#endif


/*
 * Current size of heap in (long) words.
 *
 * For PCLU, returns the number of machine words of allocated objects,
 * which is generally smaller than "max_heap".
 */
errcode
_heap_size(CLUREF *ans)
{
#ifdef LINUX
    /*
     * This code used to peek at gc-7.2 internals.  The other "heap
     * size" fumction is _get_active_heap that also peeked at the gc
     * internals and returned GC_composite_in_use + GC_atomic_in_use.
     * There was probably some reason for that. (Also note that this
     * function returns words, and the other one returns bytes).
     */
#if 0
    ans->num = GC_composite_in_use; / sizeof(long);
#endif
    ans->num = GC_get_heap_size() / sizeof(long);
#else
/*  ans->num = (heaphi - heaplo) / 4; */
    ans->num = composite_in_use;
#endif
    signal(ERR_ok);
}
