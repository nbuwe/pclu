/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_event			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

int defer;


/*
 * Defer quit interrupt, stop array-trimming during G/C.
 * Must be paired with undefer() call!
 */
errcode
_eventOPdefer(void)
{
    ++defer;
    signal(ERR_ok);
}


/*
 * Allow quit interrupt, allow array-trimming during G/C.
 * Must be paired with defer call!
 */
errcode
_eventOPundefer(void)
{
    --defer;
    signal(ERR_ok);
}
