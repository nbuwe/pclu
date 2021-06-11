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
 * hash_obj = proc (key: _obj, int table_size) returns (int)
 *
 * Hash function for Clu objects for the TABLE cluster.
 */
errcode
hash_obj(CLUREF _obj, CLUREF max, CLUREF *ans)
{
    if (max.num == 0) {
	ans->num = 0;
    }
    else {
	uintptr_t ptrbits = (uintptr_t)_obj.ref / CLUREFSZ;
	ans->num = ptrbits % max.num;
    }

    signal(ERR_ok);
}
