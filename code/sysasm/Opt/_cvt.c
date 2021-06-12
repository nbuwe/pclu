/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*					*/
/*		_CVT			*/
/*					*/

#include "pclu_err.h"
#include "pclu_sys.h"


/* Don't care about FROM */
static const struct /* REQS */ {
    long count;
} _cvt_of_from_reqs_actual = { 0 };

const struct REQS * const _cvt_of_from_reqs
    = (const struct REQS *)&_cvt_of_from_reqs_actual;


/* Don't care about TO */
static const struct /* REQS */ {
    long count;
} _cvt_of_to_reqs_actual = { 0 };

const struct REQS * const _cvt_of_to_reqs
    = (const struct REQS *)&_cvt_of_to_reqs_actual;


/* No owns */
const OWN_req _cvt_ownreqs = { 0, 0 };

OWN_ptr _cvt_own_init; /* dummy */


/*
 * _cvt = proc [from, to: type] (x: from) returns (to)
 *
 * It's a cast and the real work happens in the type-checker.
 * Optimizer just inlines _cvt() as direct assignment.
 */
errcode
_cvt(CLUREF obj, CLUREF *ans)
{
    *ans = obj;
    signal(ERR_ok);
}
