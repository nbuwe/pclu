/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/* 	null	IMPLEMENTATION OF		*/
/*			gprof			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
_gprofOPinit(void)
{
    signal(ERR_ok);
}


errcode
_gprofOPdump(CLUREF fs)
{
    CLU_NOREF(fs);
    signal(ERR_ok);
}


errcode
_gprofOPcontrol(CLUREF flag)
{
    CLU_NOREF(flag);
    signal(ERR_ok);
}
