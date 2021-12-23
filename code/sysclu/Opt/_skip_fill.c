
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _skip_fill ****/

extern errcode _bytevecOPindexc();
extern errcode intOPadd();
extern errcode intOPequal();
extern errcode intOPgt();
extern errcode _bytevecOPfetch();
extern errcode _chanOPgetb();
extern errcode boolOPnot();
extern errcode charOPequal();
extern errcode intOPsub();
extern errcode _bytevecOPmove_lr();
extern errcode _chanOPgetbv();
extern errcode _bytevecOPsize();

errcode
_skip_fill(CLUREF b, CLUREF max, CLUREF c, CLUREF term, CLUREF *ret_1)
{
    errcode err;
    CLUREF i;
    CLUREF last;
    enter_proc(3);

  LINE(5);
    {
    i.num = 0;
    }

  LINE(6);
    {
    CLUREF T_1_1;
    T_1_1.ch = ' ';
    last.num = T_1_1.num;
    }

  LINE(7);
    for (;;) { /* while */
        if (true != true)
            break;

  LINE(8);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = i.num + 1;
        if ((T_2_1.num > 0 && i.num < 0 && 1 < 0) ||
            (T_2_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        err = _bytevecOPindexc(term, b, T_2_1, &T_2_2);
        if (err != ERR_ok)
            goto ex_0;
        i.num = T_2_2.num;
        }

  LINE(9);
        { /* if */
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_2.num = (i.num == 0);
        T_2_1.num = T_2_2.num;
        if (!T_2_2.num) {
            T_2_3.num = (i.num > max.num);
            T_2_1.num = T_2_3.num;
        }
        if (T_2_1.num == true) { /* if */

  LINE(10);
            {
            CLUREF T_3_1;
            if (max.num < 1 || max.num > b.str->size) {
                err = ERR_bounds;
                goto ex_0;
            }
            T_3_1.ch = b.str->data[max.num - 1];
            last.num = T_3_1.num;
            }

  LINE(11);
            {
            CLUREF T_4_1;
            err = _chanOPgetb(c, b, &T_4_1);
            if (err != ERR_ok)
                goto ex_1;
            max.num = T_4_1.num;
            }
            goto end_1;
          ex_1: /* resignal */
            __CLU_EX_HANDLER;
            if (err == ERR_end_of_file)
                signal(err);
            else
                goto ex_0;
          end_1:;
        }
        else {

  LINE(13);
        CLUREF T_2_4;
        T_2_4.num = (i.num == 1);
        if (T_2_4.num == true) { /* elseif */

  LINE(14);
            { /* if */
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            T_3_1.ch = '\\';
            T_3_2.num = (last.ch == T_3_1.ch);
            T_3_3.num = !T_3_2.num;
            if (T_3_3.num == true) { /* if */

  LINE(15);
                goto end_while_1;
            }
            } /* end if */
        }
        else {

  LINE(16);
        CLUREF T_2_5;
        CLUREF T_2_6;
        CLUREF T_2_7;
        CLUREF T_2_8;
        CLUREF T_2_9;
        T_2_5.num = i.num - 1;
        if ((T_2_5.num >= 0 && i.num < 0 && (-1) < 0) ||
            (T_2_5.num <= 0 && i.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        if (T_2_5.num < 1 || T_2_5.num > b.str->size) {
            err = ERR_bounds;
            goto ex_0;
        }
        T_2_6.ch = b.str->data[T_2_5.num - 1];
        T_2_7.ch = '\\';
        T_2_8.num = (T_2_6.ch == T_2_7.ch);
        T_2_9.num = !T_2_8.num;
        if (T_2_9.num == true) { /* elseif */

  LINE(17);
            goto end_while_1;
        }
        }}} /* end if */
    }
    end_while_1:
    __CLU_END_LABEL;

  LINE(19);
    {
    CLUREF T_1_1;
    T_1_1.num = max.num - i.num;
    if ((T_1_1.num >= 0 && max.num < 0 && (-i.num) < 0) ||
        (T_1_1.num <= 0 && max.num > 0 && (-i.num) > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    max.num = T_1_1.num;
    }

  LINE(20);
    {
    CLUREF T_1_1;
    T_1_1.num = i.num + 1;
    if ((T_1_1.num > 0 && i.num < 0 && 1 < 0) ||
        (T_1_1.num < 0 && i.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_0;
    }
    err = _bytevecOPmove_lr(b, T_1_1, b, CLU_1, max);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(21);
    {
    CLUREF T_2_1;
    CLUREF T_2_2;
    CLUREF T_2_3;
    CLUREF T_2_4;
    T_2_1.num = max.num + 1;
    if ((T_2_1.num > 0 && max.num < 0 && 1 < 0) ||
        (T_2_1.num < 0 && max.num > 0 && 1 > 0)) {
        err = ERR_overflow;
        goto ex_2;
    }
    err = _bytevecOPsize(b, &T_2_2);
    if (err != ERR_ok)
        goto ex_2;
    err = _chanOPgetbv(c, b, T_2_1, T_2_2, &T_2_3);
    if (err != ERR_ok)
        goto ex_2;
    T_2_4.num = max.num + T_2_3.num;
    if ((T_2_4.num > 0 && max.num < 0 && T_2_3.num < 0) ||
        (T_2_4.num < 0 && max.num > 0 && T_2_3.num > 0)) {
        err = ERR_overflow;
        goto ex_2;
    }
    max.num = T_2_4.num;
    }
    goto end_2;
  ex_2: /* except */
    __CLU_EX_HANDLER;
    if (err == ERR_end_of_file) {

  LINE(23);
        { /* if */
        CLUREF T_2_1;
        T_2_1.num = (max.num == 0);
        if (T_2_1.num == true) { /* if */

  LINE(24);
            { /* signal */
                signal(ERR_end_of_file);
            }
        }
        } /* end if */
    }
    else { /* not handled */
        goto ex_0;
    }
  end_2:;

  LINE(26);
    { /* return */
    {
    ret_1->num = max.num;
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

/**** END PROCEDURE _skip_fill ****/

