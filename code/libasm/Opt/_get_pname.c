/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_pname		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

/* sysasm: util.c */
extern char **argv;


/*
 * Return program name with directory, if any.
 */
errcode
_get_pname(CLUREF *ans)
{
    size_t len = strlen(argv[0]);
    stringOPcons(argv[0], CLU_1, CLUREF_make_num(len), ans);
    signal(ERR_ok);
}
