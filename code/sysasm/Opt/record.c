
/* Copyright Massachusetts Institute of Technology 1990,1991 */

#ifndef lint
static char rcsid[] = "$Header: /pm/src/site/pclu/code/base/RCS/record.c,v 1.7 91/08/29 16:02:10 dcurtis Exp $";
#endif
/* $Log:	record.c,v $
 * Revision 1.7  91/08/29  16:02:10  dcurtis
 * fixed casting on arguments to bcopy
 * 
 * Revision 1.6  91/08/29  15:00:56  dcurtis
 * removed elist from oneofOPnew call
 * 
 * Revision 1.5  91/06/06  13:30:22  root
 * added copyright notice
 * 
 * Revision 1.4  91/06/05  13:26:09  root
 * added elist to sequence$new2
 * 
 * Revision 1.3  91/06/03  14:54:35  root
 * sparcstation compatibility: int->CLUREF
 * 
 * Revision 1.2  91/05/31  12:33:23  root
 * fixed aggregate initialization in ops_actual
 * changed an argument from int to CLUREF
 * removed unused variable
 * added result variable to pstream calls
 * added start & length arguments to string$cons calls
 * 
 * Revision 1.1  91/02/04  15:49:51  mtv
 * Initial revision
 * 
 */

/*							*/
/*		RECORD IMPLEMENTATION			*/
/*							*/

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode recordOPprint();

errcode recordOPnew(size, ans)
CLUREF size;
CLUREF *ans;
{
errcode err;
CLUREF temp;

	clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &temp);
	temp.vec->typ.mark = 0;
	temp.vec->typ.val = CT_REC;
	temp.vec->typ.refp = 0;
	temp.vec->typ.spare = 0;
	temp.vec->size = size.num;
	ans->vec = temp.vec;
	signal(ERR_ok);
	}


errcode recordOPcopy(record, ans)
CLUREF record, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to copy fcns */
errcode err;
CLUREF temp;
CLUREF size, e1, e2;
long i;

	size.num = record.vec->size;
	clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &temp);
	temp.vec->typ.mark = 0;
	temp.vec->typ.val = CT_REC;
	temp.vec->typ.refp = 0;
	temp.vec->typ.spare = 0;
	temp.vec->size = size.num;
	for (i = 0; i < size.num ; i++) {
		e1.num = record.vec->data[i];
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(e1, &e2);
		temp.vec->data[i] = e2.num;
		if (err != ERR_ok) resignal(err);
		}
	ans->vec = temp.vec;
	signal(ERR_ok);
}

errcode recordOPcopy1(record, ans)
CLUREF record, *ans;
{
errcode err;
CLUREF temp;
CLUREF size;
long i;

	size.num = record.vec->size;
	clu_alloc((size.num - 1)* (sizeof(CLUREF)) + sizeof(CLU_sequence), &temp);
	temp.vec->typ.mark = 0;
	temp.vec->typ.val = CT_REC;
	temp.vec->typ.refp = 0;
	temp.vec->typ.spare = 0;
	temp.vec->size = record.vec->size;
	for (i = 0; i < record.vec->size; i++) 
		temp.vec->data[i] = record.vec->data[i];
	ans->vec = temp.vec;
	signal(ERR_ok);
	}

errcode recordOPsimilar(rec1, rec2, ans)
CLUREF rec1, rec2, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to similar fcns */
long i;
errcode err;
CLUREF e1, e2;

	if (rec1.vec->size != rec2.vec->size) {
			ans->tf = false;
			signal(ERR_ok);
			}
	for (i = 0; i < rec1.vec->size; i++) {
		e1.num = rec1.vec->data[i];
		e2.num = rec2.vec->data[i];
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(e1, e2, ans);
		if (err != ERR_ok) resignal(err);
		if (ans->tf == false) signal(ERR_ok);
		}
	signal(ERR_ok);
	}

errcode recordOP_gcd(rec, tab, ans)
CLUREF rec, tab, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to _gcd fcns */
long i;
errcode err;
CLUREF temp_oneof, temp_seq, temp_seq_data, sz;

	sz.num = rec.vec->size;
	sequenceOPnew2(sz, &temp_seq);
	for (i = 0; i < rec.vec->size; i++) {
		temp_seq.vec->data[i] = (long)table[i];
		}
	err = oneofOPnew(CLU_3, temp_seq, &temp_oneof);
	if (err != ERR_ok) resignal(err);
	sz.num = 2*CLUREFSZ + (rec.vec->size * GCD_REF_SIZE);
	err = gcd_tabOPinsert(tab, sz, temp_oneof, rec, ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}

errcode recordOPequal(rec1, rec2, ans)
CLUREF rec1, rec2, *ans;
{
	if (rec1.ref == rec2.ref) ans->tf = true;
	else ans->tf = false;	
	signal(ERR_ok);
	}

errcode recordOPr_gets_r(rec1, rec2)
CLUREF rec1, rec2;
{
	bcopy((char*)rec2.vec->data, (char*)rec1.vec->data, rec1.vec->size*CLUREFSZ);
	signal(ERR_ok);
	}

errcode recordOPr_gets_s(rec1, rec2)
CLUREF rec1, rec2;
{
	bcopy((char*)rec2.vec->data, (char*)rec1.vec->data, rec1.vec->size*CLUREFSZ);
	signal(ERR_ok);
	}


errcode recordOPdebug_print(rec, pst)
CLUREF rec, pst;
{
errcode err;
	err = recordOPprint(rec, pst);  /* assumes CUR_PROC_VAR is ok */
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}

errcode recordOPprint(rec, pst)
CLUREF rec, pst;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to print fcns */
char **table2 = (char**)(table+rec.vec->size); /* ptr to field names */
long i;
errcode err;
CLUREF temp_str, temp_str2, temp_str3, e1;
CLUREF size, ans;

	err = stringOPcons("{", CLU_1, CLU_1, &temp_str);
	if (err != ERR_ok) resignal(err);
	err = pstreamOPstart(pst, temp_str, &ans);
	if (err != ERR_ok) resignal(err);
	if (ans.tf == false) goto done;
	err = stringOPcons(",", CLU_1, CLU_1, &temp_str);
	if (err != ERR_ok) resignal(err);
	err = stringOPcons(": ", CLU_1, CLU_2, &temp_str2);
	if (err != ERR_ok) resignal(err);
	for (i = 0; i < rec.vec->size; i++) {
		if (i != 0) {
			err = pstreamOPpause(pst, temp_str, &ans);
			if (err != ERR_ok) resignal(err);
			if (ans.tf == false) break;
			}
		size.num = strlen(table2[i]);
		stringOPcons(table2[i], CLU_1, size, &temp_str3);
		err = pstreamOPtext(pst, temp_str3, &ans);
		if (err != ERR_ok) resignal(err);
		err = pstreamOPtext(pst, temp_str2, &ans);
		if (err != ERR_ok) resignal(err);
		e1.num = rec.vec->data[i];
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(e1, pst);
		if (err != ERR_ok) resignal(err);
		}
done:
	err = stringOPcons("}", CLU_1, CLU_1, &temp_str);
	if (err != ERR_ok) resignal(err);
	err = pstreamOPstop(pst, temp_str, &ans);
	if (err != ERR_ok) resignal(err);
	signal(ERR_ok);
	}


errcode recordOPencode(rec, ist)
CLUREF rec, ist;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to encode fcns */
long i;
errcode err;
CLUREF e1;

        err = istreamOPputi(ist, rec.vec->size);
        if (err == ERR_not_possible) signal(err);
        if (err != ERR_ok) resignal(err);
	for (i = 0; i < rec.vec->size; i++) {
		e1.num = rec.vec->data[i];
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(e1, ist);
		if (err == ERR_not_possible) signal(err);
		if (err != ERR_ok) resignal(err);
		}
	signal(ERR_ok);
	}

errcode recordOPdecode(ist, ans)
CLUREF ist, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; /* ptr to decode fcns */
long i;
errcode err;
CLUREF temp, size;

        err = istreamOPgeti(ist, &size);
        if (err == ERR_not_possible) signal(err);
        if (err == ERR_end_of_file) signal(err);
        if (err != ERR_ok) resignal(err);
	err = recordOPnew(size, &temp);
	if (err != ERR_ok) resignal(err);
	for (i = 0; i < temp.vec->size; i++) {
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(ist, &temp.vec->data[i]);
		if (err == ERR_not_possible) signal(err);
		if (err == ERR_end_of_file) signal(err);
		if (err != ERR_ok) resignal(err);
		}
	ans->vec = temp.vec;
	signal(ERR_ok);
	}


errcode recordOPsimilar1(rec1, rec2, ans)
CLUREF rec1, rec2, *ans;
{
CLUPROC *table = (CLUPROC*)CUR_PROC_VAR.proc->op_owns->info; 
long i;
errcode err;
CLUREF e1, e2;

	if (rec1.vec->size != rec2.vec->size) {
			ans->tf = false;
			signal(ERR_ok);
			}
	for (i = 0; i < rec1.vec->size; i++) {
		e1.num = rec1.vec->data[i];
		e2.num = rec2.vec->data[i];
		CUR_PROC_VAR.proc = (CLUPROC)table[i];
		err = table[i]->proc(e1, e2, ans);
		if (err != ERR_ok) resignal(err);
		if (ans->tf == false) signal(ERR_ok);
		}
	signal(ERR_ok);
	}


typedef struct {
PROC *fcn;
char *name;
} SEL_ENTRY;

typedef struct {
long count;
OWNPTR	type_owns;
OWNPTR  op_owns;
struct OP_ENTRY entry[8];
} selector_OPS;

typedef struct {
long count;
OWNPTR	type_owns;
OWNPTR  op_owns;
struct OP_ENTRY equal;
struct OP_ENTRY copy;
struct OP_ENTRY similar;
struct OP_ENTRY print;
struct OP_ENTRY encode;
struct OP_ENTRY decode;
struct OP_ENTRY _gcd;
struct OP_ENTRY debug_print;
} selector_TABLE;

OWN_ptr record_own_init = {0, 0};

CLU_proc record_oe_equal = {{0,0,0,0}, recordOPequal, &record_own_init, &record_own_init};
CLU_proc record_oe_copy = {{0,0,0,0}, recordOPcopy, &record_own_init, &record_own_init};
CLU_proc record_oe_similar = {{0,0,0,0}, recordOPsimilar, &record_own_init, &record_own_init};
CLU_proc record_oe_print = {{0,0,0,0}, recordOPprint, &record_own_init, &record_own_init};
CLU_proc record_oe_encode = {{0,0,0,0}, recordOPencode, &record_own_init, &record_own_init};
CLU_proc record_oe_decode = {{0,0,0,0}, recordOPdecode, &record_own_init, &record_own_init};
CLU_proc record_oe__gcd = {{0,0,0,0}, recordOP_gcd, &record_own_init, &record_own_init};
CLU_proc record_oe_debug_print = {{0,0,0,0}, recordOPdebug_print, &record_own_init, &record_own_init};

selector_OPS record_ops_actual = {8, 
&record_own_init,
&record_own_init, {
{&record_oe_equal, "equal"},
{&record_oe_copy, "copy"}, 
{&record_oe_similar, "similar"},
{&record_oe_print, "print"},
{&record_oe_encode, "encode"},
{&record_oe_decode, "decode"},
{&record_oe__gcd, "_gcd"},
{&record_oe_debug_print, "debug_print"}
}};

selector_OPS *record_ops = &record_ops_actual;

