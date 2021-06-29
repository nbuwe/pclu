/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			pause			*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"


/*
 * This is not speced as a clu proc and CHANGES mention intentionally
 * changing its return type to int.  Doesn't seem to be used anywhere,
 * so just keep it as it is.
 */
int /* sic */
pause(void)
{
    sigset_t empty_mask;
    sigemptyset(&empty_mask);
    sigsuspend(&empty_mask);
    signal(ERR_ok);
}
