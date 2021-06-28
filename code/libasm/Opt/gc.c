/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			gc			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"
#undef gc

#include <stdio.h>

/* XXX: stubs in sysasm unimp.c */
errcode _gcOPgc(void);
extern int heaplo;


/*
 * Returns number of (long) words reclaimed.
 */
errcode
gc(CLUREF *ans)
{
    int old_heaplo;

    fprintf(stderr, "gc$gc returning wrong value\n");

    old_heaplo = heaplo;
    _gcOPgc();

    ans->num = (heaplo - old_heaplo) / 4;
    signal(ERR_ok);
}
