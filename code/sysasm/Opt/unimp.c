/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*	SOME UNIMPLEMENTED STUBS		*/
/*						*/

#include <stdio.h>
#include "pclu_err.h"
#include "pclu_sys.h"

#ifndef LINUX
extern int gccount;
#else
#include <gc/gc.h>
#define gccount (GC_get_gc_no())
#endif

long heaplo = 0xdead;
long heaphi = 0xffff;
long freelm = 0x0042;


errcode
_gcOPgc(void)
{
    dmd_gc();
    signal(ERR_ok);
}


#if 0
errcode
_gcOPcontrol(CLUREF add, CLUREF mask)
{
    errcode err;

    err = gcOPcontrol(add, mask);
    resignal(err);
}
#endif	/* 0 */


errcode
_gcOPcount(CLUREF *ans)
{
    ans->num = gccount;
    signal(ERR_ok);
}


errcode
_rtn_infoOPis_proc(CLUREF s, CLUREF *ans)
{
    CLU_NOREF(s);

    ans->tf = true;
    signal(ERR_ok);
}


errcode
_rtn_infoOPis_iter(CLUREF s, CLUREF *ans)
{
    CLU_NOREF(s);

    ans->tf = true;
    signal(ERR_ok);
}


errcode
_objOPis_uninit(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);
    CLU_NOREF(ans);

    fprintf(stderr, "_obj$is_uninit not implemented\n");
    signal(ERR_failure);
}


errcode
atan4900(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);
    CLU_NOREF(ans);

    fprintf(stderr, "atan4900 not implemented\n");
    signal(ERR_failure);
}


errcode
_objOPis_routine(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);
    CLU_NOREF(ans);

    fprintf(stderr, "_obj$is_routine not implemented\n");
    signal(ERR_failure);
}


errcode
structOPcreate(CLUREF x, CLUREF *ans)
{
    CLU_NOREF(x);
    CLU_NOREF(ans);

    fprintf(stderr, "struct$create not implemented\n");
    signal(ERR_failure);
}


errcode
_printn(void)
{
    signal(ERR_ok);
}
