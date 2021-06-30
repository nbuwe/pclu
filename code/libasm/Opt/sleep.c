/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			sleep			*/
/*						*/

#include <sys/time.h>
#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

void sleep_alarm(int);


unsigned int
sleep(unsigned int isecs)
{
    int uerr;
    int omask, omask2;
    struct sigaction vec;
    int which;
    struct itimerval value;
    CLUREF secs;

    secs.num = isecs;
    if (secs.num == 0)
	signal(ERR_ok);

    vec.sa_handler = sleep_alarm;
    sigfillset(&vec.sa_mask);
    vec.sa_flags = true;

    uerr = sigaction(SIGALRM, &vec, NULL);

    omask = sigblock(sigmask(SIGALRM));
    which = ITIMER_REAL;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = secs.num;
    value.it_value.tv_usec = 0;
    uerr = setitimer(which, &value, NULL);
    if (uerr != 0)
	signal(ERR_ok);

    omask2 = sigpause(omask);

    sigsetmask(omask);
    value.it_value.tv_sec = 0;
    // value.it_value.tv_usec = 0;
    setitimer(which, &value, NULL);
    signal(ERR_ok);
}


void
sleep_alarm(int sig)
{
    CLU_NOREF(sig);
    return;
}
