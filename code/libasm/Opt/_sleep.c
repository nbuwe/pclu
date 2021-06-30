/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_sleep			*/
/*						*/

#include <sys/time.h>
#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

void _sleep_alarm(int);


errcode
_sleep(CLUREF millis)
{
    int uerr;
    int omask, omask2;
    struct sigaction vec;
    int which;
    struct itimerval value;

    if (millis.num == 0)
	signal(ERR_ok);

    vec.sa_handler = _sleep_alarm;
    /* vec.sa_mask = -1; */
    sigfillset(&vec.sa_mask);
    vec.sa_flags = true;

    uerr = sigaction(SIGALRM, &vec, NULL);

    omask = sigblock(sigmask(SIGALRM));
    which = ITIMER_REAL;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = millis.num / 1000;
    value.it_value.tv_usec = millis.num % 1000;
    uerr = setitimer(which, &value, NULL);
    if (uerr != 0)
	signal(ERR_ok);

    omask2 = sigpause(omask);

    sigsetmask(omask);
    value.it_value.tv_sec = 0;
    value.it_value.tv_usec = 0;
    setitimer(which, &value, NULL);
    signal(ERR_ok);
}


void
_sleep_alarm(int sig)
{
    CLU_NOREF(sig);
    return;
}
