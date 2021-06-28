/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_dtable_size 		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


errcode
_dtable_size(CLUREF *ans)
{
    ans->num = getdtablesize();
    signal(ERR_ok);
}
