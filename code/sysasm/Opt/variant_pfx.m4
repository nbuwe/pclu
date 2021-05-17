define(`MAXFIELDS', `30')dnl
include(`pfx.m4')dnl
dnl
define(`MAKE',
`
errcode
variantOPmake_$1(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_$1, val, ans);
    resignal(err);
}')dnl
dnl
define(`VALUE',
`
errcode
variantOPvalue_$1(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == $1) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}')dnl
dnl
define(`CHANGE',
`
errcode
variantOPchange_$1(CLUREF variant, CLUREF val)
{
    variant.cell->tag = $1;
    variant.cell->value = val.num;
    signal(ERR_ok);
}')dnl
dnl
define(`IS',
`
errcode
variantOPis_$1(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == $1)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}')dnl
dnl
/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

extern errcode variantOPnew(CLUREF tag, CLUREF val, CLUREF *ans);

EMIT(`MAKE')
EMIT(`VALUE')
EMIT(`CHANGE')
EMIT(`IS')
