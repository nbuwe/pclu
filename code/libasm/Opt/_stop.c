/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_stop			*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>



errcode
_stop(void)
{
    kill(getpid(), SIGSTOP);
    signal(ERR_ok);
}
