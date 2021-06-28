/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_page_size 		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


/*
 * Returns system page size in bytes.
 */
errcode
_page_size(CLUREF *ans)
{
    ans->num = getpagesize();
    signal(ERR_ok);
}
