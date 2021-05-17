define(`MAXFIELDS', `25')dnl
include(`pfx.m4')dnl
dnl
define(`GET',
`
errcode
recordOPget_$1(CLUREF record, CLUREF *ans)
{
    ans->num = record.vec->data[decr($1)];
    signal(ERR_ok);
}')dnl
dnl
define(`SET',
`
errcode
recordOPset_$1(CLUREF record, CLUREF val)
{
    record.vec->data[decr($1)] = val.num;
    signal(ERR_ok);
}')dnl
dnl
/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

EMIT(`GET')
EMIT(`SET')
