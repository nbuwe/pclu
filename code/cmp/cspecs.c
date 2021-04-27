
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


extern errcode duOPget_mspecs();
extern errcode duOPread_specs();
extern errcode oneofOPis_4();
extern errcode c_envOPadd_undefined();
extern errcode f_duspecs();
extern errcode duOPset_mspecs();
extern errcode oneofOPmake_2();

/**** BEGIN PROCEDURE c_get_duspecs ****/

errcode
c_get_duspecs(CLUREF e, CLUREF gen, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF ms;
    CLUREF specs;
    CLUREF fixdus;
    enter_proc(6);

  LINE(7);
    {
    CLUREF T_1_1;
    err = duOPget_mspecs(gen, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 2:
         {CLUREF T_1_2;
        T_1_2.num = T_1_1.cell->value;
        ms.num = T_1_2.num;

  LINE(9);
            {
            {
            ret_1->num = ms.num;
            }
            {signal (ERR_ok);}}
            break;
            }
    default: {
    }
    }
    }

  LINE(12);
    {
        {CLUREF T_1_1;
        CLUREF T_1_2;
        err = duOPread_specs(gen, &T_1_1, &T_1_2);
        if (err != ERR_ok) goto ex_0;
        specs.num = T_1_1.num;
        fixdus.num = T_1_2.num;
        }
        }

  LINE(13);
    {
    CLUREF T_1_1;
    if (specs.cell->tag == 4) T_1_1.num = true; else T_1_1.num = false;
    if (T_1_1.num == true) {

  LINE(14);
        {
        err = c_envOPadd_undefined(e, gen);
        if (err != ERR_ok) goto ex_0;
        }
        }
    else {

  LINE(15);
        {
        err = f_duspecs(e, specs, fixdus);
        if (err != ERR_ok) goto ex_0;
        }
        }}/* end if */

  LINE(17);
    {
    CLUREF T_1_1;
    CellAlloc(2, specs.num, T_1_1);
    err = duOPset_mspecs(gen, T_1_1);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(18);
    {
    {
    ret_1->num = specs.num;
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

/**** END PROCEDURE c_get_duspecs ****/



/**** BEGIN PROCEDURE c_duspecs ****/

errcode
c_duspecs(CLUREF e, CLUREF specs)
    {
    errcode err;
    errcode ecode2;
    enter_proc(21);
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE c_duspecs ****/


extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode sequenceOPsize();
extern errcode sequenceOPindexes();
extern errcode typespecOPmismatch2();
extern errcode sequenceOPfetch();

/**** BEGIN PROCEDURE types_mismatch ****/

errcode
types_mismatch(CLUREF types1, CLUREF types2, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    enter_proc(24);

  LINE(25);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    T_1_1.num = types1.vec->size;
    T_1_2.num = types2.vec->size;
    T_1_3.num = (T_1_1.num == T_1_2.num)? true : false;
    T_1_4.num = T_1_3.num ^ 1;
    if (T_1_4.num == true) {

  LINE(26);
        {
        {
        ret_1->tf = true;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(27);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
        T_1_2.num = types1.vec->size;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            i.num = T_1_1.num;

  LINE(28);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            if (i.num < 1 || i.num > types1.vec->size ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_1.num = types1.vec->data[i.num - 1];
            if (i.num < 1 || i.num > types2.vec->size ) {
                err = ERR_bounds;
                goto ex_0;}
            T_2_2.num = types2.vec->data[i.num - 1];
            err = typespecOPmismatch2(T_2_1, T_2_2, &T_2_3);
            if (err != ERR_ok) goto ex_0;
            if (T_2_3.num == true) {

  LINE(29);
                {
                {
                ret_1->tf = true;
                }
                {signal (ERR_ok);}}
                }
                }/* end if */
        }
    }
    end_inline_for_1:;

  LINE(31);
    {
    {
    ret_1->tf = false;
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

/**** END PROCEDURE types_mismatch ****/


extern errcode f_idnkinds();
extern errcode recordOPget_1();
extern errcode recordOPset_2();
extern errcode f_type();
extern errcode recordOPget_2();
extern errcode sequenceOPelements();
extern errcode recordOPget_3();
extern errcode f_opspeclist();

/**** BEGIN PROCEDURE f_duspecs ****/

errcode
f_duspecs(CLUREF e, CLUREF specs, CLUREF fixdus)
    {
    errcode err;
    errcode ecode2;
    CLUREF info;
    CLUREF inf;
    CLUREF req;
    CLUREF infinf;
    enter_proc(34);

  LINE(35);
    {
    switch (specs.cell->tag) {
    case 1:
         {CLUREF T_1_1;
        T_1_1.num = specs.cell->value;
        info.num = T_1_1.num;

  LINE(37);
            {
            CLUREF T_2_1;
            T_2_1.num = info.vec->data[0];
            err = f_idnkinds(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(38);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = info.vec->data[1];
            err = f_type(e, T_2_1, fixdus, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            info.vec->data[1]  = T_2_2.num;
            }
            break;
            }
    case 3:
    case 5:
    case 2:
         {CLUREF T_1_2;
        T_1_2.num = specs.cell->value;
        info.num = T_1_2.num;

  LINE(40);
            {
            CLUREF T_2_1;
            T_2_1.num = info.vec->data[1];
            err = f_idnkinds(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(41);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            CLUREF T_2_4;
                T_2_1.num = info.vec->data[0];
                T_2_3.num = T_2_1.vec->size;
                T_2_4 = T_2_1;
                for (T_2_2.num = 1; T_2_2.num <= T_2_3.num; T_2_2.num++) {
                    inf.num = T_2_4.vec->data[T_2_2.num - 1];

  LINE(42);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    CLUREF T_3_3;
                    CLUREF T_3_4;
                        T_3_1.num = inf.vec->data[2];
                        T_3_3.num = T_3_1.vec->size;
                        T_3_4 = T_3_1;
                        for (T_3_2.num = 1; T_3_2.num <= T_3_3.num; T_3_2.num++) {
                            req.num = T_3_4.vec->data[T_3_2.num - 1];

  LINE(43);
                            {
                            CLUREF T_4_1;
                            T_4_1.num = req.vec->data[0];
                            err = f_opspeclist(e, T_4_1, fixdus);
                            if (err != ERR_ok) goto ex_0;
                            }
                        }
                    }
                    end_inline_for_2:;

  LINE(45);
                    {
                        {CLUREF T_3_1;
                        T_3_1.num = inf.vec->data[0];
                        infinf.num = T_3_1.num;
                        }
                        }

  LINE(46);
                    {
                    CLUREF T_3_1;
                    T_3_1.num = infinf.vec->data[0];
                    err = f_idnkinds(e, T_3_1, fixdus);
                    if (err != ERR_ok) goto ex_0;
                    }

  LINE(47);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    T_3_1.num = infinf.vec->data[1];
                    err = f_type(e, T_3_1, fixdus, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    infinf.vec->data[1]  = T_3_2.num;
                    }
                }
            }
            end_inline_for_1:;
            break;
            }
    default: {
    }
    }
    }
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE f_duspecs ****/


extern errcode idnOPget_kind();
extern errcode typespecOPget_id();
extern errcode idnOPset_kind();
extern errcode oneofOPmake_10();

/**** BEGIN PROCEDURE f_idnkinds ****/

errcode
f_idnkinds(CLUREF e, CLUREF parms, CLUREF fixdus)
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    CLUREF k;
    enter_proc(53);

  LINE(54);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        T_1_2.num = parms.vec->size;
        T_1_3 = parms;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            i.num = T_1_3.vec->data[T_1_1.num - 1];

  LINE(55);
            {
            CLUREF T_2_1;
            err = idnOPget_kind(i, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            switch (T_2_1.cell->tag) {
            case 6:
                 {CLUREF T_2_2;
                T_2_2.num = T_2_1.cell->value;
                k.num = T_2_2.num;

  LINE(57);
                    {
                    err = f_opspeclist(e, k, fixdus);
                    if (err != ERR_ok) goto ex_0;
                    }
                    break;
                    }
            case 10:
                 {CLUREF T_2_3;
                T_2_3.num = T_2_1.cell->value;
                k.num = T_2_3.num;

  LINE(59);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    CLUREF T_3_3;
                    CLUREF T_3_4;
                    err = typespecOPget_id(k, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    T_3_3.num = (T_3_2.num == 0)? true : false;
                    T_3_1.num = T_3_3.num;
                    if (!T_3_3.num) {
                        T_3_1.num = fixdus.num;
                    }
                    T_3_4.num = T_3_1.num ^ 1;
                    if (T_3_4.num == true) {

  LINE(60);
                        {
                        CLUREF T_4_1;
                        CLUREF T_4_2;
                        err = f_type(e, k, fixdus, &T_4_1);
                        if (err != ERR_ok) goto ex_0;
                        CellAlloc(10, T_4_1.num, T_4_2);
                        err = idnOPset_kind(i, T_4_2);
                        if (err != ERR_ok) goto ex_0;
                        }
                        }
                        }/* end if */
                    break;
                    }
            case 5:
                 {CLUREF T_2_4;
                T_2_4.num = T_2_1.cell->value;
                k.num = T_2_4.num;

  LINE(64);
                    {
                    err = f_opspeclist(e, k, fixdus);
                    if (err != ERR_ok) goto ex_0;
                    }
                    break;
                    }
            default: {
            }
            }
            }
        }
    }
    end_inline_for_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE f_idnkinds ****/


extern errcode f_exprlist();
extern errcode recordOPset_3();

/**** BEGIN PROCEDURE f_opspeclist ****/

errcode
f_opspeclist(CLUREF e, CLUREF ops, CLUREF fixdus)
    {
    errcode err;
    errcode ecode2;
    CLUREF op;
    enter_proc(70);

  LINE(71);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        T_1_2.num = ops.vec->size;
        T_1_3 = ops;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            op.num = T_1_3.vec->data[T_1_1.num - 1];

  LINE(72);
            {
            CLUREF T_2_1;
            T_2_1.num = op.vec->data[1];
            err = f_exprlist(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(73);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = op.vec->data[2];
            err = f_type(e, T_2_1, fixdus, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            op.vec->data[2]  = T_2_2.num;
            }
        }
    }
    end_inline_for_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE f_opspeclist ****/


extern errcode typespecOPget_abs();
extern errcode recordOPset_1();
extern errcode f_typelist();
extern errcode recordOPset_4();
extern errcode recordOPget_4();
extern errcode oneofOPmake_3();
extern errcode oneofOPmake_6();
extern errcode c_envOPget_type();

/**** BEGIN PROCEDURE f_type ****/

errcode
f_type(CLUREF e, CLUREF t, CLUREF fixdus, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF abs;
    CLUREF clut;
    CLUREF selt;
    CLUREF fspec;
    CLUREF at;
    CLUREF sig;
    CLUREF ot;
    CLUREF cop;
    CLUREF tt;
    enter_proc(77);

  LINE(78);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    err = typespecOPget_id(t, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    T_1_3.num = (T_1_2.num == 0)? true : false;
    T_1_1.num = T_1_3.num;
    if (!T_1_3.num) {
        T_1_1.num = fixdus.num;
    }
    T_1_4.num = T_1_1.num ^ 1;
    if (T_1_4.num == true) {

  LINE(79);
        {
        {
        ret_1->num = t.num;
        }
        {signal (ERR_ok);}}
        }
        }/* end if */

  LINE(80);
    {
        {CLUREF T_1_1;
        err = typespecOPget_abs(t, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        abs.num = T_1_1.num;
        }
        }

  LINE(81);
    {
    switch (abs.cell->tag) {
    case 3:
         {CLUREF T_1_1;
        T_1_1.num = abs.cell->value;
        clut.num = T_1_1.num;

  LINE(83);
            {
            CLUREF T_2_1;
            T_2_1.num = clut.vec->data[1];
            err = f_exprlist(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    case 7:
         {CLUREF T_1_2;
        T_1_2.num = abs.cell->value;
        selt.num = T_1_2.num;

  LINE(85);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            CLUREF T_2_4;
                T_2_1.num = selt.vec->data[1];
                T_2_3.num = T_2_1.vec->size;
                T_2_4 = T_2_1;
                for (T_2_2.num = 1; T_2_2.num <= T_2_3.num; T_2_2.num++) {
                    fspec.num = T_2_4.vec->data[T_2_2.num - 1];

  LINE(86);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    T_3_1.num = fspec.vec->data[1];
                    err = f_type(e, T_3_1, fixdus, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    fspec.vec->data[1]  = T_3_2.num;
                    }
                }
            }
            end_inline_for_1:;
            break;
            }
    case 2:
         {CLUREF T_1_3;
        T_1_3.num = abs.cell->value;
        at.num = T_1_3.num;

  LINE(89);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = at.vec->data[0];
            err = f_typelist(e, T_2_1, fixdus, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            at.vec->data[0]  = T_2_2.num;
            }

  LINE(90);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = at.vec->data[3];
            err = f_typelist(e, T_2_1, fixdus, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            at.vec->data[3]  = T_2_2.num;
            }

  LINE(91);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            CLUREF T_2_4;
                T_2_1.num = at.vec->data[2];
                T_2_3.num = T_2_1.vec->size;
                T_2_4 = T_2_1;
                for (T_2_2.num = 1; T_2_2.num <= T_2_3.num; T_2_2.num++) {
                    sig.num = T_2_4.vec->data[T_2_2.num - 1];

  LINE(92);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    T_3_1.num = sig.vec->data[1];
                    err = f_typelist(e, T_3_1, fixdus, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    sig.vec->data[1]  = T_3_2.num;
                    }
                }
            }
            end_inline_for_2:;
            break;
            }
    case 6:
         {CLUREF T_1_4;
        T_1_4.num = abs.cell->value;
        ot.num = T_1_4.num;

  LINE(95);
            {
            switch (ot.cell->tag) {
            case 1:
                 {CLUREF T_2_1;
                T_2_1.num = ot.cell->value;
                clut.num = T_2_1.num;

  LINE(97);
                    {
                    CLUREF T_3_1;
                    T_3_1.num = clut.vec->data[1];
                    err = f_exprlist(e, T_3_1, fixdus);
                    if (err != ERR_ok) goto ex_0;
                    }
                    break;
                    }
            case 2:
                 {CLUREF T_2_2;
                T_2_2.num = ot.cell->value;
                cop.num = T_2_2.num;

  LINE(99);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    T_3_1.num = cop.vec->data[2];
                    err = f_type(e, T_3_1, fixdus, &T_3_2);
                    if (err != ERR_ok) goto ex_0;
                    cop.vec->data[2]  = T_3_2.num;
                    }

  LINE(100);
                    {
                    CLUREF T_3_1;
                    T_3_1.num = cop.vec->data[1];
                    err = f_exprlist(e, T_3_1, fixdus);
                    if (err != ERR_ok) goto ex_0;
                    }
                    break;
                    }
            case 3:
                 {CLUREF T_2_3;
                T_2_3.num = ot.cell->value;
                tt.num = T_2_3.num;

  LINE(102);
                    {
                    CLUREF T_3_1;
                    CLUREF T_3_2;
                    err = f_type(e, tt, fixdus, &T_3_1);
                    if (err != ERR_ok) goto ex_0;
                    CellAlloc(3, T_3_1.num, T_3_2);
                    ot.num = T_3_2.num;
                    }

  LINE(103);
                    {
                    CLUREF T_3_1;
                    CellAlloc(6, ot.num, T_3_1);
                    abs.num = T_3_1.num;
                    }
                    break;
                    }
            }
            }
            break;
            }
    default: {
    }
    }
    }

  LINE(107);
    {
    {
    CLUREF T_1_1;
    err = c_envOPget_type(e, abs, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    ret_1->num = T_1_1.num;
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

/**** END PROCEDURE f_type ****/


extern errcode sequenceOPreplace();

/**** BEGIN PROCEDURE f_typelist ****/

errcode
f_typelist(CLUREF e, CLUREF types, CLUREF fixdus, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF i;
    CLUREF t;
    enter_proc(110);

  LINE(111);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
        T_1_2.num = types.vec->size;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            i.num = T_1_1.num;

  LINE(112);
            {
                {CLUREF T_2_1;
                if (i.num < 1 || i.num > types.vec->size ) {
                    err = ERR_bounds;
                    goto ex_0;}
                T_2_1.num = types.vec->data[i.num - 1];
                t.num = T_2_1.num;
                }
                }

  LINE(113);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            err = typespecOPget_id(t, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            T_2_3.num = (T_2_2.num == 0)? true : false;
            T_2_1.num = T_2_3.num;
            if (!T_2_3.num) {
                T_2_1.num = fixdus.num;
            }
            if (T_2_1.num == true) {

  LINE(114);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                err = f_type(e, t, fixdus, &T_3_1);
                if (err != ERR_ok) goto ex_0;
                err = sequenceOPreplace(types, i, T_3_1, &T_3_2);
                if (err != ERR_ok) goto ex_0;
                types.num = T_3_2.num;
                }
                }
                }/* end if */
        }
    }
    end_inline_for_1:;

  LINE(118);
    {
    {
    ret_1->num = types.num;
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

/**** END PROCEDURE f_typelist ****/


extern errcode exprOPset_typespec();
extern errcode exprOPget_typespec();
extern errcode exprOPget_abs();
extern errcode exprOPset_abs();
extern errcode oneofOPmake_25();
extern errcode f_expr();
extern errcode c_envOPget_du();
extern errcode oneofOPmake_11();

/**** BEGIN PROCEDURE f_expr ****/

errcode
f_expr(CLUREF e, CLUREF x, CLUREF fixdus)
    {
    errcode err;
    errcode ecode2;
    CLUREF t;
    CLUREF inv;
    CLUREF clut;
    CLUREF cop;
    enter_proc(121);

  LINE(122);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = exprOPget_typespec(x, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    err = f_type(e, T_1_1, fixdus, &T_1_2);
    if (err != ERR_ok) goto ex_0;
    err = exprOPset_typespec(x, T_1_2);
    if (err != ERR_ok) goto ex_0;
    }

  LINE(123);
    {
    CLUREF T_1_1;
    err = exprOPget_abs(x, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    switch (T_1_1.cell->tag) {
    case 25:
         {CLUREF T_1_2;
        T_1_2.num = T_1_1.cell->value;
        t.num = T_1_2.num;

  LINE(125);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            err = typespecOPget_id(t, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            T_2_3.num = (T_2_2.num == 0)? true : false;
            T_2_1.num = T_2_3.num;
            if (!T_2_3.num) {
                T_2_1.num = fixdus.num;
            }
            if (T_2_1.num == true) {

  LINE(126);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                err = f_type(e, t, fixdus, &T_3_1);
                if (err != ERR_ok) goto ex_0;
                CellAlloc(25, T_3_1.num, T_3_2);
                err = exprOPset_abs(x, T_3_2);
                if (err != ERR_ok) goto ex_0;
                }
                }
                }/* end if */
            break;
            }
    case 16:
         {CLUREF T_1_3;
        T_1_3.num = T_1_1.cell->value;
        inv.num = T_1_3.num;

  LINE(128);
            {
            CLUREF T_2_1;
            T_2_1.num = inv.vec->data[0];
            err = f_expr(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }

  LINE(129);
            {
            CLUREF T_2_1;
            T_2_1.num = inv.vec->data[1];
            err = f_exprlist(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    case 3:
         {CLUREF T_1_4;
        T_1_4.num = T_1_1.cell->value;
        clut.num = T_1_4.num;

  LINE(131);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = clut.vec->data[0];
            err = c_envOPget_du(e, T_2_1, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            clut.vec->data[0]  = T_2_2.num;
            }

  LINE(132);
            {
            CLUREF T_2_1;
            T_2_1.num = clut.vec->data[1];
            err = f_exprlist(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    case 20:
         {CLUREF T_1_5;
        T_1_5.num = T_1_1.cell->value;
        cop.num = T_1_5.num;

  LINE(134);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            T_2_1.num = cop.vec->data[2];
            err = f_type(e, T_2_1, fixdus, &T_2_2);
            if (err != ERR_ok) goto ex_0;
            cop.vec->data[2]  = T_2_2.num;
            }

  LINE(135);
            {
            CLUREF T_2_1;
            T_2_1.num = cop.vec->data[1];
            err = f_exprlist(e, T_2_1, fixdus);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    case 11:
         {CLUREF T_1_6;
        T_1_6.num = T_1_1.cell->value;
        t.num = T_1_6.num;

  LINE(137);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            err = f_type(e, t, fixdus, &T_2_1);
            if (err != ERR_ok) goto ex_0;
            CellAlloc(11, T_2_1.num, T_2_2);
            err = exprOPset_abs(x, T_2_2);
            if (err != ERR_ok) goto ex_0;
            }
            break;
            }
    default: {
    }
    }
    }
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE f_expr ****/



/**** BEGIN PROCEDURE f_exprlist ****/

errcode
f_exprlist(CLUREF e, CLUREF exprs, CLUREF fixdus)
    {
    errcode err;
    errcode ecode2;
    CLUREF x;
    enter_proc(142);

  LINE(143);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
        T_1_2.num = exprs.vec->size;
        T_1_3 = exprs;
        for (T_1_1.num = 1; T_1_1.num <= T_1_2.num; T_1_1.num++) {
            x.num = T_1_3.vec->data[T_1_1.num - 1];

  LINE(144);
            {
            err = f_expr(e, x, fixdus);
            if (err != ERR_ok) goto ex_0;
            }
        }
    }
    end_inline_for_1:;
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE f_exprlist ****/

