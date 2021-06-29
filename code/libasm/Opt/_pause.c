/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_pause			*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"



errcode
_pause(void)
{
    sigset_t empty_mask;
    sigemptyset(&empty_mask);
    sigsuspend(&empty_mask);
    signal(ERR_ok);
}
