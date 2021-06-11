/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			hash_int		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdint.h>


errcode
hash_int(CLUREF i, CLUREF max, CLUREF *ans)
{
    if (max.num == 0) {
	ans->num = 0;
    }
    else {
	/*
	 * The C standard specifies symmetric division (truncation
	 * towards zero) that can produce negative remainders with
	 * signed operands, so use unsigned.
	 */
	ans->num = (uintptr_t)i.num % (uintptr_t)max.num;
    }

    signal(ERR_ok);
}
