/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_xjname		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

/* sysasm: util.c */
extern char **argv;


/*
 * Return program name with directory removed
 */
errcode
_get_xjname(CLUREF *ans)
{
    const char *start = strrchr(argv[0], '/');
    if (start)
	++start;
    else
	start = argv[0];

    size_t len = strlen(start);
    stringOPcons(start, CLU_1, CLUREF_make_num(len), ans);
    signal(ERR_ok);
}
