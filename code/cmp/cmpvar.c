
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN CLUSTER cmpvar ****/

extern errcode binary_suffix();
extern errcode cmpvarOPinit_base_cmd();
extern errcode stringOPempty();
extern errcode file_nameOPcreate();
extern errcode stringOPconcat();
extern errcode _system_root();
extern errcode streamOPopen();
extern errcode streamOPgetl();
extern errcode stringOPindexs();
extern errcode boolOPnot();
extern errcode intOPequal();
extern errcode stringOPsubstr();
extern errcode intOPsub();
extern errcode stringOPrest();
extern errcode intOPadd();
extern errcode streamOPclose();
CLUREF STR_;
CLUREF STR__077_077_077;
CLUREF STR_opt;
CLUREF STR_dbg;
CLUREF STR__057cmp;
CLUREF STR_cc;
CLUREF STR_cmd;
CLUREF STR_read;
CLUREF STR__176CLU;
static int cmpvar_own_init = 0;
OWN_req cmpvar_ownreqs = {0,0};
CLUREF cmpvarOPlocal_vars;
CLUREF cmpvarOPdo_force;
CLUREF cmpvarOPlist_externals;
CLUREF cmpvarOPbinary_dir;
CLUREF cmpvarOPbin_suffix;
CLUREF cmpvarOPallow_errors;
CLUREF cmpvarOPexpunge_specs;
CLUREF cmpvarOPreserved_modules;
CLUREF cmpvarOPcompiler_version;
CLUREF cmpvarOPcompiler_save_date;
CLUREF cmpvarOPcompiler_stuff;
CLUREF cmpvarOPsave_c_files;
CLUREF cmpvarOPbase_cc_opt_cmd_string;
CLUREF cmpvarOPbase_cc_dbg_cmd_string;
CLUREF cmpvarOPcc_opt_cmd_string;
CLUREF cmpvarOPcc_dbg_cmd_string;
errcode cmpvar_own_init_proc()
{
    errcode err;
    enter_own_init_proc();
        if (cmpvar_own_init == 0) {
        stringOPcons("", CLU_1, CLU_0, &STR_);
        stringOPcons("???", CLU_1, CLU_3, &STR__077_077_077);
        stringOPcons("opt", CLU_1, CLU_3, &STR_opt);
        stringOPcons("dbg", CLU_1, CLU_3, &STR_dbg);
        stringOPcons("/cmp", CLU_1, CLU_4, &STR__057cmp);
        stringOPcons("cc", CLU_1, CLU_2, &STR_cc);
        stringOPcons("cmd", CLU_1, CLU_3, &STR_cmd);
        stringOPcons("read", CLU_1, CLU_4, &STR_read);
        stringOPcons("~CLU", CLU_1, CLU_4, &STR__176CLU);
        cmpvar_own_init = 1;
        {
            {cmpvarOPlocal_vars.tf = true;
            }
            }
        {
            {cmpvarOPdo_force.tf = true;
            }
            }
        {
            {cmpvarOPlist_externals.tf = false;
            }
            }
        {
            {cmpvarOPbinary_dir = STR_;
            }
            }
        {
            {CLUREF T_0_1;
            err = binary_suffix(&T_0_1);
            if (err != ERR_ok) goto ex_0;
            cmpvarOPbin_suffix.num = T_0_1.num;
            }
            }
        {
            {cmpvarOPallow_errors.tf = false;
            }
            }
        {
            {cmpvarOPexpunge_specs.tf = false;
            }
            }
        {
            {cmpvarOPreserved_modules = STR_;
            }
            }
        {
            {cmpvarOPcompiler_version = STR__077_077_077;
            }
            }
        {
            {cmpvarOPcompiler_save_date = STR__077_077_077;
            }
            }
        {
            {cmpvarOPsave_c_files.tf = false;
            }
            }
        {
            {CLUREF T_0_2;
            err = cmpvarOPinit_base_cmd(STR_opt, &T_0_2);
            if (err != ERR_ok) goto ex_0;
            cmpvarOPbase_cc_opt_cmd_string.num = T_0_2.num;
            }
            }
        {
            {CLUREF T_0_3;
            err = cmpvarOPinit_base_cmd(STR_dbg, &T_0_3);
            if (err != ERR_ok) goto ex_0;
            cmpvarOPbase_cc_dbg_cmd_string.num = T_0_3.num;
            }
            }
        {
            {cmpvarOPcc_opt_cmd_string.num = cmpvarOPbase_cc_opt_cmd_string.num;
            }
            }
        {
            {cmpvarOPcc_dbg_cmd_string.num = cmpvarOPbase_cc_dbg_cmd_string.num;
            }
            }
        {signal(ERR_ok);}
    ex_0: pclu_unhandled(err); {signal(ERR_failure);}
        }
    }


/**** BEGIN PROCEDURE locals ****/

errcode
cmpvarOPlocals(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(39);

  LINE(40);
    {
    {
    ret_1->num = cmpvarOPlocal_vars.num;
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

/**** END PROCEDURE locals ****/


/**** BEGIN PROCEDURE set_locals ****/

errcode
cmpvarOPset_locals(CLUREF b)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(43);

  LINE(44);
    {
    cmpvarOPlocal_vars.num = b.num;
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

/**** END PROCEDURE set_locals ****/


/**** BEGIN PROCEDURE force_ ****/

errcode
cmpvarOPforce_(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(47);

  LINE(48);
    {
    {
    ret_1->num = cmpvarOPdo_force.num;
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

/**** END PROCEDURE force_ ****/


/**** BEGIN PROCEDURE set_force_ ****/

errcode
cmpvarOPset_force_(CLUREF b)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(51);

  LINE(52);
    {
    cmpvarOPdo_force.num = b.num;
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

/**** END PROCEDURE set_force_ ****/


/**** BEGIN PROCEDURE externals ****/

errcode
cmpvarOPexternals(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(55);

  LINE(56);
    {
    {
    ret_1->num = cmpvarOPlist_externals.num;
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

/**** END PROCEDURE externals ****/


/**** BEGIN PROCEDURE set_externals ****/

errcode
cmpvarOPset_externals(CLUREF b)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(59);

  LINE(60);
    {
    cmpvarOPlist_externals.num = b.num;
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

/**** END PROCEDURE set_externals ****/


/**** BEGIN PROCEDURE dir ****/

errcode
cmpvarOPdir(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(63);

  LINE(64);
    {
    {
    ret_1->num = cmpvarOPbinary_dir.num;
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

/**** END PROCEDURE dir ****/


/**** BEGIN PROCEDURE set_dir ****/

errcode
cmpvarOPset_dir(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(67);

  LINE(68);
    {
    cmpvarOPbinary_dir.num = s.num;
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

/**** END PROCEDURE set_dir ****/


/**** BEGIN PROCEDURE suffix ****/

errcode
cmpvarOPsuffix(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(71);

  LINE(72);
    {
    {
    ret_1->num = cmpvarOPbin_suffix.num;
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

/**** END PROCEDURE suffix ****/


/**** BEGIN PROCEDURE set_suffix ****/

errcode
cmpvarOPset_suffix(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(75);

  LINE(76);
    {
    CLUREF T_1_1;
    err = stringOPempty(s, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    if (T_1_1.num == true) {

  LINE(77);
        {
        CLUREF T_2_1;
        err = binary_suffix(&T_2_1);
        if (err != ERR_ok) goto ex_0;
        s.num = T_2_1.num;
        }
        }
        }/* end if */

  LINE(78);
    {
    cmpvarOPbin_suffix.num = s.num;
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

/**** END PROCEDURE set_suffix ****/


/**** BEGIN PROCEDURE allow ****/

errcode
cmpvarOPallow(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(81);

  LINE(82);
    {
    {
    ret_1->num = cmpvarOPallow_errors.num;
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

/**** END PROCEDURE allow ****/


/**** BEGIN PROCEDURE set_allow ****/

errcode
cmpvarOPset_allow(CLUREF b)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(85);

  LINE(86);
    {
    cmpvarOPallow_errors.num = b.num;
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

/**** END PROCEDURE set_allow ****/


/**** BEGIN PROCEDURE expunge ****/

errcode
cmpvarOPexpunge(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(89);

  LINE(90);
    {
    {
    ret_1->num = cmpvarOPexpunge_specs.num;
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

/**** END PROCEDURE expunge ****/


/**** BEGIN PROCEDURE set_expunge ****/

errcode
cmpvarOPset_expunge(CLUREF b)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(93);

  LINE(94);
    {
    cmpvarOPexpunge_specs.num = b.num;
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

/**** END PROCEDURE set_expunge ****/


/**** BEGIN PROCEDURE modules ****/

errcode
cmpvarOPmodules(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(97);

  LINE(98);
    {
    {
    ret_1->num = cmpvarOPreserved_modules.num;
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

/**** END PROCEDURE modules ****/


/**** BEGIN PROCEDURE set_modules ****/

errcode
cmpvarOPset_modules(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(101);

  LINE(102);
    {
    cmpvarOPreserved_modules.num = s.num;
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

/**** END PROCEDURE set_modules ****/


/**** BEGIN PROCEDURE version ****/

errcode
cmpvarOPversion(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(105);

  LINE(106);
    {
    {
    ret_1->num = cmpvarOPcompiler_version.num;
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

/**** END PROCEDURE version ****/


/**** BEGIN PROCEDURE set_version ****/

errcode
cmpvarOPset_version(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(109);

  LINE(110);
    {
    cmpvarOPcompiler_version.num = s.num;
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

/**** END PROCEDURE set_version ****/


/**** BEGIN PROCEDURE date ****/

errcode
cmpvarOPdate(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(113);

  LINE(114);
    {
    {
    ret_1->num = cmpvarOPcompiler_save_date.num;
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

/**** END PROCEDURE date ****/


/**** BEGIN PROCEDURE set_date ****/

errcode
cmpvarOPset_date(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(117);

  LINE(118);
    {
    cmpvarOPcompiler_save_date.num = s.num;
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

/**** END PROCEDURE set_date ****/


/**** BEGIN PROCEDURE stuffs ****/

errcode
cmpvarOPstuffs(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(121);

  LINE(122);
    {
    {
    ret_1->num = cmpvarOPcompiler_stuff.num;
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

/**** END PROCEDURE stuffs ****/


/**** BEGIN PROCEDURE set_stuffs ****/

errcode
cmpvarOPset_stuffs(CLUREF s)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(125);

  LINE(126);
    {
    cmpvarOPcompiler_stuff.num = s.num;
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

/**** END PROCEDURE set_stuffs ****/


/**** BEGIN PROCEDURE save_c ****/

errcode
cmpvarOPsave_c(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(129);

  LINE(130);
    {
    {
    ret_1->num = cmpvarOPsave_c_files.num;
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

/**** END PROCEDURE save_c ****/


/**** BEGIN PROCEDURE set_save_c ****/

errcode
cmpvarOPset_save_c(CLUREF save)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(133);

  LINE(134);
    {
    cmpvarOPsave_c_files.num = save.num;
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

/**** END PROCEDURE set_save_c ****/


/**** BEGIN PROCEDURE cc_opt_cmd ****/

errcode
cmpvarOPcc_opt_cmd(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(137);

  LINE(138);
    {
    {
    ret_1->num = cmpvarOPcc_opt_cmd_string.num;
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

/**** END PROCEDURE cc_opt_cmd ****/


/**** BEGIN PROCEDURE cc_dbg_cmd ****/

errcode
cmpvarOPcc_dbg_cmd(CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(141);

  LINE(142);
    {
    {
    ret_1->num = cmpvarOPcc_dbg_cmd_string.num;
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

/**** END PROCEDURE cc_dbg_cmd ****/


/**** BEGIN PROCEDURE set_cc_opt_cmd ****/

errcode
cmpvarOPset_cc_opt_cmd(CLUREF cmd)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(145);

  LINE(146);
    {
    CLUREF T_1_1;
    err = stringOPempty(cmd, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    if (T_1_1.num == true) {
        {
        cmpvarOPcc_opt_cmd_string.num = cmpvarOPbase_cc_opt_cmd_string.num;
        }
        }
    else {

  LINE(147);
        {
        cmpvarOPcc_opt_cmd_string.num = cmd.num;
        }
        }}/* end if */
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE set_cc_opt_cmd ****/


/**** BEGIN PROCEDURE set_cc_dbg_cmd ****/

errcode
cmpvarOPset_cc_dbg_cmd(CLUREF cmd)
    {
    errcode err;
    errcode ecode2;
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
    enter_proc(150);

  LINE(151);
    {
    CLUREF T_1_1;
    err = stringOPempty(cmd, &T_1_1);
    if (err != ERR_ok) goto ex_0;
    if (T_1_1.num == true) {
        {
        cmpvarOPcc_dbg_cmd_string.num = cmpvarOPbase_cc_dbg_cmd_string.num;
        }
        }
    else {

  LINE(152);
        {
        cmpvarOPcc_dbg_cmd_string.num = cmd.num;
        }
        }}/* end if */
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: {signal(ERR_ok);}
    }

/**** END PROCEDURE set_cc_dbg_cmd ****/

static int cmpvarOPinit_base_cmd_own_init = 0;

/**** BEGIN PROCEDURE init_base_cmd ****/

errcode
cmpvarOPinit_base_cmd(CLUREF ty, CLUREF *ret_1)
    {
    errcode err;
    errcode ecode2;
    CLUREF fn;
    CLUREF st;
    CLUREF line;
    CLUREF pos;
        if (cmpvarOPinit_base_cmd_own_init == 0) {
        if (cmpvar_own_init == 0) {
            err = cmpvar_own_init_proc();
            if (err != ERR_ok) goto ex_0;
            }
        cmpvarOPinit_base_cmd_own_init = 1;
    }
    enter_proc(155);

  LINE(156);
    {

  LINE(157);
        {
            {CLUREF T_3_1;
            CLUREF T_3_2;
            CLUREF T_3_3;
            CLUREF T_3_4;
            err = _system_root(&T_3_1);
            if (err != ERR_ok) goto ex_1;
            err = stringOPconcat(T_3_1, STR__057cmp, &T_3_2);
            if (err != ERR_ok) goto ex_1;
            err = stringOPconcat(STR_cc, ty, &T_3_3);
            if (err != ERR_ok) goto ex_1;
            err = file_nameOPcreate(T_3_2, T_3_3, STR_cmd, STR_, &T_3_4);
            if (err != ERR_ok) goto ex_1;
            fn.num = T_3_4.num;
            }
            }

  LINE(159);
        {
            {CLUREF T_3_1;
            err = streamOPopen(fn, STR_read, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            st.num = T_3_1.num;
            }
            }

  LINE(160);
        {
            {CLUREF T_3_1;
            err = streamOPgetl(st, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            line.num = T_3_1.num;
            }
            }

  LINE(161);
        {
            {CLUREF T_3_1;
            err = stringOPindexs(STR__176CLU, line, &T_3_1);
            if (err != ERR_ok) goto ex_1;
            pos.num = T_3_1.num;
            }
            }

  LINE(162);
        {
        CLUREF T_3_1;
        CLUREF T_3_2;
        T_3_1.num = (pos.num == 0)? true : false;
        T_3_2.num = T_3_1.num ^ 1;
        if (T_3_2.num == true) {

  LINE(163);
            {
            CLUREF T_4_1;
            CLUREF T_4_2;
            CLUREF T_4_3;
            CLUREF T_4_4;
            CLUREF T_4_5;
            CLUREF T_4_6;
            CLUREF T_4_7;
            T_4_1.num = pos.num - 1;
             if ((T_4_1.num >= 0 && pos.num < 0 && (-1) < 0) ||
                 (T_4_1.num <= 0 && pos.num > 0 && (-1) > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            err = stringOPsubstr(line, CLU_1, T_4_1, &T_4_2);
            if (err != ERR_ok) goto ex_1;
            err = _system_root(&T_4_3);
            if (err != ERR_ok) goto ex_1;
            err = stringOPconcat(T_4_2, T_4_3, &T_4_4);
            if (err != ERR_ok) goto ex_1;
            T_4_5.num = pos.num + 4;
             if ((T_4_5.num > 0 && pos.num < 0 && 4 < 0) ||
                 (T_4_5.num < 0 && pos.num > 0 && 4 > 0)) {
                err = ERR_overflow;
                goto ex_1;}
            err = stringOPrest(line, T_4_5, &T_4_6);
            if (err != ERR_ok) goto ex_1;
            err = stringOPconcat(T_4_4, T_4_6, &T_4_7);
            if (err != ERR_ok) goto ex_1;
            line.num = T_4_7.num;
            }
            }
            }/* end if */

  LINE(166);
        {
        err = streamOPclose(st);
        if (err != ERR_ok) goto ex_1;
        }

  LINE(167);
        {
        {
        ret_1->num = line.num;
        }
        {signal (ERR_ok);}}
        }
        goto end_1;
        ex_1:
            {

  LINE(169);
                {
                {
                ret_1->str = STR_.str;
                }
                {signal (ERR_ok);}}
            }
        end_1:;
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

/**** END PROCEDURE init_base_cmd ****/

typedef struct{
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[28];
} cmpvar_OPS;

CLU_proc cmpvar_oe_allow = {{0,0,0,0}, cmpvarOPallow, 0};
CLU_proc cmpvar_oe_cc_dbg_cmd = {{0,0,0,0}, cmpvarOPcc_dbg_cmd, 0};
CLU_proc cmpvar_oe_cc_opt_cmd = {{0,0,0,0}, cmpvarOPcc_opt_cmd, 0};
CLU_proc cmpvar_oe_date = {{0,0,0,0}, cmpvarOPdate, 0};
CLU_proc cmpvar_oe_dir = {{0,0,0,0}, cmpvarOPdir, 0};
CLU_proc cmpvar_oe_expunge = {{0,0,0,0}, cmpvarOPexpunge, 0};
CLU_proc cmpvar_oe_externals = {{0,0,0,0}, cmpvarOPexternals, 0};
CLU_proc cmpvar_oe_force_ = {{0,0,0,0}, cmpvarOPforce_, 0};
CLU_proc cmpvar_oe_locals = {{0,0,0,0}, cmpvarOPlocals, 0};
CLU_proc cmpvar_oe_modules = {{0,0,0,0}, cmpvarOPmodules, 0};
CLU_proc cmpvar_oe_save_c = {{0,0,0,0}, cmpvarOPsave_c, 0};
CLU_proc cmpvar_oe_set_allow = {{0,0,0,0}, cmpvarOPset_allow, 0};
CLU_proc cmpvar_oe_set_cc_dbg_cmd = {{0,0,0,0}, cmpvarOPset_cc_dbg_cmd, 0};
CLU_proc cmpvar_oe_set_cc_opt_cmd = {{0,0,0,0}, cmpvarOPset_cc_opt_cmd, 0};
CLU_proc cmpvar_oe_set_date = {{0,0,0,0}, cmpvarOPset_date, 0};
CLU_proc cmpvar_oe_set_dir = {{0,0,0,0}, cmpvarOPset_dir, 0};
CLU_proc cmpvar_oe_set_expunge = {{0,0,0,0}, cmpvarOPset_expunge, 0};
CLU_proc cmpvar_oe_set_externals = {{0,0,0,0}, cmpvarOPset_externals, 0};
CLU_proc cmpvar_oe_set_force_ = {{0,0,0,0}, cmpvarOPset_force_, 0};
CLU_proc cmpvar_oe_set_locals = {{0,0,0,0}, cmpvarOPset_locals, 0};
CLU_proc cmpvar_oe_set_modules = {{0,0,0,0}, cmpvarOPset_modules, 0};
CLU_proc cmpvar_oe_set_save_c = {{0,0,0,0}, cmpvarOPset_save_c, 0};
CLU_proc cmpvar_oe_set_stuffs = {{0,0,0,0}, cmpvarOPset_stuffs, 0};
CLU_proc cmpvar_oe_set_suffix = {{0,0,0,0}, cmpvarOPset_suffix, 0};
CLU_proc cmpvar_oe_set_version = {{0,0,0,0}, cmpvarOPset_version, 0};
CLU_proc cmpvar_oe_stuffs = {{0,0,0,0}, cmpvarOPstuffs, 0};
CLU_proc cmpvar_oe_suffix = {{0,0,0,0}, cmpvarOPsuffix, 0};
CLU_proc cmpvar_oe_version = {{0,0,0,0}, cmpvarOPversion, 0};

cmpvar_OPS cmpvar_ops_actual = {28, (OWNPTR)&cmpvar_own_init, (OWNPTR)&cmpvar_own_init, {
    {&cmpvar_oe_allow, "allow"},
    {&cmpvar_oe_cc_dbg_cmd, "cc_dbg_cmd"},
    {&cmpvar_oe_cc_opt_cmd, "cc_opt_cmd"},
    {&cmpvar_oe_date, "date"},
    {&cmpvar_oe_dir, "dir"},
    {&cmpvar_oe_expunge, "expunge"},
    {&cmpvar_oe_externals, "externals"},
    {&cmpvar_oe_force_, "force_"},
    {&cmpvar_oe_locals, "locals"},
    {&cmpvar_oe_modules, "modules"},
    {&cmpvar_oe_save_c, "save_c"},
    {&cmpvar_oe_set_allow, "set_allow"},
    {&cmpvar_oe_set_cc_dbg_cmd, "set_cc_dbg_cmd"},
    {&cmpvar_oe_set_cc_opt_cmd, "set_cc_opt_cmd"},
    {&cmpvar_oe_set_date, "set_date"},
    {&cmpvar_oe_set_dir, "set_dir"},
    {&cmpvar_oe_set_expunge, "set_expunge"},
    {&cmpvar_oe_set_externals, "set_externals"},
    {&cmpvar_oe_set_force_, "set_force_"},
    {&cmpvar_oe_set_locals, "set_locals"},
    {&cmpvar_oe_set_modules, "set_modules"},
    {&cmpvar_oe_set_save_c, "set_save_c"},
    {&cmpvar_oe_set_stuffs, "set_stuffs"},
    {&cmpvar_oe_set_suffix, "set_suffix"},
    {&cmpvar_oe_set_version, "set_version"},
    {&cmpvar_oe_stuffs, "stuffs"},
    {&cmpvar_oe_suffix, "suffix"},
    {&cmpvar_oe_version, "version"}}};

struct OPS *cmpvar_ops = (struct OPS *)&cmpvar_ops_actual;

/**** END CLUSTER cmpvar ****/
