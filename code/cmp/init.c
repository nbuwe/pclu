
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"



/**** BEGIN PROCEDURE initialize_compiler ****/

extern errcode cmpvarOPset_version();
extern errcode stringOPappend();
extern errcode get_compiler_version();
extern errcode cmpvarOPset_date();
extern errcode dateOPunparse();
extern errcode now();
extern errcode xlibOPinit();
extern errcode ceOPcreate();
extern errcode file_nameOPparse();
extern errcode nul_dev();
extern errcode streamOPopen();
extern errcode p_envOPcreate();
extern errcode c_envOPcreate();
extern errcode streamOPclose();
extern errcode xrefOPcreate();
extern errcode oneofOPmake_1();
extern errcode arrayOPnew();
extern errcode cmpvarOPset_stuffs();
extern errcode initialize_specs();
extern errcode recordOPset_7();
extern errcode oneofOPmake_2();
extern errcode g_envOPcreate();
extern errcode save_compiler();
static CLUREF STR_read;
static CLUREF STR_write;
static int initialize_compiler_own_init = 0;

errcode
initialize_compiler(CLUREF *ret_1)
{
    errcode err;
    CLUREF comp;
    CLUREF fn;
    CLUREF inst;
    CLUREF outst;
    CLUREF ep;
    CLUREF ec;
    CLUREF exts;
    CLUREF undefs;
    CLUREF e;
    if (initialize_compiler_own_init == 0) {
        stringOPcons("read", CLU_1, CLUREF_make_num(4), &STR_read);
        stringOPcons("write", CLU_1, CLUREF_make_num(5), &STR_write);
        initialize_compiler_own_init = 1;
    }
    enter_proc(6);

  LINE(7);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    err = get_compiler_version(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    T_1_2.ch = 'X';
    err = stringOPappend(T_1_1, T_1_2, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    err = cmpvarOPset_version(T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(8);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = now(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = dateOPunparse(T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    err = cmpvarOPset_date(T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(9);
    {
    err = xlibOPinit();
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(10);
    {
    CLUREF T_1_1;
    err = ceOPcreate(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    comp.num = T_1_1.num;
    }

  LINE(11);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = nul_dev(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = file_nameOPparse(T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    fn.num = T_1_2.num;
    }

  LINE(12);
    {
    CLUREF T_1_1;
    err = streamOPopen(fn, STR_read, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    inst.num = T_1_1.num;
    }

  LINE(13);
    {
    CLUREF T_1_1;
    err = streamOPopen(fn, STR_write, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    outst.num = T_1_1.num;
    }

  LINE(14);
    {
    CLUREF T_1_1;
    err = p_envOPcreate(comp, inst, outst, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    ep.num = T_1_1.num;
    }

  LINE(15);
    {
    CLUREF T_1_1;
    err = c_envOPcreate(comp, outst, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    ec.num = T_1_1.num;
    }

  LINE(16);
    {
    err = streamOPclose(inst);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(17);
    {
    err = streamOPclose(outst);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(18);
    {
    CLUREF T_1_1;
    err = xrefOPcreate(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    exts.num = T_1_1.num;
    }

  LINE(19);
    {
    CLUREF T_1_1;
    err = xrefOPcreate(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    undefs.num = T_1_1.num;
    }

  LINE(20);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    RecordAlloc(13, T_1_1);
    T_1_1.vec->data[0] = comp.num;
    T_1_1.vec->data[2] = true;
    T_1_1.vec->data[1] = true;
    T_1_1.vec->data[11] = ep.num;
    T_1_1.vec->data[3] = ec.num;
    CellAlloc(1, nil, T_1_2);
    T_1_1.vec->data[6] = T_1_2.num;
    T_1_1.vec->data[8] = 0;
    T_1_1.vec->data[7] = inst.num;
    T_1_1.vec->data[10] = outst.num;
    T_1_1.vec->data[5] = outst.num;
    err = arrayOPnew(&T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    T_1_1.vec->data[9] = T_1_3.num;
    T_1_1.vec->data[4] = exts.num;
    T_1_1.vec->data[12] = undefs.num;
    e.num = T_1_1.num;
    }

  LINE(33);
    {
    err = cmpvarOPset_stuffs(e);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(34);
    {
    err = initialize_specs();
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(35);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = g_envOPcreate(comp, outst, fn, fn, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    CellAlloc(2, T_1_1.num, T_1_2);
    e.vec->data[6] = T_1_2.num;
    }

  LINE(36);
    {
    err = save_compiler();
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(37);
    { /* return */
    {
    ret_1->tf = true;
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

/**** END PROCEDURE initialize_compiler ****/



/**** BEGIN PROCEDURE initialize_specs ****/

extern errcode basic_name();
extern errcode boolOPnot();
extern errcode file_exists();
extern errcode file_nameOPmake_output();
extern errcode stringOPconcat();
extern errcode file_nameOPunparse();
extern errcode process_commands();
extern errcode stringOPs2ac();
extern errcode fake_stream();
extern errcode ceOPkeep();
extern errcode recordOPget_1();
extern errcode cmpvarOPstuffs();
extern errcode duOPkeep();
static CLUREF STR_Can_047t_040find_040basic_056types_072_040please_040setenv_040CLUHOME_040to_040an_040appropriate_040value;
static CLUREF STR_junk;
static CLUREF STR__043specs_040;
static CLUREF STR__136;
static int initialize_specs_own_init = 0;

errcode
initialize_specs(void)
{
    errcode err;
    CLUREF fn;
    CLUREF ofn;
    CLUREF jcl;
    if (initialize_specs_own_init == 0) {
        stringOPcons("Can\'t find basic.types: please setenv CLUHOME to an appropriate value", CLU_1, CLUREF_make_num(69), &STR_Can_047t_040find_040basic_056types_072_040please_040setenv_040CLUHOME_040to_040an_040appropriate_040value);
        stringOPcons("junk", CLU_1, CLUREF_make_num(4), &STR_junk);
        stringOPcons("#specs ", CLU_1, CLUREF_make_num(7), &STR__043specs_040);
        stringOPcons("^", CLU_1, CLUREF_make_num(1), &STR__136);
        initialize_specs_own_init = 1;
    }
    enter_proc(40);

  LINE(41);
    {
    CLUREF T_1_1;
    err = basic_name(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    fn.num = T_1_1.num;
    }

  LINE(42);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = file_exists(fn, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    T_1_2.num = !T_1_1.num;
    if (T_1_2.num == true) { /* if */

  LINE(43);
        { /* signal */
            elist[0] = STR_Can_047t_040find_040basic_056types_072_040please_040setenv_040CLUHOME_040to_040an_040appropriate_040value;
            signal(ERR_failure);
        }
    }
    } /* end if */

  LINE(44);
    {
    CLUREF T_1_1;
    err = file_nameOPmake_output(fn, STR_junk, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    ofn.num = T_1_1.num;
    }

  LINE(45);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
    CLUREF T_1_5;
    err = file_nameOPunparse(fn, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = stringOPconcat(STR__043specs_040, T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    err = stringOPconcat(T_1_2, STR__136, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    err = file_nameOPunparse(ofn, &T_1_4);
    if (err != ERR_ok)
        goto ex_0;
    err = stringOPconcat(T_1_3, T_1_4, &T_1_5);
    if (err != ERR_ok)
        goto ex_0;
    jcl.num = T_1_5.num;
    }

  LINE(46);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    err = stringOPs2ac(jcl, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = fake_stream(&T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    err = process_commands(T_1_1, T_1_2, CLU_1, &T_1_3);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(47);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = cmpvarOPstuffs(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    T_1_2.num = T_1_1.vec->data[0];
    err = ceOPkeep(T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(48);
    {
    err = duOPkeep();
    if (err != ERR_ok)
        goto ex_0;
    }

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE initialize_specs ****/



/**** BEGIN PROCEDURE save_compiler ****/

extern errcode reset_compiler();
extern errcode cmpvarOPversion();
extern errcode stringOPsize();
extern errcode charOPequal();
extern errcode stringOPfetch();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode dump_compiler();

errcode
save_compiler(void)
{
    errcode err;
    CLUREF vers;
    CLUREF z;
    enter_proc(51);

  LINE(52);
    {
    err = reset_compiler();
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(53);
    {
    CLUREF T_1_1;
    err = cmpvarOPversion(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    vers.num = T_1_1.num;
    }

  LINE(54);
    {
    CLUREF T_1_1;
    err = stringOPsize(vers, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    z.num = T_1_1.num;
    }

  LINE(55);
    { /* if */
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    err = stringOPfetch(vers, z, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    T_1_2.ch = 'X';
    T_1_3.num = (T_1_1.ch == T_1_2.ch);
    if (T_1_3.num == true) { /* if */

  LINE(56);
        {
        CLUREF T_2_1;
        CLUREF T_2_2;
        T_2_1.num = z.num - 1;
        if ((T_2_1.num >= 0 && z.num < 0 && (-1) < 0) ||
            (T_2_1.num <= 0 && z.num > 0 && (-1) > 0)) {
            err = ERR_overflow;
            goto ex_0;
        }
        err = stringOPsubstr(vers, CLU_1, T_2_1, &T_2_2);
        if (err != ERR_ok)
            goto ex_0;
        vers.num = T_2_2.num;
        }

  LINE(57);
        {
        err = cmpvarOPset_version(vers);
        if (err != ERR_ok)
            goto ex_0;
        }
    }
    } /* end if */

  LINE(59);
    {
    err = dump_compiler(vers);
    if (err != ERR_ok)
        goto ex_0;
    }

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE save_compiler ****/



/**** BEGIN PROCEDURE reset_compiler ****/

extern errcode ceOPreset();
extern errcode recordOPset_3();
extern errcode p_envOPreset();
extern errcode recordOPget_12();
extern errcode c_envOPreset();
extern errcode recordOPget_4();
extern errcode g_envOPreset();
extern errcode oneofOPvalue_2();
extern errcode recordOPget_7();
extern errcode xrefOPflush();
extern errcode recordOPget_5();
extern errcode recordOPget_13();
extern errcode arrayOPtrim();
extern errcode recordOPget_10();
static int reset_compiler_own_init = 0;

errcode
reset_compiler(void)
{
    errcode err;
    CLUREF e;
    CLUREF fn;
    CLUREF inst;
    CLUREF outst;
    CLUREF comp;
    if (reset_compiler_own_init == 0) {
        stringOPcons("read", CLU_1, CLUREF_make_num(4), &STR_read);
        stringOPcons("write", CLU_1, CLUREF_make_num(5), &STR_write);
        reset_compiler_own_init = 1;
    }
    enter_proc(62);

  LINE(63);
    {
    CLUREF T_1_1;
    err = cmpvarOPstuffs(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    e.num = T_1_1.num;
    }

  LINE(64);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    err = nul_dev(&T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    err = file_nameOPparse(T_1_1, &T_1_2);
    if (err != ERR_ok)
        goto ex_0;
    fn.num = T_1_2.num;
    }

  LINE(65);
    {
    CLUREF T_1_1;
    err = streamOPopen(fn, STR_read, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    inst.num = T_1_1.num;
    }

  LINE(66);
    {
    CLUREF T_1_1;
    err = streamOPopen(fn, STR_write, &T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    outst.num = T_1_1.num;
    }

  LINE(67);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[0];
    comp.num = T_1_1.num;
    }

  LINE(68);
    {
    err = ceOPreset(comp);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(69);
    {
    e.vec->data[2] = true;
    }

  LINE(70);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[11];
    err = p_envOPreset(T_1_1, comp, outst, inst, CLU_empty_string);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(71);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[3];
    err = c_envOPreset(T_1_1, comp, outst, CLU_empty_string);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(72);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    T_1_1.num = e.vec->data[6];
    if (T_1_1.cell->tag != 2) {
        err = ERR_wrong_tag;
        goto ex_0;
    }
    T_1_2.num = T_1_1.cell->value;
    err = g_envOPreset(T_1_2, comp, outst, fn, fn);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(73);
    {
    err = streamOPclose(inst);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(74);
    {
    err = streamOPclose(outst);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(75);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[4];
    err = xrefOPflush(T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(76);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[12];
    err = xrefOPflush(T_1_1);
    if (err != ERR_ok)
        goto ex_0;
    }

  LINE(77);
    {
    CLUREF T_1_1;
    T_1_1.num = e.vec->data[9];
    err = arrayOPtrim(T_1_1, CLU_1, CLU_0);
    if (err != ERR_ok)
        goto ex_0;
    }

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (err != ERR_failure)
        elist[0] = _pclu_erstr(err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END PROCEDURE reset_compiler ****/

