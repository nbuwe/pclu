
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode stringOPsize();
extern errcode intOPle();
extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode intOPadd();

/**** BEGIN PROCEDURE _qindexc ****/

errcode _qindexc(c, s, ret_1)
CLUREF c;
CLUREF s;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF z;
    CLUREF i;
    CLUREF cc;
    enter_proc(3);

  LINE(5);
    {
        {CLUREF T_1_1;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        z.num = T_1_1.num;
        }
        }

  LINE(6);
    {
        {i.num = 1;
        }
        }

  LINE(7);
    for (;;) {
        CLUREF T_1_1;
        T_1_1.num = (i.num <= z.num)? true : false;
        if (T_1_1.num != true) { break; }

  LINE(8);
        {
            {CLUREF T_2_1;
            err = stringOPfetch(s, i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            cc.num = T_2_1.num;
            }
            }

  LINE(9);
        {
        CLUREF T_2_1;
        T_2_1.num = (cc.ch == c.ch)? true : false;
        if (T_2_1.num == true) {

  LINE(10);
            {
            {
            ret_1->num = i.num;
            }
            {signal (ERR_ok);}}
            }
        else {
        CLUREF T_2_2;
        CLUREF T_2_3;
        T_2_2.ch = '\\';
        T_2_3.num = (cc.ch == T_2_2.ch)? true : false;
        if (T_2_3.num == true) {

  LINE(12);
            {
            CLUREF T_3_1;
            T_3_1.num = i.num + 2;
             if ((T_3_1.num > 0 && i.num < 0 && 2 < 0) || 
                 (T_3_1.num < 0 && i.num > 0 && 2 > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            i.num = T_3_1.num;
            }
            }
        else {

  LINE(13);
            {
            CLUREF T_3_1;
            T_3_1.num = i.num + 1;
             if ((T_3_1.num > 0 && i.num < 0 && 1 < 0) || 
                 (T_3_1.num < 0 && i.num > 0 && 1 > 0)) {
                err = ERR_overflow;
                goto ex_0;}
            i.num = T_3_1.num;
            }
            }}}/* end if */
        }
        end_while_1:;

  LINE(15);
    {
    {
    ret_1->num = 0;
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

/**** END PROCEDURE _qindexc ****/

