/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			type_of			*/
/*						*/
/*		returns the type field of an any*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
type_of(CLUREF a, CLUREF *ans)
{
    ans->num = a.cell->tag;	/* cf. _anyize() */
    signal(ERR_ok);
}
