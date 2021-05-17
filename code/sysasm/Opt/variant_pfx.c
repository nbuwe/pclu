/* Copyright Massachusetts Institute of Technology 1990,1991 */
#include <pclu_err.h>
#include <pclu_sys.h>

extern errcode variantOPnew(CLUREF tag, CLUREF val, CLUREF *ans);


errcode
variantOPmake_1(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_1, val, ans);
    resignal(err);
}

errcode
variantOPmake_2(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_2, val, ans);
    resignal(err);
}

errcode
variantOPmake_3(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_3, val, ans);
    resignal(err);
}

errcode
variantOPmake_4(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_4, val, ans);
    resignal(err);
}

errcode
variantOPmake_5(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_5, val, ans);
    resignal(err);
}

errcode
variantOPmake_6(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_6, val, ans);
    resignal(err);
}

errcode
variantOPmake_7(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_7, val, ans);
    resignal(err);
}

errcode
variantOPmake_8(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_8, val, ans);
    resignal(err);
}

errcode
variantOPmake_9(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_9, val, ans);
    resignal(err);
}

errcode
variantOPmake_10(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_10, val, ans);
    resignal(err);
}

errcode
variantOPmake_11(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_11, val, ans);
    resignal(err);
}

errcode
variantOPmake_12(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_12, val, ans);
    resignal(err);
}

errcode
variantOPmake_13(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_13, val, ans);
    resignal(err);
}

errcode
variantOPmake_14(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_14, val, ans);
    resignal(err);
}

errcode
variantOPmake_15(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_15, val, ans);
    resignal(err);
}

errcode
variantOPmake_16(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_16, val, ans);
    resignal(err);
}

errcode
variantOPmake_17(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_17, val, ans);
    resignal(err);
}

errcode
variantOPmake_18(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_18, val, ans);
    resignal(err);
}

errcode
variantOPmake_19(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_19, val, ans);
    resignal(err);
}

errcode
variantOPmake_20(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_20, val, ans);
    resignal(err);
}

errcode
variantOPmake_21(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_21, val, ans);
    resignal(err);
}

errcode
variantOPmake_22(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_22, val, ans);
    resignal(err);
}

errcode
variantOPmake_23(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_23, val, ans);
    resignal(err);
}

errcode
variantOPmake_24(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_24, val, ans);
    resignal(err);
}

errcode
variantOPmake_25(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_25, val, ans);
    resignal(err);
}

errcode
variantOPmake_26(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_26, val, ans);
    resignal(err);
}

errcode
variantOPmake_27(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_27, val, ans);
    resignal(err);
}

errcode
variantOPmake_28(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_28, val, ans);
    resignal(err);
}

errcode
variantOPmake_29(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_29, val, ans);
    resignal(err);
}

errcode
variantOPmake_30(CLUREF val, CLUREF *ans)
{
    errcode err = variantOPnew(CLU_30, val, ans);
    resignal(err);
}

errcode
variantOPvalue_1(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 1) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_2(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 2) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_3(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 3) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_4(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 4) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_5(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 5) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_6(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 6) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_7(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 7) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_8(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 8) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_9(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 9) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_10(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 10) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_11(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 11) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_12(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 12) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_13(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 13) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_14(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 14) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_15(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 15) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_16(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 16) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_17(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 17) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_18(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 18) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_19(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 19) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_20(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 20) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_21(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 21) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_22(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 22) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_23(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 23) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_24(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 24) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_25(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 25) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_26(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 26) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_27(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 27) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_28(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 28) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_29(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 29) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPvalue_30(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 30) {
	ans->num = variant.cell->value;
	signal(ERR_ok);
    }
    else
	signal(ERR_wrong_tag);
}

errcode
variantOPchange_1(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 1;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_2(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 2;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_3(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 3;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_4(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 4;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_5(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 5;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_6(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 6;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_7(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 7;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_8(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 8;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_9(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 9;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_10(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 10;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_11(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 11;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_12(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 12;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_13(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 13;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_14(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 14;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_15(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 15;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_16(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 16;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_17(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 17;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_18(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 18;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_19(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 19;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_20(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 20;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_21(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 21;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_22(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 22;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_23(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 23;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_24(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 24;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_25(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 25;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_26(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 26;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_27(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 27;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_28(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 28;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_29(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 29;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPchange_30(CLUREF variant, CLUREF val)
{
    variant.cell->tag = 30;
    variant.cell->value = val.num;
    signal(ERR_ok);
}

errcode
variantOPis_1(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 1)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_2(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 2)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_3(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 3)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_4(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 4)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_5(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 5)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_6(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 6)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_7(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 7)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_8(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 8)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_9(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 9)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_10(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 10)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_11(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 11)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_12(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 12)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_13(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 13)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_14(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 14)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_15(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 15)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_16(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 16)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_17(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 17)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_18(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 18)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_19(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 19)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_20(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 20)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_21(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 21)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_22(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 22)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_23(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 23)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_24(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 24)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_25(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 25)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_26(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 26)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_27(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 27)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_28(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 28)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_29(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 29)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}

errcode
variantOPis_30(CLUREF variant, CLUREF *ans)
{
    if (variant.cell->tag == 30)
	ans->tf = true;
    else
        ans->tf = false;
    signal(ERR_ok);
}
