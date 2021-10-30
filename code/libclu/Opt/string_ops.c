
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE padl ****/

extern errcode padlc();

errcode
padl(CLUREF s, CLUREF w, CLUREF *ret_1)
{
    errcode err;
    enter_proc(20);

  LINE(21);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.ch = ' ';
    err = padlc(s, w, T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_2.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE padl ****/



/**** BEGIN PROCEDURE padr ****/

extern errcode padrc();

errcode
padr(CLUREF s, CLUREF w, CLUREF *ret_1)
{
    errcode err;
    enter_proc(24);

  LINE(25);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.ch = ' ';
    err = padrc(s, w, T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_2.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE padr ****/



/**** BEGIN PROCEDURE padlc ****/

extern errcode stringOPc2s();
extern errcode intOPlt();
extern errcode stringOPsize();
extern errcode stringOPconcat();

errcode
padlc(CLUREF s, CLUREF w, CLUREF c, CLUREF *ret_1)
{
    errcode err;
    CLUREF cs;
    enter_proc(28);

  LINE(29);
    {
        {CLUREF T_1_1;
        err = stringOPc2s(c, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        cs.num = T_1_1.num;
        }
        }

  LINE(30);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_2.num = (T_1_1.num < w.num)? true : false;
        if (T_1_2.num != true) { break; }

  LINE(31);
        {
        CLUREF T_2_1;
        err = stringOPconcat(cs, s, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_1.num;
        }
        }
        end_while_1:
        __CLU_END_LABEL;

  LINE(33);
    {
    {
    ret_1->num = s.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE padlc ****/



/**** BEGIN PROCEDURE padrc ****/

extern errcode stringOPappend();

errcode
padrc(CLUREF s, CLUREF w, CLUREF c, CLUREF *ret_1)
{
    errcode err;
    enter_proc(36);

  LINE(37);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_2.num = (T_1_1.num < w.num)? true : false;
        if (T_1_2.num != true) { break; }

  LINE(38);
        {
        CLUREF T_2_1;
        err = stringOPappend(s, c, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_1.num;
        }
        }
        end_while_1:
        __CLU_END_LABEL;

  LINE(40);
    {
    {
    ret_1->num = s.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE padrc ****/



/**** BEGIN PROCEDURE upper ****/

extern errcode charOPge();
extern errcode charOPle();
extern errcode charOPi2c();
extern errcode intOPsub();
extern errcode charOPc2i();

errcode
upper(CLUREF c, CLUREF *ret_1)
{
    errcode err;
    enter_proc(43);

  LINE(44);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.ch = 'a';
    err = charOPge(c, T_1_2, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    T_1_1.num = T_1_3.num;
    if (T_1_3.num) {
        T_1_4.ch = 'z';
        err = charOPle(c, T_1_4, &T_1_5);
        if (err != ERR_ok) goto ex_0;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = (long)(c.ch & 0xff);
        T_2_2.num = T_2_1.num - 32;
         if ((T_2_2.num >= 0 && T_2_1.num < 0 && (-32) < 0) ||
             (T_2_2.num <= 0 && T_2_1.num > 0 && (-32) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = charOPi2c(T_2_2, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
    else {

  LINE(45);
        {
        {
        ret_1->num = c.num;
        }
        {signal (ERR_ok);}}
        }}/* end if */

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

/**** END PROCEDURE upper ****/



/**** BEGIN PROCEDURE lower ****/

extern errcode intOPadd();

errcode
lower(CLUREF c, CLUREF *ret_1)
{
    errcode err;
    enter_proc(49);

  LINE(50);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.ch = 'A';
    err = charOPge(c, T_1_2, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    T_1_1.num = T_1_3.num;
    if (T_1_3.num) {
        T_1_4.ch = 'Z';
        err = charOPle(c, T_1_4, &T_1_5);
        if (err != ERR_ok) goto ex_0;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = (long)(c.ch & 0xff);
        T_2_2.num = T_2_1.num + 32;
         if ((T_2_2.num > 0 && T_2_1.num < 0 && 32 < 0) ||
             (T_2_2.num < 0 && T_2_1.num > 0 && 32 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = charOPi2c(T_2_2, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
    else {

  LINE(51);
        {
        {
        ret_1->num = c.num;
        }
        {signal (ERR_ok);}}
        }}/* end if */

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

/**** END PROCEDURE lower ****/



/**** BEGIN PROCEDURE supper ****/

extern errcode stringOPs2ac();
extern errcode arrayOPindexes();
extern errcode arrayOPstore();
extern errcode upper();
extern errcode arrayOPfetch();
extern errcode stringOPac2s();

errcode
supper(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF a;
    CLUREF i;
    enter_proc(55);

  LINE(57);
    {
        {CLUREF T_1_1;
        err = stringOPs2ac(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        a.num = T_1_1.num;
        }
        }

  LINE(58);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
        T_1_2.num = a.array->ext_high;
        for (T_1_1.num = a.array->ext_low; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            i.num = T_1_1.num;

  LINE(59);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            if (i.num < a.array->ext_low || i.num > a.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_1.num = a.array->store->data[i.num - a.array->ext_low + a.array->int_low];
            err = upper(T_2_1, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            {
            if (i.num < a.array->ext_low || i.num > a.array->ext_high) {
                err = ERR_bounds;
                goto ex_0;}
            a.array->store->data[i.num + a.array->int_low - a.array->ext_low] = T_2_2.num;
            }
            }
        }
    }
    end_inline_for_1:
    __CLU_END_LABEL;

  LINE(61);
    {
    {
    CLUREF T_1_1;
    err = stringOPac2s(a, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE supper ****/



/**** BEGIN PROCEDURE slower ****/

extern errcode lower();

errcode
slower(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF a;
    CLUREF i;
    enter_proc(64);

  LINE(66);
    {
        {CLUREF T_1_1;
        err = stringOPs2ac(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        a.num = T_1_1.num;
        }
        }

  LINE(67);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
        T_1_2.num = a.array->ext_high;
        for (T_1_1.num = a.array->ext_low; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            i.num = T_1_1.num;

  LINE(68);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            if (i.num < a.array->ext_low || i.num > a.array->ext_high ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_1.num = a.array->store->data[i.num - a.array->ext_low + a.array->int_low];
            err = lower(T_2_1, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            {
            if (i.num < a.array->ext_low || i.num > a.array->ext_high) {
                err = ERR_bounds;
                goto ex_0;}
            a.array->store->data[i.num + a.array->int_low - a.array->ext_low] = T_2_2.num;
            }
            }
        }
    }
    end_inline_for_1:
    __CLU_END_LABEL;

  LINE(70);
    {
    {
    CLUREF T_1_1;
    err = stringOPac2s(a, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE slower ****/



/**** BEGIN PROCEDURE verify ****/

extern errcode stringOPchars();
extern errcode intOPequal();
extern errcode stringOPindexc();
static errcode verify_IB_1();
typedef struct {
    errcode ecode2;
    errcode err;
    CLUREF c;
    CLUREF s;
    CLUREF chars;
} verify_LOCALS_t;

errcode
verify(CLUREF s, CLUREF chars, CLUREF *ret_1)
{
    verify_LOCALS_t locals;
    locals.s = s;
    locals.chars = chars;
    enter_proc(73);

  LINE(74);
    {
        locals.err = stringOPchars(locals.s, verify_IB_1, &locals, &locals.ecode2);
        if (locals.err == ERR_iterbodyreturn) {
            ret_1->num = elist[0].num;
            signal(ERR_ok);
        }
        if (locals.err == ERR_iterbodysignal) {signal(locals.ecode2);}
        if (locals.err == ERR_break) locals.err = ERR_ok;
        if (locals.err == ERR_iterbodyexit) locals.err = locals.ecode2;
        if (locals.err != ERR_ok) goto ex_0;
        }

  LINE(77);
    {
    {
    ret_1->tf = false;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (locals.err != ERR_failure)
        elist[0] = _pclu_erstr(locals.err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE verify ****/


/**** BEGIN ITERATOR BODIES for verify ****/

static errcode
verify_IB_1(CLUREF iv_1, verify_LOCALS_t *locals, errcode *iecode)
{
    locals->c.num = iv_1.num;
    enter_iter_body_proc(75);

  FB_LINE(75);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    locals->err = stringOPindexc(locals->c, locals->chars, &T_1_1);
    if (locals->err != ERR_ok) goto ex_0;
    T_1_2.num = (T_1_1.num == 0)? true : false;
    if (T_1_2.num == true) {
        {
        {
        elist[0].tf = true;
        }
        *iecode = ERR_ok;
        {signal(ERR_iterbodyreturn);}
        }
        }
        }/* end if */

    signal(ERR_ok);
  ex_0:
    __CLU_EX_HANDLER;
    *iecode = locals->err;
    signal(ERR_iterbodyexit);
  end_0:
    __CLU_END_LABEL;
    signal(ERR_ok);
}

/**** END ITERATOR BODIES for verify ****/



/**** BEGIN PROCEDURE remblank ****/

extern errcode intOPle();
extern errcode charOPequal();
extern errcode stringOPfetch();
extern errcode stringOPrest();

errcode
remblank(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF i;
    CLUREF hi;
    enter_proc(80);

  LINE(81);
    {
        {i.num = 1;
        }
        }

  LINE(82);
    {
        {CLUREF T_1_1;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        hi.num = T_1_1.num;
        }
        }

  LINE(83);
    for (;;) {
        CLUREF T_1_1;
        CLUREF T_1_2;
        CLUREF T_1_3;
        CLUREF T_1_4;
        CLUREF T_1_5;
        T_1_2.num = (i.num <= hi.num)? true : false;
        T_1_1.num = T_1_2.num;
        if (T_1_2.num) {
            err = stringOPfetch(s, i, &T_1_3);
            if (err != ERR_ok) goto ex_0;
            T_1_4.ch = ' ';
            T_1_5.num = (T_1_3.ch == T_1_4.ch)? true : false;
            T_1_1.num = T_1_5.num;
        }
        if (T_1_1.num != true) { break; }
        {
        CLUREF T_2_1;
        T_2_1.num = i.num + 1;
         if ((T_2_1.num > 0 && i.num < 0 && 1 < 0) ||
             (T_2_1.num < 0 && i.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        i.num = T_2_1.num;
        }
        }
        end_while_1:
        __CLU_END_LABEL;

  LINE(84);
    {
    {
    CLUREF T_1_1;
    err = stringOPrest(s, i, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

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

/**** END PROCEDURE remblank ****/

