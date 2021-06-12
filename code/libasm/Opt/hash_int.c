/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			hash_int		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdint.h>


/*
 * hash_int = proc (i: int, table_size: int) returns (int)
 *
 *   A hashing function for integers.
 */
errcode
hash_int(CLUREF i, CLUREF table_size, CLUREF *ans)
{
    if (table_size.num == 0) {
	ans->num = 0;
    }
    else {
	/*
	 * The C standard specifies symmetric division (truncation
	 * towards zero) that can produce negative remainders with
	 * signed operands, so use unsigned.
	 */
	ans->num = (uintptr_t)i.num % (uintptr_t)table_size.num;
    }

    signal(ERR_ok);
}
