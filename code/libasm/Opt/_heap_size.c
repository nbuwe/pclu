/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_heap_size		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#ifdef LINUX
#include <gc/private/gc_priv.h>
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
/*  ans->num = (heaphi - heaplo) / 4; */
#ifdef LINUX
    ans->num = GC_composite_in_use;
#else
    ans->num = composite_in_use;
#endif
    signal(ERR_ok);
}
