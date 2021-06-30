/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			pause			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

errcode _pause(void);


/*
 * Forward to _pause() which has exact same code this implementation
 * used to have.
 *
 * FIXME: This function overrides pause(3) from libc.
 *
 * It's probably better to fix up the clu name to avoid the name clash
 * as the compiler already does for C keywords.
 *
 * This code could dodge this problem b/c 3rd party C code calling
 * pause(3) and clu code calling pause() are ABI compatible.  Note
 * that pause(3) always returns -1 and sets EINTR, but no normal C
 * code would ever depend on that.
 */
int
pause(void)
{
    return _pause();
}
