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
    (void) fs;
    signal(ERR_ok);
}


errcode
_gprofOPcontrol(CLUREF flag)
{
    (void) flag;
    signal(ERR_ok);
}
