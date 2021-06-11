/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			hash_obj		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * hash_obj = proc (key: _obj, int table_size) returns (int)
 *
 * Hash function for Clu objects for the TABLE cluster.
 */
errcode
hash_obj(CLUREF _obj, CLUREF max, CLUREF *ans)
{
    int temp, temp2;

    if (max.num == 0)
	ans->num = 0;
    else {
	temp = _obj.num / 4;
	temp2 = temp % max.num ;
	ans->num = temp2;
    }

    signal(ERR_ok);
}
