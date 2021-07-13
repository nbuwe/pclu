/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_save_state		*/
/* null implementation pending gc		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
_save_state(CLUREF fs, CLUREF mode)
{
    CLU_NOREF(fs);
    CLU_NOREF(mode);

    signal(ERR_ok);
}
