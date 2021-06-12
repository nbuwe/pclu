/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*	   	   unix_cmd			*/
/*						*/

#include <sys/wait.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdlib.h>

extern errcode intOPunparse(CLUREF i, CLUREF *ans);
extern errcode stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans);
extern errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


errcode
unix_cmd(CLUREF input)
{
    errcode err;

    int result = system((char *)input.vec->data);
#if 0
    printf("err = %X, %X %X %X\n", result, WTERMSIG(result),
	   WEXITSTATUS(result), WSTOPSIG(result));
#endif
    if (result == 0)
	signal(ERR_ok);


    CLUREF msg;
    err = stringOPcons("call to system failed: ", CLU_1, CLU_23, &msg);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF numstr;
    err = intOPunparse(CLUREF_make_num(result) , &numstr);
    if (err != ERR_ok)
	goto ex_0;

    err = stringOPconcat(msg, numstr, &msg);
    if (err != ERR_ok)
	goto ex_0;

    elist[0] = msg;
    signal(ERR_failure);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
