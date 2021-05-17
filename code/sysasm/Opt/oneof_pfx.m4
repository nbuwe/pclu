define(`MAXFIELDS', `41')dnl
include(`pfx.m4')dnl
dnl
define(`MAKE',
`
errcode
oneofOPmake_$1(CLUREF val, CLUREF *ans)
{
    errcode err = oneofOPnew(CLU_$1, val, ans);
    resignal(err);
}')dnl
dnl
define(`VALUE',
`
errcode
oneofOPvalue_$1(CLUREF oneof, CLUREF *ans)
{
    if (oneof.cell->tag == $1) {
	ans->num = oneof.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}')dnl
dnl
define(`IS',
`
errcode
oneofOPis_$1(CLUREF oneof, CLUREF *ans)
{
    if (oneof.cell->tag == $1)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}')dnl
dnl
/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

EMIT(`MAKE')
EMIT(`VALUE')
EMIT(`IS')
