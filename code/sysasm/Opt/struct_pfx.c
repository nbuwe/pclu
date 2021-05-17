/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

extern errcode structOPblit(CLUREF strukt, CLUREF *ans);


errcode
structOPget_1(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[0];
    signal(ERR_ok);
}

errcode
structOPget_2(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[1];
    signal(ERR_ok);
}

errcode
structOPget_3(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[2];
    signal(ERR_ok);
}

errcode
structOPget_4(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[3];
    signal(ERR_ok);
}

errcode
structOPget_5(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[4];
    signal(ERR_ok);
}

errcode
structOPget_6(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[5];
    signal(ERR_ok);
}

errcode
structOPget_7(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[6];
    signal(ERR_ok);
}

errcode
structOPget_8(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[7];
    signal(ERR_ok);
}

errcode
structOPget_9(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[8];
    signal(ERR_ok);
}

errcode
structOPget_10(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[9];
    signal(ERR_ok);
}

errcode
structOPget_11(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[10];
    signal(ERR_ok);
}

errcode
structOPget_12(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[11];
    signal(ERR_ok);
}

errcode
structOPget_13(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[12];
    signal(ERR_ok);
}

errcode
structOPget_14(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[13];
    signal(ERR_ok);
}

errcode
structOPget_15(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[14];
    signal(ERR_ok);
}

errcode
structOPget_16(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[15];
    signal(ERR_ok);
}

errcode
structOPget_17(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[16];
    signal(ERR_ok);
}

errcode
structOPget_18(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[17];
    signal(ERR_ok);
}

errcode
structOPget_19(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[18];
    signal(ERR_ok);
}

errcode
structOPget_20(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[19];
    signal(ERR_ok);
}

errcode
structOPget_21(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[20];
    signal(ERR_ok);
}

errcode
structOPget_22(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[21];
    signal(ERR_ok);
}

errcode
structOPget_23(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[22];
    signal(ERR_ok);
}

errcode
structOPget_24(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[23];
    signal(ERR_ok);
}

errcode
structOPget_25(CLUREF strukt, CLUREF *ans)
{
    ans->num = strukt.vec->data[24];
    signal(ERR_ok);
}

errcode
structOPreplace_1(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[0] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_2(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[1] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_3(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[2] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_4(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[3] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_5(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[4] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_6(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[5] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_7(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[6] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_8(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[7] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_9(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[8] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_10(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[9] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_11(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[10] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_12(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[11] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_13(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[12] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_14(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[13] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_15(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[14] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_16(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[15] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_17(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[16] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_18(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[17] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_19(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[18] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_20(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[19] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_21(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[20] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_22(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[21] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_23(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[22] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_24(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[23] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}

errcode
structOPreplace_25(CLUREF strukt, CLUREF val, CLUREF *ans)
{
    CLUREF temp;
    errcode err = structOPblit(strukt, &temp);
    if (err != ERR_ok) resignal(err);

    temp.vec->data[24] = val.num;
    ans->vec = temp.vec;
    signal(ERR_ok);
}
