
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _fixup_dir_part ****/

extern errcode stringOPindexs();
extern errcode intOPequal();
extern errcode stringOPconcat();
extern errcode stringOPsubstr();
extern errcode stringOPrest();
extern errcode intOPadd();
extern errcode stringOPsize();
extern errcode intOPgt();
extern errcode charOPequal();
extern errcode stringOPfetch();
extern errcode intOPsub();
static CLUREF STR__057_057;
static int _fixup_dir_part_own_init = 0;

errcode
_fixup_dir_part(CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF i;
    if (_fixup_dir_part_own_init == 0) {
        stringOPcons("//", CLU_1, CLUREF_make_num(2), &STR__057_057);
        _fixup_dir_part_own_init = 1;
    }
    enter_proc(3);

  LINE(4);
    for (;;) {
        if (true != true) { break; }

  LINE(5);
        {
            {CLUREF T_2_1;
            err = stringOPindexs(STR__057_057, s, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            i.num = T_2_1.num;
            }
            }

  LINE(6);
        {
        CLUREF T_2_1;
        T_2_1.num = (i.num == 0)? true : false;
        if (T_2_1.num == true) {

  LINE(7);
            goto end_while_1;
            }
            }/* end if */

  LINE(8);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        CLUREF T_2_3;
        CLUREF T_2_4;
        err = stringOPsubstr(s, CLU_1, i, &T_2_1);
        if (err != ERR_ok) goto ex_0;
        T_2_2.num = i.num + 2;
         if ((T_2_2.num > 0 && i.num < 0 && 2 < 0) ||
             (T_2_2.num < 0 && i.num > 0 && 2 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPrest(s, T_2_2, &T_2_3);
        if (err != ERR_ok) goto ex_0;
        err = stringOPconcat(T_2_1, T_2_3, &T_2_4);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_4.num;
        }
        }
        end_while_1:;

  LINE(10);
    {
        {CLUREF T_1_1;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        i.num = T_1_1.num;
        }
        }

  LINE(11);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    T_1_2.num = (i.num > 1)? true : false;
    T_1_1.num = T_1_2.num;
    if (T_1_2.num) {
        err = stringOPfetch(s, i, &T_1_3);
        if (err != ERR_ok) goto ex_0;
        T_1_4.ch = '/';
        T_1_5.num = (T_1_3.ch == T_1_4.ch)? true : false;
        T_1_1.num = T_1_5.num;
    }
    if (T_1_1.num == true) {

  LINE(12);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = i.num - 1;
         if ((T_2_1.num >= 0 && i.num < 0 && (-1) < 0) ||
             (T_2_1.num <= 0 && i.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        err = stringOPsubstr(s, CLU_1, T_2_1, &T_2_2);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_2.num;
        }
        }
        }/* end if */

  LINE(13);
    {
    {
    ret_1->num = s.num;
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

/**** END PROCEDURE _fixup_dir_part ****/

