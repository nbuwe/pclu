/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			get_argv		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode sequenceOPnew(CLUREF *ans);

/* sysasm: util.c */
extern int argc;
extern char **argv;

/* sysasm: _chan.c - debugger fd? */
extern long wrpipe;

static CLUREF save_argv;


errcode
get_argv(CLUREF *ans)
{
    errcode err;

    if (save_argv.vec != NULL) {
	*ans = save_argv;
	signal(ERR_ok);
    }

    if (wrpipe != 0 || argc <= 1) {
	err = sequenceOPnew(&save_argv);
	if (err != ERR_ok)
	    goto ex_0;

	*ans = save_argv;
	signal(ERR_ok);
    }


    CLUREF seq;
    err = sequenceOPnew2(CLUREF_make_num(argc - 1), &seq);
    if (err != ERR_ok)
	goto ex_0;

    for (int i = 1; i < argc; ++i) {
	size_t len = strlen(argv[i]);

	CLUREF arg;
	stringOPcons(argv[i], CLU_1, CLUREF_make_num(len), &arg);
	seq.vec->data[i - 1] = arg.num;
    }

    save_argv = seq;
    *ans = save_argv;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}


/*
 * set_argv() modifies the static variable used by get_argv() to hold
 * the CLU sequence of strings corresponding to argv.  The C global
 * variable "argv", is not affected.  new 9/10/92 dwc
 */
errcode
set_argv(CLUREF args)
{
    save_argv = args;
    signal(ERR_ok);
}
