/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_restore_state		*/
/* null implementation pending gc		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
_restore_state(CLUREF fs, CLUREF *ans)
{
    CLU_NOREF(fs);

    ans->tf = false;
    signal(ERR_ok);
}
