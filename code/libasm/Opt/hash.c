/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			hash			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * hash = proc (s: string, table_size: int) returns (int)
 *
 *   A hashing function for strings.
 */
errcode
hash(CLUREF s, CLUREF table_size, CLUREF *ans)
{
    int j, sum, temp;

    if (s.str->size == 0) {
	ans->num = 0;
	signal(ERR_ok);
    }

    /*
     * this algorithm is a little strange:
     * each character is added in twice
     * and a byte past the end of the string may be added in as well
     */
    sum = 0;
    for (j = 0; j < s.str->size; j++, j++) {
	temp = s.str->data[j];
	sum += temp << 16;
	sum += s.str->data[j+1];
    }

    if (table_size.num == 0) {
	ans->num = 0;
    }
    else {
	if (sum < 0)
	    sum = -sum;
	ans->num = sum % table_size.num;
    }

    signal(ERR_ok);
}
