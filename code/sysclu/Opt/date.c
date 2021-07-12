
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

/**** BEGIN CLUSTER date ****/

extern errcode intOPlt();
extern errcode intOPgt();
extern errcode structOPget_1();
extern errcode structOPget_4();
extern errcode structOPget_6();
extern errcode structOPget_2();
extern errcode structOPget_3();
extern errcode structOPget_5();
extern errcode stringOPconcat();
extern errcode dateOPunparse_date();
extern errcode dateOPunparse_time();
extern errcode intOPunparse();
extern errcode sequenceOPfetch();
extern errcode structOPequal();
extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode intOPle();
extern errcode dateOPlt();
extern errcode dateOPle();
extern errcode pstreamOPtext();
extern errcode dateOPunparse();
extern errcode intOPencode();
extern errcode dateOPcreate();
extern errcode intOPdecode();
extern errcode structOP_gcd();
extern struct OPS *int_ops;
struct OPS *struct_day_hour_minute_month_second_year_ops __CLU_COMMON;
static CLUREF STR__040;
static CLUREF STR_January;
static CLUREF STR_February;
static CLUREF STR_March;
static CLUREF STR_April;
static CLUREF STR_May;
static CLUREF STR_June;
static CLUREF STR_July;
static CLUREF STR_August;
static CLUREF STR_September;
static CLUREF STR_October;
static CLUREF STR_November;
static CLUREF STR_December;
static CLUREF STR_0;
static CLUREF STR__072;
static CLUREF STR_bad_040format;
static int date_own_init = 0;
const OWN_req date_ownreqs = { 0, 0 };

errcode
date_own_init_proc(void)
{
    errcode err;
    enter_own_init_proc();
    if (date_own_init == 0) {
        add_selector_info("day", 0, int_ops);
        add_selector_info("hour", 1, int_ops);
        add_selector_info("minute", 2, int_ops);
        add_selector_info("month", 3, int_ops);
        add_selector_info("second", 4, int_ops);
        add_selector_info("year", 5, int_ops);
        find_selector_ops("struct", 6, &(struct_day_hour_minute_month_second_year_ops));
        stringOPcons(" ", CLU_1, CLUREF_make_num(1), &STR__040);
        stringOPcons("January", CLU_1, CLUREF_make_num(7), &STR_January);
        stringOPcons("February", CLU_1, CLUREF_make_num(8), &STR_February);
        stringOPcons("March", CLU_1, CLUREF_make_num(5), &STR_March);
        stringOPcons("April", CLU_1, CLUREF_make_num(5), &STR_April);
        stringOPcons("May", CLU_1, CLUREF_make_num(3), &STR_May);
        stringOPcons("June", CLU_1, CLUREF_make_num(4), &STR_June);
        stringOPcons("July", CLU_1, CLUREF_make_num(4), &STR_July);
        stringOPcons("August", CLU_1, CLUREF_make_num(6), &STR_August);
        stringOPcons("September", CLU_1, CLUREF_make_num(9), &STR_September);
        stringOPcons("October", CLU_1, CLUREF_make_num(7), &STR_October);
        stringOPcons("November", CLU_1, CLUREF_make_num(8), &STR_November);
        stringOPcons("December", CLU_1, CLUREF_make_num(8), &STR_December);
        stringOPcons("0", CLU_1, CLUREF_make_num(1), &STR_0);
        stringOPcons(":", CLU_1, CLUREF_make_num(1), &STR__072);
        stringOPcons("bad format", CLU_1, CLUREF_make_num(10), &STR_bad_040format);
        date_own_init = 1;
        signal(ERR_ok);
      ex_0:
        pclu_unhandled(err);
        signal(ERR_failure);
    }
    signal(ERR_ok);
}


/**** BEGIN PROCEDURE create ****/


errcode
dateOPcreate(CLUREF day, CLUREF month, CLUREF year, CLUREF hour, CLUREF minute, CLUREF second, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(28);

  LINE(30);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    CLUREF T_1_8;
    CLUREF T_1_9;
    CLUREF T_1_10;
    CLUREF T_1_11;
    CLUREF T_1_12;
    CLUREF T_1_13;
    CLUREF T_1_14;
    CLUREF T_1_15;
    CLUREF T_1_16;
    CLUREF T_1_17;
    CLUREF T_1_18;
    CLUREF T_1_19;
    CLUREF T_1_20;
    CLUREF T_1_21;
    CLUREF T_1_22;
    CLUREF T_1_23;
    T_1_11.num = (day.num < 1)? true : false;
    T_1_10.num = T_1_11.num;
    if (!T_1_11.num) {
        T_1_12.num = (day.num > 31)? true : false;
        T_1_10.num = T_1_12.num;
    }
    T_1_9.num = T_1_10.num;
    if (!T_1_10.num) {
        T_1_13.num = (month.num < 1)? true : false;
        T_1_9.num = T_1_13.num;
    }
    T_1_8.num = T_1_9.num;
    if (!T_1_9.num) {
        T_1_14.num = (month.num > 12)? true : false;
        T_1_8.num = T_1_14.num;
    }
    T_1_7.num = T_1_8.num;
    if (!T_1_8.num) {
        T_1_15.num = (year.num < 1)? true : false;
        T_1_7.num = T_1_15.num;
    }
    T_1_6.num = T_1_7.num;
    if (!T_1_7.num) {
        T_1_16.num = (hour.num < 0)? true : false;
        T_1_6.num = T_1_16.num;
    }
    T_1_5.num = T_1_6.num;
    if (!T_1_6.num) {
        T_1_17.num = (hour.num > 23)? true : false;
        T_1_5.num = T_1_17.num;
    }
    T_1_4.num = T_1_5.num;
    if (!T_1_5.num) {
        T_1_18.num = (minute.num < 0)? true : false;
        T_1_4.num = T_1_18.num;
    }
    T_1_3.num = T_1_4.num;
    if (!T_1_4.num) {
        T_1_19.num = 59;
        T_1_20.num = (minute.num > T_1_19.num)? true : false;
        T_1_3.num = T_1_20.num;
    }
    T_1_2.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_21.num = (second.num < 0)? true : false;
        T_1_2.num = T_1_21.num;
    }
    T_1_1.num = T_1_2.num;
    if (!T_1_2.num) {
        T_1_22.num = 59;
        T_1_23.num = (second.num > T_1_22.num)? true : false;
        T_1_1.num = T_1_23.num;
    }
    if (T_1_1.num == true) {

  LINE(36);
        {
        {signal (ERR_bad_format);}}
        }
        }/* end if */

  LINE(37);
    {
    {
    CLUREF T_1_1;
    RecordAlloc(6, T_1_1);
    T_1_1.vec->data[0] = day.num;
    T_1_1.vec->data[3] = month.num;
    T_1_1.vec->data[5] = year.num;
    T_1_1.vec->data[1] = hour.num;
    T_1_1.vec->data[2] = minute.num;
    T_1_1.vec->data[4] = second.num;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE create ****/


/**** BEGIN PROCEDURE get_day ****/


errcode
dateOPget_day(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(41);

  LINE(42);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[0];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_day ****/


/**** BEGIN PROCEDURE get_month ****/


errcode
dateOPget_month(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(45);

  LINE(46);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[3];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_month ****/


/**** BEGIN PROCEDURE get_year ****/


errcode
dateOPget_year(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(49);

  LINE(50);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[5];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_year ****/


/**** BEGIN PROCEDURE get_hour ****/


errcode
dateOPget_hour(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(53);

  LINE(54);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[1];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_hour ****/


/**** BEGIN PROCEDURE get_minute ****/


errcode
dateOPget_minute(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(57);

  LINE(58);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[2];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_minute ****/


/**** BEGIN PROCEDURE get_second ****/


errcode
dateOPget_second(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(61);

  LINE(62);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[4];
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_second ****/


/**** BEGIN PROCEDURE get_all ****/


errcode
dateOPget_all(CLUREF d, CLUREF *ret_1, CLUREF *ret_2, CLUREF *ret_3, CLUREF *ret_4, CLUREF *ret_5, CLUREF *ret_6)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(65);

  LINE(66);
    {
    {
    CLUREF T_1_1;
    T_1_1.num = d.vec->data[0];
    ret_1->num = T_1_1.num;
    }
    {
    CLUREF T_1_2;
    T_1_2.num = d.vec->data[3];
    ret_2->num = T_1_2.num;
    }
    {
    CLUREF T_1_3;
    T_1_3.num = d.vec->data[5];
    ret_3->num = T_1_3.num;
    }
    {
    CLUREF T_1_4;
    T_1_4.num = d.vec->data[1];
    ret_4->num = T_1_4.num;
    }
    {
    CLUREF T_1_5;
    T_1_5.num = d.vec->data[2];
    ret_5->num = T_1_5.num;
    }
    {
    CLUREF T_1_6;
    T_1_6.num = d.vec->data[4];
    ret_6->num = T_1_6.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE get_all ****/


/**** BEGIN PROCEDURE unparse ****/

static int dateOPunparse_own_init = 0;

errcode
dateOPunparse(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (dateOPunparse_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPunparse_own_init = 1;
    }
    enter_proc(69);

  LINE(70);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = dateOPunparse_date(d, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_1, STR__040, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    err = dateOPunparse_time(d, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_2, T_1_3, &T_1_4);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_4.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE unparse ****/


/**** BEGIN PROCEDURE unparse_date ****/

static int dateOPunparse_date_own_init = 0;

errcode
dateOPunparse_date(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (dateOPunparse_date_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPunparse_date_own_init = 1;
    }
    enter_proc(73);

  LINE(78);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    CLUREF T_1_6;
    CLUREF T_1_7;
    CLUREF T_1_8;
    CLUREF T_1_9;
    CLUREF T_1_10;
    CLUREF T_1_11;
    T_1_1.num = d.vec->data[0];
    err = intOPunparse(T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_2, STR__040, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    sequenceOPnew2(CLU_12, &T_1_4);
    T_1_4.vec->data[0] = STR_January.num;
    T_1_4.vec->data[1] = STR_February.num;
    T_1_4.vec->data[2] = STR_March.num;
    T_1_4.vec->data[3] = STR_April.num;
    T_1_4.vec->data[4] = STR_May.num;
    T_1_4.vec->data[5] = STR_June.num;
    T_1_4.vec->data[6] = STR_July.num;
    T_1_4.vec->data[7] = STR_August.num;
    T_1_4.vec->data[8] = STR_September.num;
    T_1_4.vec->data[9] = STR_October.num;
    T_1_4.vec->data[10] = STR_November.num;
    T_1_4.vec->data[11] = STR_December.num;
    T_1_5.num = d.vec->data[3];
    if (T_1_5.num < 1 || T_1_5.num > T_1_4.vec->size ) {
        err = ERR_bounds;
        goto ex_0;}
    T_1_6.num = T_1_4.vec->data[T_1_5.num - 1];
    err = stringOPconcat(T_1_3, T_1_6, &T_1_7);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_7, STR__040, &T_1_8);
    if (err != ERR_ok) goto ex_0;
    T_1_9.num = d.vec->data[5];
    err = intOPunparse(T_1_9, &T_1_10);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_8, T_1_10, &T_1_11);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_11.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE unparse_date ****/


/**** BEGIN PROCEDURE unparse_time ****/

static int dateOPunparse_time_own_init = 0;

errcode
dateOPunparse_time(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    CLUREF hour;
    CLUREF minute;
    CLUREF second;
    if (dateOPunparse_time_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPunparse_time_own_init = 1;
    }
    enter_proc(83);

  LINE(84);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = d.vec->data[1];
        err = intOPunparse(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        hour.num = T_1_2.num;
        }
        }

  LINE(85);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = d.vec->data[2];
        err = intOPunparse(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        minute.num = T_1_2.num;
        }
        }

  LINE(86);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = d.vec->data[4];
        err = intOPunparse(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        second.num = T_1_2.num;
        }
        }

  LINE(87);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = d.vec->data[1];
    T_1_2.num = (T_1_1.num < 10)? true : false;
    if (T_1_2.num == true) {

  LINE(88);
        {
        CLUREF T_2_1;
        err = stringOPconcat(STR_0, hour, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        hour.num = T_2_1.num;
        }
        }
        }/* end if */

  LINE(89);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = d.vec->data[2];
    T_1_2.num = (T_1_1.num < 10)? true : false;
    if (T_1_2.num == true) {

  LINE(90);
        {
        CLUREF T_2_1;
        err = stringOPconcat(STR_0, minute, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        minute.num = T_2_1.num;
        }
        }
        }/* end if */

  LINE(91);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = d.vec->data[4];
    T_1_2.num = (T_1_1.num < 10)? true : false;
    if (T_1_2.num == true) {

  LINE(92);
        {
        CLUREF T_2_1;
        err = stringOPconcat(STR_0, second, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        second.num = T_2_1.num;
        }
        }
        }/* end if */

  LINE(93);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = stringOPconcat(hour, STR__072, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_1, minute, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_2, STR__072, &T_1_3);
    if (err != ERR_ok) goto ex_0;
    err = stringOPconcat(T_1_3, second, &T_1_4);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_4.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE unparse_time ****/


/**** BEGIN PROCEDURE equal ****/

struct OPS *struct_day_hour_minute_month_second_year_ops __CLU_COMMON;
static int dateOPequal_own_init = 0;

errcode
dateOPequal(CLUREF date1, CLUREF date2, CLUREF *ret_1)
{
    errcode err;
    if (dateOPequal_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPequal_own_init = 1;
    }
    enter_proc(96);

  LINE(97);
    {

  LINE(98);
        {
        {
        CLUREF T_2_1;
        generic_CLU_proc.type_owns = 0;
        generic_CLU_proc.op_owns = struct_day_hour_minute_month_second_year_ops->entry[0].fcn->op_owns;
        generic_CLU_proc.proc = structOPequal;
        CUR_PROC_VAR.proc = &generic_CLU_proc;
        err = structOPequal(date1, date2, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        ret_1->num = T_2_1.num;
        }
        {signal (ERR_ok);}}
        }

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE equal ****/


/**** BEGIN PROCEDURE similar ****/

struct OPS *struct_day_hour_minute_month_second_year_ops __CLU_COMMON;
static int dateOPsimilar_own_init = 0;

errcode
dateOPsimilar(CLUREF date1, CLUREF date2, CLUREF *ret_1)
{
    errcode err;
    if (dateOPsimilar_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPsimilar_own_init = 1;
    }
    enter_proc(102);

  LINE(103);
    {
    {
    CLUREF T_1_1;
    generic_CLU_proc.type_owns = 0;
    generic_CLU_proc.op_owns = struct_day_hour_minute_month_second_year_ops->entry[0].fcn->op_owns;
    generic_CLU_proc.proc = structOPequal;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = structOPequal(date1, date2, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE similar ****/


/**** BEGIN PROCEDURE copy ****/


errcode
dateOPcopy(CLUREF d, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(106);

  LINE(107);
    {
    {
    ret_1->num = d.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE copy ****/


/**** BEGIN PROCEDURE lt ****/


errcode
dateOPlt(CLUREF d1, CLUREF d2, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(110);

  LINE(111);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[5];
    T_1_2.num = d2.vec->data[5];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(112);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[5];
        T_2_2.num = d2.vec->data[5];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(113);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[3];
    T_1_2.num = d2.vec->data[3];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(114);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[3];
        T_2_2.num = d2.vec->data[3];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(115);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[0];
    T_1_2.num = d2.vec->data[0];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(116);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[0];
        T_2_2.num = d2.vec->data[0];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(117);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[1];
    T_1_2.num = d2.vec->data[1];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(118);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[1];
        T_2_2.num = d2.vec->data[1];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(119);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[2];
    T_1_2.num = d2.vec->data[2];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(120);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[2];
        T_2_2.num = d2.vec->data[2];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(121);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = d1.vec->data[4];
    T_1_2.num = d2.vec->data[4];
    T_1_3.num = (T_1_1.num < T_1_2.num)? true : false;
    ret_1->num = T_1_3.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE lt ****/


/**** BEGIN PROCEDURE le ****/


errcode
dateOPle(CLUREF d1, CLUREF d2, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(124);

  LINE(125);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[5];
    T_1_2.num = d2.vec->data[5];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(126);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[5];
        T_2_2.num = d2.vec->data[5];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(127);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[3];
    T_1_2.num = d2.vec->data[3];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(128);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[3];
        T_2_2.num = d2.vec->data[3];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(129);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[0];
    T_1_2.num = d2.vec->data[0];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(130);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[0];
        T_2_2.num = d2.vec->data[0];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(131);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[1];
    T_1_2.num = d2.vec->data[1];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(132);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[1];
        T_2_2.num = d2.vec->data[1];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(133);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = d1.vec->data[2];
    T_1_2.num = d2.vec->data[2];
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(134);
        {
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_1.num = d1.vec->data[2];
        T_2_2.num = d2.vec->data[2];
        T_2_3.num = (T_2_1.num < T_2_2.num)? true : false;
        ret_1->num = T_2_3.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(135);
    {
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    T_1_1.num = d1.vec->data[4];
    T_1_2.num = d2.vec->data[4];
    T_1_3.num = (T_1_1.num <= T_1_2.num)? true : false;
    ret_1->num = T_1_3.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE le ****/


/**** BEGIN PROCEDURE gt ****/


errcode
dateOPgt(CLUREF d1, CLUREF d2, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(138);

  LINE(139);
    {
    {
    CLUREF T_1_1;
    err = dateOPlt(d2, d1, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE gt ****/


/**** BEGIN PROCEDURE ge ****/


errcode
dateOPge(CLUREF d1, CLUREF d2, CLUREF *ret_1)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(142);

  LINE(143);
    {
    {
    CLUREF T_1_1;
    err = dateOPle(d2, d1, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE ge ****/


/**** BEGIN PROCEDURE print ****/


errcode
dateOPprint(CLUREF d, CLUREF ps)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(146);

  LINE(147);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = dateOPunparse(d, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = pstreamOPtext(ps, T_1_1, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    }

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE print ****/


/**** BEGIN PROCEDURE encode ****/


errcode
dateOPencode(CLUREF d, CLUREF ist)
{
    errcode err;
    if (date_own_init == 0) {
        err = date_own_init_proc();
        if (err != ERR_ok) goto ex_0;
    }
    enter_proc(150);

  LINE(151);
    {

  LINE(152);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[0];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(153);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[3];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(154);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[5];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(155);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[1];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(156);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[2];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(157);
        {
        CLUREF T_3_1;
        T_3_1.num = d.vec->data[4];
        err = intOPencode(T_3_1, ist);
        if (err != ERR_ok) goto ex_1;
        }
        }
    goto end_1;
    ex_1:
        if (err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_0;}
    end_1:;

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE encode ****/


/**** BEGIN PROCEDURE decode ****/

static int dateOPdecode_own_init = 0;

errcode
dateOPdecode(CLUREF ist, CLUREF *ret_1)
{
    errcode err;
    if (dateOPdecode_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOPdecode_own_init = 1;
    }
    enter_proc(161);

  LINE(163);
    {
    {
    CLUREF T_3_1;
    CLUREF T_3_2;
    CLUREF T_3_3;
    CLUREF T_3_4;
    CLUREF T_3_5;
    CLUREF T_3_6;
    CLUREF T_3_7;
    err = intOPdecode(ist, &T_3_1);
    if (err != ERR_ok) goto ex_2;
    err = intOPdecode(ist, &T_3_2);
    if (err != ERR_ok) goto ex_2;
    err = intOPdecode(ist, &T_3_3);
    if (err != ERR_ok) goto ex_2;
    err = intOPdecode(ist, &T_3_4);
    if (err != ERR_ok) goto ex_2;
    err = intOPdecode(ist, &T_3_5);
    if (err != ERR_ok) goto ex_2;
    err = intOPdecode(ist, &T_3_6);
    if (err != ERR_ok) goto ex_2;
    err = dateOPcreate(T_3_1, T_3_2, T_3_3, T_3_4, T_3_5, T_3_6, &T_3_7);
    if (err != ERR_ok) goto ex_2;
    ret_1->num = T_3_7.num;
    }
    {signal (ERR_ok);}}
    goto end_2;
    ex_2:
        if (err == ERR_end_of_file) {signal(ERR_end_of_file);}
        else if (err == ERR_not_possible) {signal(ERR_not_possible);}
        else {
            goto ex_1;}
    end_2:;
        goto end_1;
        ex_1:
            if ((err == ERR_bad_format)) {

  LINE(166);
                {
                elist[0] = STR_bad_040format;
                {signal (ERR_not_possible);}}
            }
            else {
                goto ex_0;
            }
        end_1:;

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE decode ****/


/**** BEGIN PROCEDURE _gcd ****/

struct OPS *struct_day_hour_minute_month_second_year_ops __CLU_COMMON;
static int dateOP_gcd_own_init = 0;

errcode
dateOP_gcd(CLUREF d, CLUREF tab, CLUREF *ret_1)
{
    errcode err;
    if (dateOP_gcd_own_init == 0) {
        if (date_own_init == 0) {
            err = date_own_init_proc();
            if (err != ERR_ok) goto ex_0;
        }
        dateOP_gcd_own_init = 1;
    }
    enter_proc(169);

  LINE(170);
    {
    {
    CLUREF T_1_1;
    generic_CLU_proc.type_owns = 0;
    generic_CLU_proc.op_owns = struct_day_hour_minute_month_second_year_ops->entry[6].fcn->op_owns;
    generic_CLU_proc.proc = structOP_gcd;
    CUR_PROC_VAR.proc = &generic_CLU_proc;
    err = structOP_gcd(d, tab, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
    }
    {signal (ERR_ok);}}

    goto end_0;
  ex_0:
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    elist[0] = no_return_values_STRING;
    signal(ERR_failure);
}

/**** END PROCEDURE _gcd ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[22];
} date_OPS;

static CLU_proc date_oe__gcd = { .proc = dateOP_gcd };
static CLU_proc date_oe_copy = { .proc = dateOPcopy };
static CLU_proc date_oe_create = { .proc = dateOPcreate };
static CLU_proc date_oe_decode = { .proc = dateOPdecode };
static CLU_proc date_oe_encode = { .proc = dateOPencode };
static CLU_proc date_oe_equal = { .proc = dateOPequal };
static CLU_proc date_oe_ge = { .proc = dateOPge };
static CLU_proc date_oe_get_all = { .proc = dateOPget_all };
static CLU_proc date_oe_get_day = { .proc = dateOPget_day };
static CLU_proc date_oe_get_hour = { .proc = dateOPget_hour };
static CLU_proc date_oe_get_minute = { .proc = dateOPget_minute };
static CLU_proc date_oe_get_month = { .proc = dateOPget_month };
static CLU_proc date_oe_get_second = { .proc = dateOPget_second };
static CLU_proc date_oe_get_year = { .proc = dateOPget_year };
static CLU_proc date_oe_gt = { .proc = dateOPgt };
static CLU_proc date_oe_le = { .proc = dateOPle };
static CLU_proc date_oe_lt = { .proc = dateOPlt };
static CLU_proc date_oe_print = { .proc = dateOPprint };
static CLU_proc date_oe_similar = { .proc = dateOPsimilar };
static CLU_proc date_oe_unparse = { .proc = dateOPunparse };
static CLU_proc date_oe_unparse_date = { .proc = dateOPunparse_date };
static CLU_proc date_oe_unparse_time = { .proc = dateOPunparse_time };

static date_OPS date_ops_actual = {22, (OWNPTR)&date_own_init, (OWNPTR)&date_own_init, {
    {&date_oe__gcd, "_gcd"},
    {&date_oe_copy, "copy"},
    {&date_oe_create, "create"},
    {&date_oe_decode, "decode"},
    {&date_oe_encode, "encode"},
    {&date_oe_equal, "equal"},
    {&date_oe_ge, "ge"},
    {&date_oe_get_all, "get_all"},
    {&date_oe_get_day, "get_day"},
    {&date_oe_get_hour, "get_hour"},
    {&date_oe_get_minute, "get_minute"},
    {&date_oe_get_month, "get_month"},
    {&date_oe_get_second, "get_second"},
    {&date_oe_get_year, "get_year"},
    {&date_oe_gt, "gt"},
    {&date_oe_le, "le"},
    {&date_oe_lt, "lt"},
    {&date_oe_print, "print"},
    {&date_oe_similar, "similar"},
    {&date_oe_unparse, "unparse"},
    {&date_oe_unparse_date, "unparse_date"},
    {&date_oe_unparse_time, "unparse_time"}}};

struct OPS *date_ops = (struct OPS *)&date_ops_actual;

/**** END CLUSTER date ****/
