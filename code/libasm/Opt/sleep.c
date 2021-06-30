/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			sleep			*/
/*						*/

#include <sys/time.h>
#include <signal.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

errcode _sleep(CLUREF millis);


/*
 * Forward to _sleep() to avoid code duplication, it differs only in
 * the units of the argument and was exactly the same code otherwise.
 *
 * FIXME: This function overrides sleep(3) from libc.
 *
 * It's probably better to fix up the clu name to avoid the name clash
 * as the compiler already does for C keywords.
 *
 * This code could almost dodge this problem b/c 3rd party C code
 * calling sleep(3) and clu code calling sleep() are ABI compatible if
 * small structs are passed unboxed.  But the problem is that the libc
 * version and clu version have different return values, so this pun
 * never fully worked as expected for the non-default case (if sleep
 * was interrupted).
 */
unsigned int
sleep(unsigned int secs)
{
    return _sleep(CLUREF_make_num(secs * 1000));
}
