
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE g_form ****/

extern errcode intOPlt();
extern errcode intOPequal();
extern errcode realOPexponent();
extern errcode realOPequal();
extern errcode intOPge();
extern errcode f_form();
extern errcode intOPsub();
extern errcode intOPadd();
extern errcode e_form();

errcode
g_form(CLUREF x, CLUREF i, CLUREF f, CLUREF *ret_1)
{
    errcode err;
    CLUREF expon;
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
    CLUREF T_2_1;
    err = realOPexponent(x, &T_2_1);
    if (err != ERR_ok)
        goto ex_1;
    expon.num = T_2_1.num;
    }
    goto end_1;
  ex_1: /* except */
    __CLU_EX_HANDLER;
    if (err == ERR_undefined) {
    }
    else { /* not handled */
        goto ex_0;
    }
  end_1:;

  LINE(10);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    T_1_2.real = 0.000000e+00;
    err = realOPequal(x, T_1_2, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    T_1_1.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_5.num = -1;
        T_1_6.num = (expon.num >= T_1_5.num);
        T_1_4.num = T_1_6.num;
        if (T_1_6.num) {
            T_1_7.num = (expon.num < i.num);
            T_1_4.num = T_1_7.num;
        }
        T_1_1.num = T_1_4.num;
    }
    if (T_1_1.num == true) { /* if */

  LINE(11);
        { /* return */
        {
        CLUREF T_3_1;
        err = f_form(x, i, f, &T_3_1);
        if (err != ERR_ok)
            goto ex_2;
        ret_1->num = T_3_1.num;
        }
        signal (ERR_ok);
        }
        goto end_2;
      ex_2: /* except */
        __CLU_EX_HANDLER;
        if (err == ERR_insufficient_field_width) {
        }
        else { /* not handled */
            goto ex_0;
        }
      end_2:;
    }
    } /* end if */

  LINE(14);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = i.num + f.num;
    if ((T_1_1.num > 0 && i.num < 0 && f.num < 0) ||
        (T_1_1.num < 0 && i.num > 0 && f.num > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    T_1_2.num = T_1_1.num - 5;
    if ((T_1_2.num >= 0 && T_1_1.num < 0 && (-5) < 0) ||
        (T_1_2.num <= 0 && T_1_1.num > 0 && (-5) > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    i.num = T_1_2.num;
    }

  LINE(15);
    { /* if */
    CLUREF T_1_1;
    T_1_1.num = (i.num >= 0);
    if (T_1_1.num == true) { /* if */

  LINE(16);
        { /* return */
        {
        CLUREF T_2_1;
        err = e_form(x, CLU_1, i, &T_2_1);
        if (err != ERR_ok)
            goto ex_0;
        ret_1->num = T_2_1.num;
        }
        signal (ERR_ok);
        }
    }
    } /* end if */

  LINE(17);
    { /* signal */
        signal(ERR_insufficient_field_width);
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

/**** END PROCEDURE g_form ****/

