/* Copyright Massachusetts Institute of Technology 1993 */

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * Returns the size, in bytes, of pointers and ints,
 * i.e., the size of a machine word.
 */
errcode
_cluref_size(CLUREF *ans)
{
    ans->num = CLUREFSZ;
    signal(ERR_ok);
}
