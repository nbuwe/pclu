
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _last_indexc ****/

extern errcode intOPfrom_to_by();
extern errcode stringOPsize();
extern errcode charOPequal();
extern errcode stringOPfetch();

errcode
_last_indexc(CLUREF c, CLUREF s, CLUREF *ret_1)
{
    errcode err;
    CLUREF i;
    enter_proc(3);

  LINE(4);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_3.num = 1;
        T_1_4.num = -1;
        for (T_1_2.num = T_1_1.num; ((T_1_4.num == 0) || ((T_1_4.num > 0)? (T_1_2.num <= T_1_3.num) : (T_1_2.num >= T_1_3.num))); T_1_2.num += T_1_4.num) {
            i.num = T_1_2.num;

  LINE(5);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            err = stringOPfetch(s, i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            T_2_2.num = (T_2_1.ch == c.ch)? true : false;
            if (T_2_2.num == true) {

  LINE(6);
                {
                {
                ret_1->num = i.num;
                }
                {signal (ERR_ok);}}
                }
                }/* end if */
        }
    }
    end_inline_for_1:;

  LINE(8);
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

/**** END PROCEDURE _last_indexc ****/

