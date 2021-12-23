
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE e_form ****/

extern errcode intOPlt();
extern errcode intOPequal();
extern errcode _unparse_real();
extern errcode boolOPnot();
extern errcode realOPequal();
extern errcode _round_real();
extern errcode intOPadd();
extern errcode intOPsub();
extern errcode _bytevecOPcreate();
extern errcode _bytevecOPstore();
extern errcode intOPle();
extern errcode _bytevecOPfetch();
extern errcode intOPgt();
extern errcode intOPge();
extern errcode intOPminus();
extern errcode charOPi2c();
extern errcode intOPdiv();
extern errcode intOPmod();
extern errcode _cvt();

errcode
e_form(CLUREF x, CLUREF i, CLUREF f, CLUREF *ret_1)
{
    errcode err;
    CLUREF minus;
    CLUREF digits;
    CLUREF expon;
    CLUREF ndigs;
    CLUREF n;
    CLUREF res;
    CLUREF j;
    CLUREF c;
    enter_proc(3);

  LINE(7);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    T_1_3.num = (i.num < 0);
    T_1_2.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_4.num = (f.num < 0);
        T_1_2.num = T_1_4.num;
    }
    T_1_1.num = T_1_2.num;
    if (!T_1_2.num) {
        T_1_6.num = (i.num == 0);
        T_1_5.num = T_1_6.num;
        if (T_1_6.num) {
            T_1_7.num = (f.num == 0);
            T_1_5.num = T_1_7.num;
        }
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) { /* if */

  LINE(8);
        { /* signal */
            signal(ERR_illegal_field_width);
        }
    }
    } /* end if */

  LINE(9);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    err = _unparse_real(x, &T_1_1, &T_1_2, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    minus.num = T_1_1.num;
    digits.num = T_1_2.num;
    expon.num = T_1_3.num;
    }

  LINE(10);
    {
    ndigs.num = 0;
    }

  LINE(12);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.real = 0.000000e+00;
    err = realOPequal(x, T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    T_1_3.num = !T_1_2.num;
    if (T_1_3.num == true) { /* if */

  LINE(13);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = i.num + f.num;
        if ((T_2_1.num > 0 && i.num < 0 && f.num < 0) ||
            (T_2_1.num < 0 && i.num > 0 && f.num > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        err = _round_real(digits, T_2_1, &T_2_2, &T_2_3);
        if (err != ERR_ok)
            goto ex_0;
        n.num = T_2_2.num;
        ndigs.num = T_2_3.num;
        }

  LINE(14);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = expon.num + n.num;
        if ((T_2_1.num > 0 && expon.num < 0 && n.num < 0) ||
            (T_2_1.num < 0 && expon.num > 0 && n.num > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        T_2_2.num = T_2_1.num - i.num;
        if ((T_2_2.num >= 0 && T_2_1.num < 0 && (-i.num) < 0) ||
            (T_2_2.num <= 0 && T_2_1.num > 0 && (-i.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        expon.num = T_2_2.num;
        }
    }
    } /* end if */

  LINE(16);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = i.num + f.num;
    if ((T_1_1.num > 0 && i.num < 0 && f.num < 0) ||
        (T_1_1.num < 0 && i.num > 0 && f.num > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    T_1_2.num = T_1_1.num + 5;
    if ((T_1_2.num > 0 && T_1_1.num < 0 && 5 < 0) ||
        (T_1_2.num < 0 && T_1_1.num > 0 && 5 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    n.num = T_1_2.num;
    }

  LINE(17);
    { /* if */
    if (minus.num == true) { /* if */

  LINE(18);
        {
        CLUREF T_2_1;
        T_2_1.num = n.num + 1;
        if ((T_2_1.num > 0 && n.num < 0 && 1 < 0) ||
            (T_2_1.num < 0 && n.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        n.num = T_2_1.num;
        }
    }
    } /* end if */

  LINE(19);
    { /* if */
    CLUREF T_1_1;
    T_1_1.num = (f.num == 0);
    if (T_1_1.num == true) { /* if */

  LINE(20);
        {
        CLUREF T_2_1;
        T_2_1.num = n.num - 1;
        if ((T_2_1.num >= 0 && n.num < 0 && (-1) < 0) ||
            (T_2_1.num <= 0 && n.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        n.num = T_2_1.num;
        }
    }
    } /* end if */

  LINE(21);
    {
    CLUREF T_1_1;
    err = _bytevecOPcreate(n, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    res.num = T_1_1.num;
    }

  LINE(22);
    {
    n.num = 1;
    }

  LINE(23);
    { /* if */
    if (minus.num == true) { /* if */

  LINE(24);
        {
        CLUREF T_2_1;
        T_2_1.ch = '-';
        err = _bytevecOPstore(res, CLU_1, T_2_1);
        if (err != ERR_ok)
            goto ex_0;
        }

  LINE(25);
        {
        n.num = 2;
        }
    }
    } /* end if */

  LINE(27);
    {
    j.num = 1;
    }

  LINE(28);
    for (;;) { /* while */
        if (true != true)
            break;

  LINE(29);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (i.num == 0);
        if (T_2_1.num == true) { /* if */

  LINE(30);
            { /* if */
            CLUREF T_3_1;
            T_3_1.num = (f.num == 0);
            if (T_3_1.num == true) { /* if */

  LINE(31);
                goto end_while_1;
            }
            } /* end if */

  LINE(32);
            {
            CLUREF T_3_1;
            T_3_1.ch = '.';
            err = _bytevecOPstore(res, n, T_3_1);
            if (err != ERR_ok)
                goto ex_0;
            }

  LINE(33);
            {
            CLUREF T_3_1;
            T_3_1.num = n.num + 1;
            if ((T_3_1.num > 0 && n.num < 0 && 1 < 0) ||
                (T_3_1.num < 0 && n.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;
            }
            n.num = T_3_1.num;
            }

  LINE(34);
            {
            i.num = -1;
            }
        }
        } /* end if */

  LINE(36);
        {
        CLUREF T_2_1;
        T_2_1.ch = '0';
        c.num = T_2_1.num;
        }

  LINE(37);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (j.num <= ndigs.num);
        if (T_2_1.num == true) { /* if */

  LINE(38);
            {
            CLUREF T_3_1;
            if (j.num < 1 || j.num > digits.str->size) {
                err = ERR_bounds;
                goto ex_0;
            }
            T_3_1.ch = digits.str->data[j.num - 1];
            c.num = T_3_1.num;
            }

  LINE(39);
            {
            CLUREF T_3_1;
            T_3_1.num = j.num + 1;
            if ((T_3_1.num > 0 && j.num < 0 && 1 < 0) ||
                (T_3_1.num < 0 && j.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;
            }
            j.num = T_3_1.num;
            }
        }
        } /* end if */

  LINE(41);
        {
        err = _bytevecOPstore(res, n, c);
        if (err != ERR_ok)
            goto ex_0;
        }

  LINE(42);
        {
        CLUREF T_2_1;
        T_2_1.num = n.num + 1;
        if ((T_2_1.num > 0 && n.num < 0 && 1 < 0) ||
            (T_2_1.num < 0 && n.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        n.num = T_2_1.num;
        }

  LINE(43);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (i.num > 0);
        if (T_2_1.num == true) { /* if */

  LINE(44);
            {
            CLUREF T_3_1;
            T_3_1.num = i.num - 1;
            if ((T_3_1.num >= 0 && i.num < 0 && (-1) < 0) ||
                (T_3_1.num <= 0 && i.num > 0 && (-1) > 0)) {
                err = ERR_overflow;
                goto ex_0;
            }
            i.num = T_3_1.num;
            }

  LINE(45);
            continue;
        }
        } /* end if */

  LINE(47);
        {
        CLUREF T_2_1;
        T_2_1.num = f.num - 1;
        if ((T_2_1.num >= 0 && f.num < 0 && (-1) < 0) ||
            (T_2_1.num <= 0 && f.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        f.num = T_2_1.num;
        }

  LINE(48);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (f.num == 0);
        if (T_2_1.num == true) { /* if */

  LINE(49);
            goto end_while_1;
        }
        } /* end if */
    }
    end_while_1:
    __CLU_END_LABEL;

  LINE(51);
    {
    CLUREF T_1_1;
    T_1_1.ch = 'e';
    err = _bytevecOPstore(res, n, T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(52);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.real = 0.000000e+00;
    err = realOPequal(x, T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    if (T_1_2.num == true) { /* if */

  LINE(53);
        {
        expon.num = 0;
        }
    }
    } /* end if */

  LINE(54);
    { /* if */
    CLUREF T_1_1;
    T_1_1.num = (expon.num >= 0);
    if (T_1_1.num == true) { /* if */

  LINE(55);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = n.num + 1;
        if ((T_2_1.num > 0 && n.num < 0 && 1 < 0) ||
            (T_2_1.num < 0 && n.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        T_2_2.ch = '+';
        err = _bytevecOPstore(res, T_2_1, T_2_2);
        if (err != ERR_ok)
            goto ex_0;
        }
    }
    else { /* else */

  LINE(56);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = n.num + 1;
        if ((T_2_1.num > 0 && n.num < 0 && 1 < 0) ||
            (T_2_1.num < 0 && n.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        T_2_2.ch = '-';
        err = _bytevecOPstore(res, T_2_1, T_2_2);
        if (err != ERR_ok)
            goto ex_0;
        }

  LINE(57);
        {
        CLUREF T_2_1;
        err = intOPminus(expon, &T_2_1);
        if (err != ERR_ok)
            goto ex_0;
        expon.num = T_2_1.num;
        }
    }} /* end if */

  LINE(59);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = n.num + 2;
    if ((T_1_1.num > 0 && n.num < 0 && 2 < 0) ||
        (T_1_1.num < 0 && n.num > 0 && 2 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    err = intOPdiv(expon, CLU_10, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    T_1_3.num = T_1_2.num + 48;
    if ((T_1_3.num > 0 && T_1_2.num < 0 && 48 < 0) ||
        (T_1_3.num < 0 && T_1_2.num > 0 && 48 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    err = charOPi2c(T_1_3, &T_1_4);
    if (err != ERR_ok)
        goto ex_0;
    err = _bytevecOPstore(res, T_1_1, T_1_4);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(60);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = n.num + 3;
    if ((T_1_1.num > 0 && n.num < 0 && 3 < 0) ||
        (T_1_1.num < 0 && n.num > 0 && 3 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    err = intOPmod(expon, CLU_10, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    T_1_3.num = T_1_2.num + 48;
    if ((T_1_3.num > 0 && T_1_2.num < 0 && 48 < 0) ||
        (T_1_3.num < 0 && T_1_2.num > 0 && 48 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    err = charOPi2c(T_1_3, &T_1_4);
    if (err != ERR_ok)
        goto ex_0;
    err = _bytevecOPstore(res, T_1_1, T_1_4);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(61);
    { /* return */
    {
    CLUREF T_1_1;
    T_1_1.num = (long)res.num;
    ret_1->num = T_1_1.num;
    }
    signal (ERR_ok);
    }

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

/**** END PROCEDURE e_form ****/

