/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*		   type				*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
typeOPequal(CLUREF t1, CLUREF t2, CLUREF *ans)
{
    if (t1.num == t2.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
typeOPsimilar(CLUREF t1, CLUREF t2, CLUREF *ans)
{
    if (t1.num == t2.num)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
typeOPcopy(CLUREF t, CLUREF *ans)
{
    ans->num = t.num;
    signal(ERR_ok);
}
