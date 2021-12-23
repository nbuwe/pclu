
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE f_form ****/

extern errcode intOPlt();
extern errcode intOPequal();
extern errcode _unparse_real();
extern errcode boolOPnot();
extern errcode realOPequal();
extern errcode _round_real();
extern errcode intOPadd();
extern errcode intOPgt();
extern errcode _bytevecOPcreate();
extern errcode _bytevecOPstore();
extern errcode intOPge();
extern errcode intOPle();
extern errcode _bytevecOPfetch();
extern errcode intOPsub();
extern errcode _cvt();

errcode
f_form(CLUREF x, CLUREF i, CLUREF f, CLUREF *ret_1)
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

  LINE(6);
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

  LINE(7);
        { /* signal */
            signal(ERR_illegal_field_width);
        }
    }
    } /* end if */

  LINE(8);
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

  LINE(9);
    {
    ndigs.num = 0;
    }

  LINE(11);
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

  LINE(12);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = expon.num + f.num;
        if ((T_2_1.num > 0 && expon.num < 0 && f.num < 0) ||
            (T_2_1.num < 0 && expon.num > 0 && f.num > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        err = _round_real(digits, T_2_1, &T_2_2, &T_2_3);
        if (err != ERR_ok)
            goto ex_0;
        n.num = T_2_2.num;
        ndigs.num = T_2_3.num;
        }

  LINE(13);
        {
        CLUREF T_2_1;
        T_2_1.num = expon.num + n.num;
        if ((T_2_1.num > 0 && expon.num < 0 && n.num < 0) ||
            (T_2_1.num < 0 && expon.num > 0 && n.num > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        expon.num = T_2_1.num;
        }

  LINE(14);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (expon.num > i.num);
        if (T_2_1.num == true) { /* if */

  LINE(15);
            { /* signal */
                signal(ERR_insufficient_field_width);
            }
        }
        } /* end if */
    }
    } /* end if */

  LINE(17);
    {
    CLUREF T_1_1;
    T_1_1.num = f.num + 1;
    if ((T_1_1.num > 0 && f.num < 0 && 1 < 0) ||
        (T_1_1.num < 0 && f.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    n.num = T_1_1.num;
    }

  LINE(18);
    { /* if */
    CLUREF T_1_1;
    T_1_1.num = (i.num > 0);
    if (T_1_1.num == true) { /* if */

  LINE(19);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (expon.num > 0);
        if (T_2_1.num == true) { /* if */

  LINE(20);
            {
            CLUREF T_3_1;
            T_3_1.num = n.num + expon.num;
            if ((T_3_1.num > 0 && n.num < 0 && expon.num < 0) ||
                (T_3_1.num < 0 && n.num > 0 && expon.num > 0)) {
                err = ERR_overflow;
                goto ex_0;
            }
            n.num = T_3_1.num;
            }

  LINE(21);
            { /* if */
            CLUREF T_3_1;
            T_3_1.num = (i.num > expon.num);
            if (T_3_1.num == true) { /* if */

  LINE(22);
                {
                i.num = expon.num;
                }
            }
            } /* end if */
        }
        else { /* else */

  LINE(23);
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

  LINE(24);
            { /* if */
            CLUREF T_3_1;
            T_3_1.num = (i.num > 1);
            if (T_3_1.num == true) { /* if */

  LINE(25);
                {
                i.num = 1;
                }
            }
            } /* end if */
        }} /* end if */
    }
    } /* end if */

  LINE(28);
    { /* if */
    if (minus.num == true) { /* if */

  LINE(29);
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

  LINE(30);
    {
    CLUREF T_1_1;
    err = _bytevecOPcreate(n, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    res.num = T_1_1.num;
    }

  LINE(31);
    {
    n.num = 1;
    }

  LINE(32);
    { /* if */
    if (minus.num == true) { /* if */

  LINE(33);
        {
        CLUREF T_2_1;
        T_2_1.ch = '-';
        err = _bytevecOPstore(res, CLU_1, T_2_1);
        if (err != ERR_ok)
            goto ex_0;
        }

  LINE(34);
        {
        n.num = 2;
        }
    }
    } /* end if */

  LINE(36);
    {
    j.num = 1;
    }

  LINE(37);
    for (;;) { /* while */
        if (true != true)
            break;

  LINE(38);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (i.num == 0);
        if (T_2_1.num == true) { /* if */

  LINE(39);
            {
            CLUREF T_3_1;
            T_3_1.ch = '.';
            err = _bytevecOPstore(res, n, T_3_1);
            if (err != ERR_ok)
                goto ex_0;
            }

  LINE(40);
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

  LINE(41);
            { /* if */
            CLUREF T_3_1;
            T_3_1.num = (f.num == 0);
            if (T_3_1.num == true) { /* if */

  LINE(42);
                goto end_while_1;
            }
            } /* end if */
        }
        } /* end if */

  LINE(44);
        {
        CLUREF T_2_1;
        T_2_1.ch = '0';
        c.num = T_2_1.num;
        }

  LINE(45);
        { /* if */
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_2.num = (expon.num >= i.num);
        T_2_1.num = T_2_2.num;
        if (T_2_2.num) {
            T_2_3.num = (j.num <= ndigs.num);
            T_2_1.num = T_2_3.num;
        }
        if (T_2_1.num == true) { /* if */

  LINE(46);
            {
            CLUREF T_3_1;
            if (j.num < 1 || j.num > digits.str->size) {
                err = ERR_bounds;
                goto ex_0;
            }
            T_3_1.ch = digits.str->data[j.num - 1];
            c.num = T_3_1.num;
            }

  LINE(47);
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

  LINE(49);
        {
        err = _bytevecOPstore(res, n, c);
        if (err != ERR_ok)
            goto ex_0;
        }

  LINE(50);
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

  LINE(51);
        {
        CLUREF T_2_1;
        T_2_1.num = i.num - 1;
        if ((T_2_1.num >= 0 && i.num < 0 && (-1) < 0) ||
            (T_2_1.num <= 0 && i.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        i.num = T_2_1.num;
        }

  LINE(52);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (i.num >= 0);
        if (T_2_1.num == true) { /* if */

  LINE(53);
            continue;
        }
        } /* end if */

  LINE(54);
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

  LINE(55);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (f.num <= 0);
        if (T_2_1.num == true) { /* if */

  LINE(56);
            goto end_while_1;
        }
        } /* end if */
    }
    end_while_1:
    __CLU_END_LABEL;

  LINE(58);
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

/**** END PROCEDURE f_form ****/

