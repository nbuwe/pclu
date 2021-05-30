
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE lex_scan ****/

extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode stringOPsize();
extern errcode intOPfrom_to();
extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode arrayOPaddh();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode stringOPindexc();
extern errcode boolOPor();
extern errcode intOPadd();
static CLUREF STR_Beginq_040and_040Endq_040must_040be_040of_040the_040same_040size;
static int lex_scan_own_init = 0;

errcode
lex_scan(CLUREF s, CLUREF sep_chars, CLUREF fill_chars, CLUREF beginq, CLUREF endq, CLUREF comment_char, CLUREF *ret_1)
{
    errcode err;
    CLUREF ps;
    CLUREF state;
    CLUREF mark;
    CLUREF i;
    CLUREF end_quote;
    CLUREF ch;
    CLUREF fillc;
    CLUREF sepc;
    CLUREF qix;
    CLUREF bq;
    CLUREF textc;
    if (lex_scan_own_init == 0) {
        stringOPcons("Beginq and Endq must be of the same size", CLU_1, CLUREF_make_num(40), &STR_Beginq_040and_040Endq_040must_040be_040of_040the_040same_040size);
        lex_scan_own_init = 1;
    }
    enter_proc(26);

  LINE(36);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = stringOPsize(beginq, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = stringOPsize(endq, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(37);
        {
        elist[0] = STR_Beginq_040and_040Endq_040must_040be_040of_040the_040same_040size;
        {signal (ERR_failure);}}
        }
        }/* end if */

  LINE(39);
    {
        {CLUREF T_1_1;
        err = arrayOPnew( &T_1_1);
        if (err != ERR_ok) goto ex_0;
        ps.num = T_1_1.num;
        }
        }

  LINE(40);
    {
        {state.num = 2;
        }
        }

  LINE(45);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_3.num = T_1_1.num;
        for (T_1_2.num = 1; T_1_2.num <= T_1_3.num; T_1_2.num++) {
            i.num = T_1_2.num;

  LINE(46);
            {
            CLUREF T_2_1;
            err = stringOPfetch(s, i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            ch.num = T_2_1.num;
            }

  LINE(47);
            {
            CLUREF T_2_1;
            T_2_1.num = (state.num == 3)? true : false;
            if (T_2_1.num == true) {

  LINE(48);
                {
                CLUREF T_3_1;
                T_3_1.num = (ch.ch == end_quote.ch)? true : false;
                if (T_3_1.num == true) {

  LINE(50);
                    {
                    CLUREF T_4_1;
                    CLUREF T_4_2;
                    T_4_1.num = i.num - mark.num;
                     if ((T_4_1.num >= 0 && i.num < 0 && (-mark.num) < 0) ||
                         (T_4_1.num <= 0 && i.num > 0 && (-mark.num) > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    err = stringOPsubstr(s, mark, T_4_1, &T_4_2);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_2.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_2);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(51);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(52);
                    {
                    state.num = 2;
                    }
                    }
                    }/* end if */

  LINE(54);
                continue;
                }
                }/* end if */

  LINE(56);
            {
            CLUREF T_2_1;
            T_2_1.num = (ch.ch == comment_char.ch)? true : false;
            if (T_2_1.num == true) {
                goto end_inline_for_1;
                }
                }/* end if */

  LINE(58);
            {
                {CLUREF T_2_1;
                CLUREF T_2_2;
                CLUREF T_2_3;
                err = stringOPindexc(ch, fill_chars, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                T_2_2.num = (T_2_1.num == 0)? true : false;
                T_2_3.num = T_2_2.num ^ 1;
                fillc.num = T_2_3.num;
                }
                }

  LINE(59);
            {
                {CLUREF T_2_1;
                CLUREF T_2_2;
                CLUREF T_2_3;
                err = stringOPindexc(ch, sep_chars, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                T_2_2.num = (T_2_1.num == 0)? true : false;
                T_2_3.num = T_2_2.num ^ 1;
                sepc.num = T_2_3.num;
                }
                }

  LINE(60);
            {
                {CLUREF T_2_1;
                err = stringOPindexc(ch, beginq, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                qix.num = T_2_1.num;
                }
                }

  LINE(61);
            {
                {CLUREF T_2_1;
                CLUREF T_2_2;
                T_2_1.num = (qix.num == 0)? true : false;
                T_2_2.num = T_2_1.num ^ 1;
                bq.num = T_2_2.num;
                }
                }

  LINE(62);
            {
            if (bq.num == true) {
                {
                CLUREF T_3_1;
                err = stringOPfetch(endq, qix, &T_3_1);
                if (err != ERR_ok) goto ex_0;
                end_quote.num = T_3_1.num;
                }
                }
                }/* end if */

  LINE(63);
            {
                {CLUREF T_2_1;
                CLUREF T_2_2;
                CLUREF T_2_3;
                err = boolOPor(fillc, sepc, &T_2_1);
                if (err != ERR_ok) goto ex_0;
                err = boolOPor(T_2_1, bq, &T_2_2);
                if (err != ERR_ok) goto ex_0;
                T_2_3.num = T_2_2.num ^ 1;
                textc.num = T_2_3.num;
                }
                }

  LINE(65);
            {
            CLUREF T_2_1;
            T_2_1.num = (state.num == 2)? true : false;
            if (T_2_1.num == true) {

  LINE(66);
                {
                if (textc.num == true) {

  LINE(67);
                    {
                    state.num = 1;
                    }

  LINE(68);
                    {
                    mark.num = i.num;
                    }
                    }
                else {
                if (fillc.num == true) {

  LINE(70);
                    {
                    state.num = 0;
                    }
                    }
                else {
                if (bq.num == true) {

  LINE(72);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(73);
                    {
                    state.num = 3;
                    }

  LINE(74);
                    {
                    CLUREF T_4_1;
                    T_4_1.num = i.num + 1;
                     if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                         (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    mark.num = T_4_1.num;
                    }
                    }
                else {

  LINE(76);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }
                    }}}}/* end if */
                }
            else {
            CLUREF T_2_2;
            T_2_2.num = (state.num == 0)? true : false;
            if (T_2_2.num == true) {

  LINE(79);
                {
                if (textc.num == true) {

  LINE(80);
                    {
                    mark.num = i.num;
                    }

  LINE(81);
                    {
                    state.num = 1;
                    }
                    }
                else {
                if (sepc.num == true) {

  LINE(83);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(84);
                    {
                    state.num = 2;
                    }
                    }
                else {
                if (bq.num == true) {

  LINE(86);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(87);
                    {
                    state.num = 3;
                    }

  LINE(88);
                    {
                    CLUREF T_4_1;
                    T_4_1.num = i.num + 1;
                     if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                         (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    mark.num = T_4_1.num;
                    }
                    }
                    }}}/* end if */
                }
            else {
            CLUREF T_2_3;
            CLUREF T_2_4;
            CLUREF T_2_5;
            T_2_4.num = (state.num == 1)? true : false;
            T_2_3.num = T_2_4.num;
            if (T_2_4.num) {
                T_2_5.num = textc.num ^ 1;
                T_2_3.num = T_2_5.num;
            }
            if (T_2_3.num == true) {

  LINE(91);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                T_3_1.num = i.num - mark.num;
                 if ((T_3_1.num >= 0 && i.num < 0 && (-mark.num) < 0) ||
                     (T_3_1.num <= 0 && i.num > 0 && (-mark.num) > 0)) {
                    err = ERR_overflow;
                    goto ex_0;}
                err = stringOPsubstr(s, mark, T_3_1, &T_3_2);
                if (err != ERR_ok) goto ex_0;
                {
                if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                    ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_3_2.num;
                    ps.array->ext_size++; ps.array->ext_high++;}
                else {
                    err = arrayOPaddh(ps, T_3_2);
                    if (err != ERR_ok) goto ex_0;}
                }
                }

  LINE(92);
                {
                if (fillc.num == true) {
                    {
                    state.num = 0;
                    }
                    }
                else {
                if (sepc.num == true) {

  LINE(93);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(94);
                    {
                    state.num = 2;
                    }
                    }
                else {
                if (bq.num == true) {

  LINE(96);
                    {
                    CLUREF T_4_1;
                    err = stringOPsubstr(s, i, CLU_1, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
                        ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_4_1.num;
                        ps.array->ext_size++; ps.array->ext_high++;}
                    else {
                        err = arrayOPaddh(ps, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(97);
                    {
                    state.num = 3;
                    }

  LINE(98);
                    {
                    CLUREF T_4_1;
                    T_4_1.num = i.num + 1;
                     if ((T_4_1.num > 0 && i.num < 0 && 1 < 0) ||
                         (T_4_1.num < 0 && i.num > 0 && 1 > 0)) {
                        err = ERR_overflow;
                        goto ex_0;}
                    mark.num = T_4_1.num;
                    }
                    }
                    }}}/* end if */
                }
                }}}/* end if */
        }
    }
    end_inline_for_1:;

  LINE(102);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_2.num = (state.num == 1)? true : false;
    T_1_1.num = T_1_2.num;
    if (!T_1_2.num) {
        T_1_3.num = (state.num == 3)? true : false;
        T_1_1.num = T_1_3.num;
    }
    if (T_1_1.num == true) {

  LINE(103);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = i.num + 1;
         if ((T_2_1.num > 0 && i.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_2_2.num = T_2_1.num - mark.num;
         if ((T_2_2.num >= 0 && T_2_1.num < 0 && (-mark.num) < 0) ||
             (T_2_2.num <= 0 && T_2_1.num > 0 && (-mark.num) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPsubstr(s, mark, T_2_2, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        {
        if ((ps.array->int_low + ps.array->ext_size + 1) < ps.array->int_size) {
            ps.array->store->data[ps.array->int_low + ps.array->ext_size] = T_2_3.num;
            ps.array->ext_size++; ps.array->ext_high++;}
        else {
            err = arrayOPaddh(ps, T_2_3);
            if (err != ERR_ok) goto ex_0;}
        }
        }
        }
        }/* end if */

  LINE(105);
    {
    CLUREF T_1_1;
    T_1_1.num = (state.num == 3)? true : false;
    if (T_1_1.num == true) {

  LINE(106);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        elist[0] = ps;
        err = stringOPindexc(end_quote, endq, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        err = stringOPfetch(beginq, T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        elist[1] = T_2_2;
        {signal (ERR_unterminated_quote);}}
        }
        }/* end if */

  LINE(108);
    {
    {
    ret_1->num = ps.num;
    }
    {signal (ERR_ok);}}
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: elist[0] = no_return_values_STRING;
        {signal(ERR_failure);}
}

/**** END PROCEDURE lex_scan ****/

