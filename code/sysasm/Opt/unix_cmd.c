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
    int result;
    CLUREF temp_str, n, num, size;
    errcode err;

    result = system((char *)input.vec->data);
#if 0
    printf("err = %X, %X %X %X\n", result, WTERMSIG(result),
	   WEXITSTATUS(result), WSTOPSIG(result));
#endif
    if (result == 0)
	signal(ERR_ok);

    err = stringOPcons("call to system failed: ", CLU_1, CLU_23, &temp_str);
    n.num = (long)result;
    err = intOPunparse(n, &num);
    err = stringOPconcat(temp_str, num, &temp_str);
    elist[0] = temp_str;
    signal(ERR_failure);
}
