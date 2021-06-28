/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			get_env			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

/* sysasm: util.c */
extern char **environ;

/* sysasm: _chan.c - debugger fd? */
extern int wrpipe;

static CLUREF save_env;


/*
 * get_env = proc () returns (sequence[string])
 *
 * This doesn't seem to be actually declared in any spec file.
 * See also _environ and _environs in sysasm (etc.spc).
 */
errcode
get_env(CLUREF *ans)
{
    errcode err;

    if (save_env.vec != NULL) {
	*ans = save_env;
	signal(ERR_ok);
    }

    if (wrpipe != 0 || environ[0] == NULL) {
	err = sequenceOPnew(&save_env);
	if (err != ERR_ok)
	    goto ex_0;

	*ans = save_env;
	signal(ERR_ok);
    }

    /* find number of strings in environ */
    size_t size = 0;
    for (size_t i = 0; environ[i] != NULL; ++i)
	++size;

    CLUREF seq;
    err = sequenceOPnew2(CLUREF_make_num(size), &seq);
    if (err != ERR_ok)
	goto ex_0;

    for (size_t i = 0; environ[i] != NULL; ++i) {
	size_t len = strlen(environ[i]);

	CLUREF e;
	stringOPcons(environ[i], CLU_1, CLUREF_make_num(len), &e);
	seq.vec->data[i] = e.num;
    }

    save_env = seq;
    *ans = save_env;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
