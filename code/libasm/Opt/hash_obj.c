/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			hash_obj		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdint.h>


/*
 * hash_obj = proc (o: _obj, table_size: int) returns (int)
 *
 *     A hashing function for objects.
 */
errcode
hash_obj(CLUREF o, CLUREF table_size, CLUREF *ans)
{
    if (table_size.num == 0) {
	ans->num = 0;
    }
    else {
	uintptr_t ptrbits = (uintptr_t)o.ref / CLUREFSZ;
	ans->num = ptrbits % table_size.num;
    }

    signal(ERR_ok);
}
