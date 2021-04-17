
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode arrayOPnew();
extern errcode stringOPsize();
extern errcode intOPfrom_to();
extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode arrayOPaddh();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode intOPadd();
extern errcode intOPle();
extern errcode stringOPrest();

/**** BEGIN PROCEDURE split_line ****/

errcode split_line(line, sep, quote, ret_1)
CLUREF line;
CLUREF sep;
CLUREF quote;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF parts;
    CLUREF start;
    CLUREF len;
    CLUREF quote_flag;
    CLUREF idx;
    CLUREF cc;
    enter_proc(8);

  LINE(9);
    {
        {CLUREF T_1_1;
        err = arrayOPnew(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        parts.num = T_1_1.num;
        }
        }

  LINE(10);
    {
        {start.num = 1;
        }
        }

  LINE(11);
    {
        {CLUREF T_1_1;
        err = stringOPsize(line, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        len.num = T_1_1.num;
        }
        }

  LINE(12);
    {
        {quote_flag.tf = false;
        }
        }

  LINE(13);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
        T_1_2.num = len.num;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            idx.num = T_1_1.num;

  LINE(14);
            {
            if (quote_flag.num == true) {

  LINE(15);
                {
                quote_flag.tf = false;
                }
                }
            else {

  LINE(17);
                {
                    {CLUREF T_3_1;
                    err = stringOPfetch(line, idx, &T_3_1);
                    if (err != ERR_ok) goto ex_0;
                    cc.num = T_3_1.num;
                    }
                    }

  LINE(18);
                {
                CLUREF T_3_1;
                T_3_1.num = (cc.ch == quote.ch)? true : false;
                if (T_3_1.num == true) {

  LINE(19);
                    {
                    quote_flag.tf = true;
                    }
                    }
                else {
                CLUREF T_3_2;
                T_3_2.num = (cc.ch == sep.ch)? true : false;
                if (T_3_2.num == true) {

  LINE(21);
                    {
                    CLUREF T_4_1;
                    CLUREF T_4_2;
                    T_4_1.num = idx.num - start.num;
                     if ((T_4_1.num >= 0 && idx.num < 0 && (-start.num) < 0) || 
                         (T_4_1.num <= 0 && idx.num > 0 && (-start.num) > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    err = stringOPsubstr(line, start, T_4_1, &T_4_2);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((parts.array->int_low + parts.array->ext_size + 1) < parts.array->int_size) {
                        parts.array->store->data[parts.array->int_low + parts.array->ext_size] = T_4_2.num;
                        parts.array->ext_size++; parts.array->ext_high++;}
                    else {
                        err = arrayOPaddh(parts, T_4_2);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(22);
                    {
                    CLUREF T_4_1;
                    T_4_1.num = idx.num + 1;
                     if ((T_4_1.num > 0 && idx.num < 0 && 1 < 0) || 
                         (T_4_1.num < 0 && idx.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    start.num = T_4_1.num;
                    }
                    }
                    }}/* end if */
                }}/* end if */
        }
    }
    end_inline_for_1:;

  LINE(26);
    {
    CLUREF T_1_1;
    T_1_1.num = (start.num <= len.num)? true : false;
    if (T_1_1.num == true) {
        {
        CLUREF T_2_1;
        err = stringOPrest(line, start, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        {
        if ((parts.array->int_low + parts.array->ext_size + 1) < parts.array->int_size) {
            parts.array->store->data[parts.array->int_low + parts.array->ext_size] = T_2_1.num;
            parts.array->ext_size++; parts.array->ext_high++;}
        else {
            err = arrayOPaddh(parts, T_2_1);
            if (err != ERR_ok) goto ex_0;}
        }
        }
        }
        }/* end if */

  LINE(27);
    {
    {
    ret_1->num = parts.num;
    }
    {signal (ERR_ok);}}
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE split_line ****/

