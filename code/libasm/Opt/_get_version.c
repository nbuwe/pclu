/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_get_version		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

/* Fallback definition for "version" is provided in version.c */
extern int version;


/*
 * Return program version number (set by #version option of LINK).
 *
 * uwe: As far as I can tell this is not supported by PCLU.
 * E.g. the compiler itself manually supplies "version" in cmpasm.
 */
errcode
_get_version(CLUREF *ans)
{
    ans->num = version;
    signal(ERR_ok);
}
