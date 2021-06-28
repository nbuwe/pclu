/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			get_jcl			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode stringOPcons0(CLUREF len, CLUREF *ans);

/* sysasm: util.c */
extern int argc;
extern char **argv;


/*
 * Returns command line, not including program name, as a single string.
 * See also get_argv().
 */
errcode
get_jcl(CLUREF *ans)
{
    static CLUREF jcl;
    static bool done = 0;
    if (done) {
	*ans = jcl;
	signal(ERR_ok);
    }

    done = true;

    if (argc <= 1) {
	jcl = CLU_empty_string;

	*ans = jcl;
	signal(ERR_ok);
    }

    size_t size = 0;
    for (int i = 1; i < argc; ++i)
	size += strlen(argv[i]) + 1; /* for space or NUL */

    stringOPcons0(CLUREF_make_num(size), &jcl);

    char *dst = jcl.str->data;
    for (int i = 1; i < argc; ++i) {
	if (i != 1)
	    *dst++ = ' ';
	for (const char *src = argv[i]; *src != '\0'; ++src, ++dst)
	    *dst = *src;
    }

    *ans = jcl;
    signal(ERR_ok);
}
