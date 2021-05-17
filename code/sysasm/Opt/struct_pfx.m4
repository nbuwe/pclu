define(`MAXFIELDS', `25')dnl
include(`pfx.m4')dnl
dnl
define(`GET',
`
errcode
structOPget_$1(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[decr($1)];
    signal(ERR_ok);
}')dnl
dnl
define(`REPLACE',
`
errcode
structOPreplace_$1(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[decr($1)] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}')dnl
dnl
/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

extern errcode structOPblit(CLUREF strukt, CLUREF *ans);

EMIT(`GET')
EMIT(`REPLACE')
