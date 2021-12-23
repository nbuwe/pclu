
/* This file was automatically generated by pclu. */

#include "pclu_err.h"
#include "pclu_sys.h"


/**** BEGIN ITERATOR all_file_names ****/

extern errcode _all_file_names_();
static errcode all_file_names_IB_1();
typedef struct {
    void *user_locals;
    errcode (*proc)();
    errcode ecode2;
    errcode err;
    bool body_ctrl_req;
    CLUREF first;
    CLUREF fn;
    CLUREF fs;
} all_file_names_LOCALS_t;

errcode
all_file_names(CLUREF fs, errcode (*proc)(), void *user_locals, errcode *iecode)
{
    errcode ecode __CLU_UNUSED;
    all_file_names_LOCALS_t locals;
    locals.fs = fs;
    locals.proc = proc;
    locals.user_locals = user_locals;
    enter_proc(6);

  LINE(8);
    {
    locals.first.tf = true;
    }

  LINE(9);
    { /* for */
        locals.body_ctrl_req = false;
        locals.err = _all_file_names_(locals.fs, all_file_names_IB_1, &locals, &locals.ecode2);

        if (locals.err == ERR_iterbodyreturn)
            signal(ERR_iterbodyreturn);
        if (locals.err == ERR_iterbodysignal) {
            *iecode = locals.ecode2;
            signal(ERR_iterbodysignal);
        }
        if (locals.err == ERR_iterbodyexit) {
            *iecode = locals.ecode2;
            signal(ERR_iterbodyexit);
        }
        if (locals.body_ctrl_req) {
            locals.body_ctrl_req = false;
            if (locals.err == ERR_iteriterbodyreturn)
                signal(ERR_ok);
            if (locals.err == ERR_iteriterbodysignal)
                signal(locals.ecode2);
            if (locals.err == ERR_break)
                locals.err = ERR_ok;
            if (locals.err == ERR_iteriterbodyexit)
                locals.err = locals.ecode2;
        }
        else {
            if (locals.err == ERR_iteriterbodyreturn)
                signal(ERR_iteriterbodyreturn);
            if (locals.err == ERR_break)
                signal(ERR_break);
            if (locals.err == ERR_iteriterbodysignal) {
                *iecode = locals.ecode2;
                signal(ERR_iteriterbodysignal);
            }
            if (locals.err == ERR_iteriterbodyexit) {
                *iecode = locals.ecode2;
                signal(ERR_iteriterbodyexit);
            }
        }
        if (locals.err != ERR_ok)
            goto ex_1;
    }
    goto end_1;
  ex_1: /* resignal */
    __CLU_EX_HANDLER;
    if (locals.err == ERR_bad_format)
        signal(locals.err);
    else if (locals.err == ERR_not_possible)
        signal(locals.err);
    else
        goto ex_0;
  end_1:;

  LINE(13);
    { /* if */
    if (locals.first.num == true) { /* if */

  LINE(14);
        { /* signal */
            signal(ERR_none);
        }
    }
    } /* end if */

    goto end_0;
  ex_0:
    __CLU_EX_HANDLER;
    if (locals.err != ERR_failure)
        elist[0] = _pclu_erstr(locals.err);
    signal(ERR_failure);
  end_0:
    signal(ERR_ok);
}

/**** END ITERATOR all_file_names ****/


/**** BEGIN ITERATOR BODIES for all_file_names ****/

static errcode
all_file_names_IB_1(CLUREF iv_1, all_file_names_LOCALS_t *locals, errcode *iecode)
{
    locals->fn.num = iv_1.num;
    enter_iter_body_proc(10);

  FB_LINE(10);
    {
    locals->first.tf = false;
    }

  FB_LINE(11);
    { /* yield */
    locals->err = (*locals->proc)(locals->fn, locals->user_locals, iecode);
    if (locals->body_ctrl_req && locals->err == ERR_iteriterbodyexit) {
        locals->err = *iecode;
        goto ex_0;
    }
    if (locals->err != ERR_ok) {
        signal(locals->err);
    }
    }

    signal(ERR_ok);
  ex_0:
    __CLU_EX_HANDLER;
    *iecode = locals->err;
    locals->body_ctrl_req = true;
    signal(ERR_iteriterbodyexit);
  end_0:
    __CLU_END_LABEL;
    signal(ERR_ok);
}

/**** END ITERATOR BODIES for all_file_names ****/

