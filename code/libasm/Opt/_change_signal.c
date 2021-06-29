/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_change_signal		*/
/*						*/

#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>


errcode
_change_signal(CLUREF sig, CLUREF label, CLUREF *ans)
{
    int status;

    struct sigaction vec;
    vec.sa_handler = (void (*)(int))label.num;
    vec.sa_flags = 1;

    sigemptyset(&vec.sa_mask);
    sigaddset(&vec.sa_mask, SIGABRT);
#ifdef SIGEMT
    sigaddset(&vec.sa_mask, SIGEMT);
#endif
    sigaddset(&vec.sa_mask, SIGFPE);
    sigaddset(&vec.sa_mask, SIGPIPE);
    sigaddset(&vec.sa_mask, SIGALRM);
    sigaddset(&vec.sa_mask, SIGTERM);
    sigaddset(&vec.sa_mask, SIGURG);
    sigaddset(&vec.sa_mask, SIGSTOP);
    sigaddset(&vec.sa_mask, SIGTSTP);
    sigaddset(&vec.sa_mask, SIGCHLD);
    sigaddset(&vec.sa_mask, SIGTTIN);
    sigaddset(&vec.sa_mask, SIGTTOU);
    sigaddset(&vec.sa_mask, SIGIO);
    sigaddset(&vec.sa_mask, SIGXFSZ);
    sigaddset(&vec.sa_mask, SIGVTALRM);
    sigaddset(&vec.sa_mask, SIGPROF);
    sigaddset(&vec.sa_mask, SIGWINCH);
#ifdef SIGINFO
    sigaddset(&vec.sa_mask, SIGINFO);
#endif
    sigaddset(&vec.sa_mask, SIGUSR1);
    sigaddset(&vec.sa_mask, SIGUSR2);

    struct sigaction ovec;
    status = sigaction(sig.num, &vec, &ovec);
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = (long)ovec.sa_handler;
    signal(ERR_ok);
}
