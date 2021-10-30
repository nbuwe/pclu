
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE tan ****/

extern errcode realOPdiv();
extern errcode sin();
extern errcode cos();

errcode
tan(CLUREF x, CLUREF *ret_1)
{
    errcode err;
    enter_proc(3);

  LINE(5);
    {
    {
    CLUREF T_3_1;
    CLUREF T_3_2;
    CLUREF T_3_3;
    err = sin(x, &T_3_1);
    if (err != ERR_ok) goto ex_2;
    err = cos(x, &T_3_2);
    if (err != ERR_ok) goto ex_2;
    err = realOPdiv(T_3_1, T_3_2, &T_3_3);
    if (err != ERR_ok) goto ex_2;
    ret_1->num = T_3_3.num;
    }
    {signal (ERR_ok);}}
    goto end_2;
    ex_2:
        __CLU_EX_HANDLER;
        if (err == ERR_overflow) {signal(ERR_overflow);}
        else if (err == ERR_underflow) {signal(ERR_underflow);}
        else {
            goto ex_1;}
    end_2:;
        goto end_1;
        ex_1:
            __CLU_EX_HANDLER;
            if ((err == ERR_zero_divide)) {

  LINE(8);
                {
                {signal (ERR_overflow);}}
            }
            else {
                goto ex_0;
            }
        end_1:;

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE tan ****/

