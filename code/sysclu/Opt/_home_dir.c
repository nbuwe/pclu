
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN PROCEDURE _home_dir ****/

extern errcode stringOPempty();
extern errcode _environ();
extern errcode sequenceOPindexes();
extern errcode stringOPequal();
extern errcode sequenceOPfetch();
extern errcode _chanOPopen();
extern errcode file_nameOPparse();
extern errcode _bytevecOPcreate();
extern errcode _chanOPgetb();
extern errcode _cvt();
extern errcode intOPadd();
extern errcode stringOPsize();
extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode _bytevecOPindexv();
extern errcode charOPequal();
extern errcode _bytevecOPfetch();
extern errcode _skip_fill();
extern errcode intOPfrom_to_by();
extern errcode _chanOPget();
extern errcode _file_exists();
extern errcode _chanOPclose();
extern errcode sequenceOPnew();
extern errcode sequenceOPaddh();
static CLUREF STR_HOME;
static CLUREF STR_CLU;
static CLUREF STR_CLUHOME;
static CLUREF STR_ARGUS;
static CLUREF STR_ARGUSHOME;
static CLUREF STR__057etc_057passwd;
static CLUREF STR_read;
static CLUREF STR__072;
static CLUREF STR__057usr_057local_057lib_057clu;
static CLUREF STR__057usr_057lib_057clu;
static CLUREF STR__057mit_057PCLU_057decmipslib;
static CLUREF STR__057usr_057clu;
static CLUREF STR__057usr_057local_057lib_057argus;
static CLUREF STR__057usr_057lib_057argus;
static CLUREF STR__057usr_057argus;
static int _home_dir_own_init = 0;
CLUREF _home_dirOPusers;
CLUREF _home_dirOPhomes;
CLUREF _home_dirOPhave;

errcode
_home_dir(CLUREF user, CLUREF *ret_1)
{
    errcode err;
    CLUREF i;
    CLUREF c;
    CLUREF b;
    CLUREF max;
    CLUREF buser;
    CLUREF idx;
    CLUREF home;
    if (_home_dir_own_init == 0) {
        stringOPcons("HOME", CLU_1, CLUREF_make_num(4), &STR_HOME);
        stringOPcons("CLU", CLU_1, CLUREF_make_num(3), &STR_CLU);
        stringOPcons("CLUHOME", CLU_1, CLUREF_make_num(7), &STR_CLUHOME);
        stringOPcons("ARGUS", CLU_1, CLUREF_make_num(5), &STR_ARGUS);
        stringOPcons("ARGUSHOME", CLU_1, CLUREF_make_num(9), &STR_ARGUSHOME);
        stringOPcons("/etc/passwd", CLU_1, CLUREF_make_num(11), &STR__057etc_057passwd);
        stringOPcons("read", CLU_1, CLUREF_make_num(4), &STR_read);
        stringOPcons(":", CLU_1, CLUREF_make_num(1), &STR__072);
        stringOPcons("/usr/local/lib/clu", CLU_1, CLUREF_make_num(18), &STR__057usr_057local_057lib_057clu);
        stringOPcons("/usr/lib/clu", CLU_1, CLUREF_make_num(12), &STR__057usr_057lib_057clu);
        stringOPcons("/mit/PCLU/decmipslib", CLU_1, CLUREF_make_num(20), &STR__057mit_057PCLU_057decmipslib);
        stringOPcons("/usr/clu", CLU_1, CLUREF_make_num(8), &STR__057usr_057clu);
        stringOPcons("/usr/local/lib/argus", CLU_1, CLUREF_make_num(20), &STR__057usr_057local_057lib_057argus);
        stringOPcons("/usr/lib/argus", CLU_1, CLUREF_make_num(14), &STR__057usr_057lib_057argus);
        stringOPcons("/usr/argus", CLU_1, CLUREF_make_num(10), &STR__057usr_057argus);
        _home_dir_own_init = 1;
        {
            {_home_dirOPhave.tf = false;
            }
            }
    }
    enter_proc(3);

  LINE(7);
    {
    CLUREF T_2_1;
    err = stringOPempty(user, &T_2_1);
    if (err != ERR_ok) goto ex_1;
    if (T_2_1.num == true) {

  LINE(8);
        {
        {
        CLUREF T_3_1;
        err = _environ(STR_HOME, &T_3_1);
        if (err != ERR_ok) goto ex_1;
        ret_1->num = T_3_1.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */
    goto end_1;
    ex_1:
        if (err == ERR_not_found) {signal(ERR_not_found);}
        else {
            goto ex_0;}
    end_1:;

  LINE(10);
    {
    if (_home_dirOPhave.num == true) {

  LINE(11);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
            T_2_2.num = _home_dirOPusers.vec->size;
            for (T_2_1.num = 1; T_2_1.num <= T_2_2.num; T_2_1.num++) {
                i.num = T_2_1.num;

  LINE(12);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                if (i.num < 1 || i.num > _home_dirOPusers.vec->size ) {
                    err = ERR_bounds;
                    goto ex_0;}
                T_3_1.num = _home_dirOPusers.vec->data[i.num - 1];
                T_3_2.num = ((T_3_1.str->size != user.str->size)? false :
                    !(memcmp(T_3_1.str->data, user.str->data, T_3_1.str->size)));
                if (T_3_2.num == true) {

  LINE(13);
                    {
                    {
                    CLUREF T_4_1;
                    if (i.num < 1 || i.num > _home_dirOPhomes.vec->size ) {
                        err = ERR_bounds;
                        goto ex_0;}
                    T_4_1.num = _home_dirOPhomes.vec->data[i.num - 1];
                    ret_1->num = T_4_1.num;
                    }
                    {signal (ERR_ok);}}
                    }
                    }/* end if */
            }
        }
        end_inline_for_1:;
        }
        }/* end if */

  LINE(16);
    {
    CLUREF T_2_1;
    T_2_1.num = ((user.str->size != STR_CLU.str->size)? false :
        !(memcmp(user.str->data, STR_CLU.str->data, user.str->size)));
    if (T_2_1.num == true) {

  LINE(17);
        {
        {
        CLUREF T_3_1;
        err = _environ(STR_CLUHOME, &T_3_1);
        if (err != ERR_ok) goto ex_2;
        ret_1->num = T_3_1.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */
        goto end_2;
        ex_2:
            if ((err == ERR_not_found)) {
            }
            else {
                goto ex_0;
            }
        end_2:;

  LINE(21);
    {
    CLUREF T_2_1;
    T_2_1.num = ((user.str->size != STR_ARGUS.str->size)? false :
        !(memcmp(user.str->data, STR_ARGUS.str->data, user.str->size)));
    if (T_2_1.num == true) {

  LINE(22);
        {
        {
        CLUREF T_3_1;
        err = _environ(STR_ARGUSHOME, &T_3_1);
        if (err != ERR_ok) goto ex_3;
        ret_1->num = T_3_1.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */
        goto end_3;
        ex_3:
            if ((err == ERR_not_found)) {
            }
            else {
                goto ex_0;
            }
        end_3:;

  LINE(26);
    {
        {CLUREF T_2_1;
        CLUREF T_2_2;
        err = file_nameOPparse(STR__057etc_057passwd, &T_2_1);
        if (err != ERR_ok) goto ex_4;
        err = _chanOPopen(T_2_1, STR_read, CLU_0, &T_2_2);
        if (err != ERR_ok) goto ex_4;
        c.num = T_2_2.num;
        }
        }
        goto end_4;
        ex_4:
            if ((err == ERR_not_possible)) {

  LINE(27);
                {
                {signal (ERR_not_found);}}
            }
            else {
                goto ex_0;
            }
        end_4:;

  LINE(28);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        T_1_1.num = 64;
        err = _bytevecOPcreate(T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        b.num = T_1_2.num;
        }
        }

  LINE(29);
    {
        {CLUREF T_1_1;
        err = _chanOPgetb(c, b, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        max.num = T_1_1.num;
        }
        }

  LINE(30);
    {
        {CLUREF T_1_1;
        T_1_1.num = (long)user.num;
        buser.num = T_1_1.num;
        }
        }

  LINE(31);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        err = stringOPsize(user, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_2.num = T_1_1.num + 1;
         if ((T_1_2.num > 0 && T_1_1.num < 0 && 1 < 0) ||
             (T_1_2.num < 0 && T_1_1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        idx.num = T_1_2.num;
        }
        }

  LINE(33);
    {

  LINE(34);
        for (;;) {
            CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            CLUREF T_3_4;
            CLUREF T_3_5;
            CLUREF T_3_6;
            CLUREF T_3_7;
            CLUREF T_3_8;
            err = _bytevecOPindexv(buser, b, CLU_1, &T_3_2);
            if (err != ERR_ok) goto ex_5;
            T_3_3.num = (T_3_2.num == 1)? true : false;
            T_3_4.num = T_3_3.num ^ 1;
            T_3_1.num = T_3_4.num;
            if (!T_3_4.num) {
                if (idx.num < 1 || idx.num > b.str->size ) {
                    err = ERR_bounds;
                    goto ex_5;}
                T_3_5.ch = b.str->data[idx.num - 1];
                T_3_6.ch = ':';
                T_3_7.num = (T_3_5.ch == T_3_6.ch)? true : false;
                T_3_8.num = T_3_7.num ^ 1;
                T_3_1.num = T_3_8.num;
            }
            if (T_3_1.num != true) { break; }

  LINE(35);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            T_4_1.ch = '\n';
            err = _skip_fill(b, max, c, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_5;
            max.num = T_4_2.num;
            }
            }
            end_while_1:;

  LINE(37);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
            T_3_2.num = 1;
            T_3_3.num = -1;
            for (T_3_1.num = 5; ((T_3_3.num == 0) || ((T_3_3.num > 0)? (T_3_1.num <= T_3_2.num) : (T_3_1.num >= T_3_2.num))); T_3_1.num += T_3_3.num) {
                i.num = T_3_1.num;

  LINE(38);
                {
                CLUREF T_4_1;
                CLUREF T_4_2;
                T_4_1.ch = ':';
                err = _skip_fill(b, max, c, T_4_1, &T_4_2);
                if (err != ERR_ok) goto ex_5;
                max.num = T_4_2.num;
                }
            }
        }
        end_inline_for_2:;

  LINE(40);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        CLUREF T_3_3;
        err = _chanOPget(c, b, CLU_1, max, STR__072, CLU_0, &T_3_1, &T_3_2, &T_3_3);
        if (err != ERR_ok) goto ex_5;
        home.num = T_3_1.num;
        idx.num = T_3_2.num;
        max.num = T_3_3.num;
        }
        }
        goto end_5;
        ex_5:
            if ((err == ERR_end_of_file)
             || (err == ERR_not_possible)) {

  LINE(43);
                {
                CLUREF T_2_1;
                T_2_1.num = ((user.str->size != STR_CLU.str->size)? false :
                    !(memcmp(user.str->data, STR_CLU.str->data, user.str->size)));
                if (T_2_1.num == true) {

  LINE(44);
                    {
                    CLUREF T_3_1;
                    err = _file_exists(STR__057usr_057local_057lib_057clu, CLU_4, &T_3_1);
                    if (err != ERR_ok) goto ex_0;
                    if (T_3_1.num == true) {

  LINE(45);
                        {
                        home = STR__057usr_057local_057lib_057clu;
                        }
                        }
                    else {
                    CLUREF T_3_2;
                    err = _file_exists(STR__057usr_057lib_057clu, CLU_4, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    if (T_3_2.num == true) {

  LINE(47);
                        {
                        home = STR__057usr_057lib_057clu;
                        }
                        }
                    else {
                    CLUREF T_3_3;
                    err = _file_exists(STR__057mit_057PCLU_057decmipslib, CLU_4, &T_3_3);
                    if (err != ERR_ok) goto ex_0;
                    if (T_3_3.num == true) {

  LINE(49);
                        {
                        home = STR__057mit_057PCLU_057decmipslib;
                        }
                        }
                    else {

  LINE(51);
                        {
                        home = STR__057usr_057clu;
                        }
                        }}}}/* end if */
                    }
                else {
                CLUREF T_2_2;
                T_2_2.num = ((user.str->size != STR_ARGUS.str->size)? false :
                    !(memcmp(user.str->data, STR_ARGUS.str->data, user.str->size)));
                if (T_2_2.num == true) {

  LINE(54);
                    {
                    CLUREF T_3_1;
                    err = _file_exists(STR__057usr_057local_057lib_057argus, CLU_4, &T_3_1);
                    if (err != ERR_ok) goto ex_0;
                    if (T_3_1.num == true) {

  LINE(55);
                        {
                        home = STR__057usr_057local_057lib_057argus;
                        }
                        }
                    else {
                    CLUREF T_3_2;
                    err = _file_exists(STR__057usr_057lib_057argus, CLU_4, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    if (T_3_2.num == true) {

  LINE(57);
                        {
                        home = STR__057usr_057lib_057argus;
                        }
                        }
                    else {

  LINE(59);
                        {
                        home = STR__057usr_057argus;
                        }
                        }}}/* end if */
                    }
                else {

  LINE(61);
                    {
                    err = _chanOPclose(c);
                    if (err != ERR_ok) goto ex_0;
                    }

  LINE(62);
                    {
                    {signal (ERR_not_found);}}
                    }}}/* end if */
            }
            else {
                goto ex_0;
            }
        end_5:;

  LINE(65);
    {
    err = _chanOPclose(c);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(66);
    {
    CLUREF T_1_1;
    T_1_1.num = _home_dirOPhave.num ^ 1;
    if (T_1_1.num == true) {

  LINE(67);
        {
        CLUREF T_2_1;
        err = sequenceOPnew(&T_2_1);
        if (err != ERR_ok) goto ex_0;
        _home_dirOPusers.num = T_2_1.num;
        }

  LINE(68);
        {
        CLUREF T_2_1;
        err = sequenceOPnew(&T_2_1);
        if (err != ERR_ok) goto ex_0;
        _home_dirOPhomes.num = T_2_1.num;
        }

  LINE(69);
        {
        _home_dirOPhave.tf = true;
        }
        }
        }/* end if */

  LINE(71);
    {
    CLUREF T_1_1;
    err = sequenceOPaddh(_home_dirOPusers, user, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    _home_dirOPusers.num = T_1_1.num;
    }

  LINE(72);
    {
    CLUREF T_1_1;
    err = sequenceOPaddh(_home_dirOPhomes, home, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    _home_dirOPhomes.num = T_1_1.num;
    }

  LINE(73);
    {
    {
    ret_1->num = home.num;
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

/**** END PROCEDURE _home_dir ****/

