/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*							*/
/*		IMPLEMENTATION OF			*/
/*			_free_space			*/
/*							*/
/*		returns the number of machine words	*/
/*		that remain available for future	*/
/*		allocations from the heap		*/

#include "pclu_err.h"
#include "pclu_sys.h"

#ifndef LINUX
extern int maxheapsize;
extern int composite_in_use;

errcode
_free_space(CLUREF *ans)
{
    ans->num = blks_hard_limit * BYTES_TO_WORDS(HBLKSIZE) - composite_in_use;
    signal(ERR_ok);
}

#else  /* LINUX */

#include <gc/private/gc_priv.h>

errcode
_free_space(CLUREF *ans)
{
    /* XXX: GC_max_heapsize is zero when unlimited */
    ans->num = BYTES_TO_WORDS(GC_max_heapsize
			      - GC_atomic_in_use
			      - GC_composite_in_use);
    signal(ERR_ok);
}
#endif
