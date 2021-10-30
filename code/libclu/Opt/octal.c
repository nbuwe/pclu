
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE i_oparse ****/

extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode charOPlt();
extern errcode charOPgt();
extern errcode intOPsub();
extern errcode intOPmul();
extern errcode charOPc2i();
extern errcode intOPadd();
extern errcode intOPminus();

errcode
i_oparse(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF num;
    CLUREF i;
    CLUREF sign;
    CLUREF c;
    enter_proc(3);

  LINE(5);
    {
        {num.num = 0;
        }
        }

  LINE(6);
    {
        {i.num = 1;
        }
        }

  LINE(7);
    {
        {CLUREF T_2_1;
        err = stringOPfetch(s, CLU_1, &T_2_1);
        if (err != ERR_ok) goto ex_1;
        sign.num = T_2_1.num;
        }
        }
        goto end_1;
        ex_1:
            __CLU_EX_HANDLER;
            if ((err == ERR_bounds)) {

  LINE(8);
                {
                {signal (ERR_bad_format);}}
            }
            else {
                goto ex_0;
            }
        end_1:;

  LINE(9);
    {
        {c.num = sign.num;
        }
        }

  LINE(10);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.ch = '+';
    T_1_3.num = (sign.ch == T_1_2.ch)? true : false;
    T_1_1.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_4.ch = '-';
        T_1_5.num = (sign.ch == T_1_4.ch)? true : false;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {

  LINE(11);
        {
        i.num = 2;
        }

  LINE(12);
        {
        CLUREF T_3_1;
        err = stringOPfetch(s, CLU_2, &T_3_1);
        if (err != ERR_ok) goto ex_2;
        c.num = T_3_1.num;
        }
            goto end_2;
            ex_2:
                __CLU_EX_HANDLER;
                if ((err == ERR_bounds)) {

  LINE(13);
                    {
                    {signal (ERR_bad_format);}}
                }
                else {
                    goto ex_0;
                }
            end_2:;
        }
        }/* end if */

  LINE(15);
    for (;;) {
        if (true != true) { break; }

  LINE(16);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        CLUREF T_4_3;
        CLUREF T_4_4;
        CLUREF T_4_5;
        T_4_2.ch = '0';
        err = charOPlt(c, T_4_2, &T_4_3);
        if (err != ERR_ok) goto ex_4;
        T_4_1.num = T_4_3.num;
        if (!T_4_3.num) {
            T_4_4.ch = '7';
            err = charOPgt(c, T_4_4, &T_4_5);
            if (err != ERR_ok) goto ex_4;
            T_4_1.num = T_4_5.num;
        }
        if (T_4_1.num == true) {

  LINE(17);
            {
            {signal (ERR_bad_format);}}
            }
            }/* end if */

  LINE(18);
        {
        CLUREF T_4_1;
        CLUREF T_4_2;
        CLUREF T_4_3;
        CLUREF T_4_4;
        err = intOPmul(num, CLU_8, &T_4_1);
        if (err != ERR_ok) goto ex_4;
        T_4_2.num = (long)(c.ch & 0xff);
        T_4_3.num = T_4_2.num - 48;
         if ((T_4_3.num >= 0 && T_4_2.num < 0 && (-48) < 0) ||
             (T_4_3.num <= 0 && T_4_2.num > 0 && (-48) > 0)) {
            err = ERR_overflow;
            goto ex_4;}
        T_4_4.num = T_4_1.num - T_4_3.num;
         if ((T_4_4.num >= 0 && T_4_1.num < 0 && (-T_4_3.num) < 0) ||
             (T_4_4.num <= 0 && T_4_1.num > 0 && (-T_4_3.num) > 0)) {
            err = ERR_overflow;
            goto ex_4;}
        num.num = T_4_4.num;
        }

  LINE(19);
        {
        CLUREF T_4_1;
        T_4_1.num = i.num + 1;
         if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
             (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_4;}
        i.num = T_4_1.num;
        }

  LINE(20);
        {
        CLUREF T_4_1;
        err = stringOPfetch(s, i, &T_4_1);
        if (err != ERR_ok) goto ex_4;
        c.num = T_4_1.num;
        }
        }
        end_while_1:
        __CLU_END_LABEL;
    goto end_4;
    ex_4:
        __CLU_EX_HANDLER;
        if (err == ERR_overflow) {signal(ERR_overflow);}
        else {
            goto ex_3;}
    end_4:;
        goto end_3;
        ex_3:
            __CLU_EX_HANDLER;
            if ((err == ERR_bounds)) {
            }
            else {
                goto ex_0;
            }
        end_3:;

  LINE(24);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    T_2_1.ch = '-';
    T_2_2.num = (sign.ch == T_2_1.ch)? true : false;
    if (T_2_2.num == true) {

  LINE(25);
        {
        {
        ret_1->num = num.num;
        }
        {signal (ERR_ok);}}
        }
    else {

  LINE(26);
        {
        {
        CLUREF T_3_1;
        err = intOPminus(num, &T_3_1);
        if (err != ERR_ok) goto ex_5;
        ret_1->num = T_3_1.num;
        }
        {signal (ERR_ok);}}
        }}/* end if */
    goto end_5;
    ex_5:
        __CLU_EX_HANDLER;
        if (err == ERR_overflow) {signal(ERR_overflow);}
        else {
            goto ex_0;}
    end_5:;

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

/**** END PROCEDURE i_oparse ****/



/**** BEGIN PROCEDURE i_ounparse ****/

extern errcode intOPlt();
extern errcode intOPmod();
extern errcode intOPdiv();
extern errcode intOPequal();
extern errcode stringOPconcat();
extern errcode stringOPc2s();
extern errcode charOPi2c();
static CLUREF STR__055;
static CLUREF STR_0;
static int i_ounparse_own_init = 0;

errcode
i_ounparse(CLUREF i, CLUREF *ret_1)
{
    errcode err;
    CLUREF sign;
    CLUREF s;
    CLUREF j;
    if (i_ounparse_own_init == 0) {
        stringOPcons("-", CLU_1, CLUREF_make_num(1), &STR__055);
        stringOPcons("0", CLU_1, CLUREF_make_num(1), &STR_0);
        i_ounparse_own_init = 1;
    }
    enter_proc(30);

  LINE(32);
    {
        {sign = CLU_empty_string;
        }
        }

  LINE(33);
    {
    CLUREF T_1_1;
    T_1_1.num = (i.num < 0)? true : false;
    if (T_1_1.num == true) {

  LINE(34);
        {
        sign = STR__055;
        }
        }
    else {

  LINE(35);
        {
        CLUREF T_2_1;
        err = intOPminus(i, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        i.num = T_2_1.num;
        }
        }}/* end if */

  LINE(37);
    {
        {s = CLU_empty_string;
        }
        }

  LINE(38);
    for (;;) {
        if (true != true) { break; }

  LINE(39);
        {
            {CLUREF T_2_1;
            err = intOPmod(i, CLU_8, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            j.num = T_2_1.num;
            }
            }

  LINE(40);
        {
        CLUREF T_2_1;
        err = intOPdiv(i, CLU_8, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        i.num = T_2_1.num;
        }

  LINE(41);
        {
        CLUREF T_2_1;
        T_2_1.num = (j.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(42);
            {
            CLUREF T_3_1;
            err = stringOPconcat(STR_0, s, &T_3_1);
            if (err != ERR_ok) goto ex_0;
            s.num = T_3_1.num;
            }
            }
        else {

  LINE(43);
            {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            CLUREF T_3_4;
            CLUREF T_3_5;
            T_3_1.num = 56;
            T_3_2.num = T_3_1.num - j.num;
             if ((T_3_2.num >= 0 && T_3_1.num < 0 && (-j.num) < 0) ||
                 (T_3_2.num <= 0 && T_3_1.num > 0 && (-j.num) > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            err = charOPi2c(T_3_2, &T_3_3);
            if (err != ERR_ok) goto ex_0;
            err = stringOPc2s(T_3_3, &T_3_4);
            if (err != ERR_ok) goto ex_0;
            err = stringOPconcat(T_3_4, s, &T_3_5);
            if (err != ERR_ok) goto ex_0;
            s.num = T_3_5.num;
            }

  LINE(44);
            {
            CLUREF T_3_1;
            T_3_1.num = i.num + 1;
             if ((T_3_1.num > 0 && i.num < 0 && 1 < 0) ||
                 (T_3_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            i.num = T_3_1.num;
            }
            }}/* end if */

  LINE(46);
        {
        CLUREF T_2_1;
        T_2_1.num = (i.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(47);
            {
            {
            CLUREF T_3_1;
            err = stringOPconcat(sign, s, &T_3_1);
            if (err != ERR_ok) goto ex_0;
            ret_1->num = T_3_1.num;
            }
            {signal (ERR_ok);}}
            }
            }/* end if */
        }
        end_while_1:
        __CLU_END_LABEL;

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

/**** END PROCEDURE i_ounparse ****/

