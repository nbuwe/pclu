/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			quit_			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"
#undef _exit /* _OPexit */

// __attribute__((noreturn))
errcode _OPexit(CLUREF status);


errcode
quit_()
{
    _OPexit(CLU_0);
    /* NOTREACHED */

    /* pacify the compiler */
    return ERR_ok;
}
