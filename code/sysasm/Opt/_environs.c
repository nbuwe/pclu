/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*							*/
/*		IMPLEMENTATION OF			*/
/*			_environs			*/
/*	an iterator that yields the environment strings */
/*							*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <string.h>

/* iterator body callback */
typedef errcode (*iter_body_t)(CLUREF iv_1, void *locals, errcode *iecode);

errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);

/* set by the C startup code in util.c */
extern char **envp;


/*
 * _environs = iter () yields (string)
 */
errcode
_environs(iter_body_t ib, void *locals, errcode *iecode)
{
    CLUREF iv_1;
    errcode err;

    if (envp == NULL || envp[0] == NULL)
	signal(ERR_ok);

    for (size_t i = 0; envp[i] != NULL; ++i) {
	size_t len = strlen(envp[i]);
	err = stringOPcons(envp[i], CLU_1, CLUREF_make_num(len), &iv_1);
	if (err != ERR_ok)
	    resignal(err);

	err = (*ib)(iv_1, locals, iecode);
	if (err == ERR_ok)
	    continue;

	/* 9/9/93 dwc: just propagate break, do not convert to ok */
	if (err == ERR_break) signal(err);
	if (err == ERR_iterbodyexit) signal(err);
	if (err == ERR_iterbodysignal) signal(err);
	if (err == ERR_iterbodyreturn) signal(err);
	if (err == ERR_iteriterbodyexit) signal(err);
	if (err == ERR_iteriterbodysignal) signal(err);
	if (err == ERR_iteriterbodyreturn) signal(err);
    }

    signal(ERR_ok);
}
