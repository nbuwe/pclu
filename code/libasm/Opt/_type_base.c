/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION _type_base	*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * Returns base of type ids.
 *
 * uwe: Probably obsolete.
 */
errcode
_type_base(CLUREF *ans)
{
    ans->num = 020000;
    signal(ERR_ok);
}
