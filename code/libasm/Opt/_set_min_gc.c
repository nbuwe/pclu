/* Copyright Massachusetts Institute of Technology 1993 */

#include "pclu_err.h"
#include "pclu_sys.h"

#ifndef LINUX
extern int blks_min_gc;

errcode
_set_min_gc(CLUREF n)
{
    if (n.num > (blks_hard_limit * HBLKSIZE))
	signal(ERR_toobig);
    if (n.num < 0)
	signal(ERR_negative_size);

    blks_min_gc = divHBLKSZ(n.num);
    signal(ERR_ok);
}
#endif	/* !LINUX */

/* This code lives in the gc directory for LINUX */
