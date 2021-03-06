#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdarg.h>
#include <stdio.h>

#define MAX_ARGS 15
#define MAX_DBG_VARS 30
#define UNUSED 0
#define USED 1
#define NO_SPACE -1
#define HIGHLY_UNLIKELY 0xfffff003

/* No CLUREFs should have an odd address, and 0xfffff003 isn't a likely real
   or int, so hopefully this will work.  (This is somewhat of a hack, I admit.)
   */

/* This procedure is used to call clu procedures from within a debugger.
   Memory is allocated for the return results, and the address of the allocated
   space is entered in the CLUREF array ca[].  When the procedure has
   executed, the addresses of these return results are printed on the standard
   C output (which will be different from the standard clu output), so that the
   clu debugger can access these results for subsequent procedure calls, or
   to print the value of the variable for the user.  It is up to the clu
   debugger to know (or guess) the type of the return results.

   If the procedure call results in an error, this procedure will print:
   	Signals: %s.
   Where %s is the error message.

   */

typedef struct debug_val {
  CLUREF val;
  long used;
} debugger_variable;

debugger_variable dv[MAX_DBG_VARS];

/* This is permanent space for debugger variables.  Up to MAX_DBG_VARS can be
   stored at once.  They must be kept as global variables so that they won't
   get erased from the stack, and won't be erased by the garbage collector. */

/* debug_alloc searches through dv[] for a free space.  If it finds one, it
   returns the index in the variable dv[].  Otherwise, returns NO_SPACE.
   debug_dealloc takes the address of the allocated space and marks the
   debugger variable as free for use. */

long debug_alloc()
{	long i;
	for (i=0; i < MAX_DBG_VARS; i++ ){
	  if (dv[i].used == UNUSED){
	    dv[i].used = USED;
	    return( i );
	  }
	}
	printf("Failure: Too many debugger variables (%d).\n", MAX_DBG_VARS );
	return( NO_SPACE );
      }


errcode debug_dealloc( address )
debugger_variable *address;
{	address->val.num = 0;
	address->used = UNUSED;
	signal( ERR_ok );
      }


/* Here's the plan.  An iterator takes its call arguments, the address of
   a procedure to call for each iteration of the loop, the address of the
   local variables of the routine that's calling the iterator, and some error
   code information.  The iterator then calls the iterator body once for
   every yielded value (or set of values) in the format:
   ib( yield1, yield2, ..., locals, iecode );

   The variable number of arguments makes the situation difficult.  However,
   within the context of the debugger, there's never going to be an
   iterator body, nor any local variables.  So, we pass the iterator some
   HIGHLY_UNLIKELY value which will signify the end of the yield values.

   The yield values are then copied into permanent non-garbage-collect storage,
   and printed, just as for call_clu.  Since an iterator could easily yield
   hundreds of values, it is important that the pclu debugger deallocate this
   storage after each iteration, unless it needs to be saved for a debugger
   variable.
   */
extern errcode iter_yieldOPprint();
static long iter_count = 0;
static long iter_val_count = 0;

errcode
iterbody_proc(long first, ...)
{
  va_list ap;
  long temp, i, ind;

  va_start(ap, first);
  temp = first;

  for (i=1; i <= iter_val_count ; i++)     /* formerly limited by HIGHLY_UNLIKELY */
    {
      ind = debug_alloc();
      if (ind == NO_SPACE) signal( ERR_failure );
      dv[ind].val.num = temp;
/*      printf( "Iter Pass %d, Yield value %d: %d\n",
		iter_count, i, dv[ind].val.num); */
      iter_yieldOPprint(temp, i);
      temp = va_arg(ap, long);
    }

  /* We can just ignore the rest of the parameters, since we won't need to
     modify the errlist or write anything in ecode2.
     iter_elist = va_arg( ap, errlist );
     ecode2 = va_arg( ap, errcode );
     */

  va_end(ap);
  iter_count++;

  /* Here, need to do an input or something so you don't continue execution
     until the pclu debugger is ready for you again. */
  return ERR_ok;
}

#undef errcmp
extern bool errcmp();
extern errcode errcmp2();
extern errcode _pclu_erstr2();

errcode call_clu( proc_ptr_ref, type_ops_ref, op_ops_ref, stack, sp,
		is_iter, is_sel, num_args, num_ret)
CLUREF proc_ptr_ref;
CLUREF type_ops_ref, op_ops_ref;
CLUREF stack;
CLUREF sp;
CLUREF is_iter;
CLUREF is_sel;
CLUREF num_args, num_ret;
{
PROC *proc_ptr = (PROC *)proc_ptr_ref.num;
struct OPS *type_ops = (struct OPS*)type_ops_ref.ref;
struct OPS *op_ops = (struct OPS*)op_ops_ref.ref;
	CLUREF ca[MAX_ARGS];

	static struct {
	  long type_owns;
	  OWNPTR op_owns;
	  struct OPS *table[MAX_ARGS];
	  errcode (*proc)();
	} generic_CLU_proc;

	errcode err, ecode2;
	long i, total_args, ind, kk;

	for (i = 0; i < num_args.num; i++){
		ca[i].num  = stack.vec->data[sp.num+i-1];
	      }
	/* Copy each of the following arguments into ca[0..num_args.num-1] */

	if (is_iter.tf != true){
	  ind = 0;
	  for (i = num_args.num; i < num_args.num + num_ret.num; i++, ind++){
		ca[i].ref = (char*)&dv[ind].val;
	      }
	  total_args = num_args.num + num_ret.num;
        }
	else {
	  ca[ num_args.num ].ref = (char*)iterbody_proc;
	  ca[ num_args.num + 1 ].num = HIGHLY_UNLIKELY;
	  ca[ num_args.num + 3 ].ref = (char*)&ecode2;
	  total_args = num_args.num + 3;
	  iter_count = 1;
	  iter_val_count = num_ret.num;
	}
	if (type_ops != (struct OPS *)NULL)
		CUR_PROC_VAR.proc->type_owns = type_ops->type_owns;
	if (op_ops != (struct OPS *)NULL) {
		if (is_sel.tf) {
			for (kk = 0 ; kk < type_ops->count ; kk++) {
				if (type_ops->entry[kk].fcn->proc == proc_ptr)
					CUR_PROC_VAR.proc->op_owns =
						type_ops->entry[kk].fcn->op_owns;
				}
			}
		else CUR_PROC_VAR.proc->op_owns = op_ops->op_owns;
		}
#ifdef sparc
	switch (num_args.num) {
	case 0:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ); break;
		case 1: err = proc_ptr( &ca[0] ); break;
		case 2: err = proc_ptr( &ca[0], &ca[1] ); break;
		case 3: err = proc_ptr( &ca[0], &ca[1], &ca[2] ); break;
		case 4: err = proc_ptr( &ca[0], &ca[1], &ca[2], &ca[3] ); break;
		case 5: err = proc_ptr( &ca[0], &ca[1], &ca[2], &ca[3], &ca[4] ); break;
		default: printf("Too many return values\n"); break;
		} break;
	case 1:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ca[0] ); break;
		case 1: err = proc_ptr( ca[0], &ca[1] ); break;
		case 2: err = proc_ptr( ca[0], &ca[1], &ca[2] ); break;
		case 3: err = proc_ptr( ca[0], &ca[1], &ca[2], &ca[3] ); break;
		case 4: err = proc_ptr( ca[0], &ca[1], &ca[2], &ca[3],
				&ca[4] ); break;
		case 5: err = proc_ptr( ca[0], &ca[1], &ca[2], &ca[3],
				&ca[4], &ca[5] ); break;
		default: printf("Too many return values\n"); break;
		} break;
	case 2:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ca[0], ca[1] ); break;
		case 1: err = proc_ptr( ca[0], ca[1], &ca[2] ); break;
		case 2: err = proc_ptr( ca[0], ca[1], &ca[2], &ca[3] ); break;
		case 3: err = proc_ptr( ca[0], ca[1], &ca[2], &ca[3],
				&ca[4] ); break;
		case 4: err = proc_ptr( ca[0], ca[1], &ca[2], &ca[3],
				&ca[4], &ca[5] ); break;
		case 5: err = proc_ptr( ca[0], ca[1], &ca[2], &ca[3],
				&ca[4], &ca[5], &ca[6] ); break;
		default: printf("Too many return values\n"); break;
		} break;
	case 3:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ca[0], ca[1], ca[2] ); break;
		case 1: err = proc_ptr( ca[0], ca[1], ca[2], &ca[3] ); break;
		case 2: err = proc_ptr( ca[0], ca[1], ca[2], &ca[3],
				&ca[4] ); break;
		case 3: err = proc_ptr( ca[0], ca[1], ca[2], &ca[3],
				&ca[4], &ca[5] ); break;
		case 4: err = proc_ptr( ca[0], ca[1], ca[2], &ca[3],
				&ca[4], &ca[5], &ca[6] ); break;
		case 5: err = proc_ptr( ca[0], ca[1], ca[2], ca[3],
				&ca[4], &ca[5], &ca[6], &ca[7] ); break;
		default: printf("Too many return values\n"); break;
		} break;
	case 4:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ca[0], ca[1], ca[2], ca[3] ); break;
		case 1: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], &ca[4] );
					break;
		case 2: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], &ca[4],
					&ca[5] ); break;
		case 3: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], &ca[4],
					&ca[5], &ca[6] ); break;
		case 4: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], &ca[4],
					&ca[5], &ca[6], &ca[7] ); break;
		case 5: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], &ca[4],
					&ca[5], &ca[6], &ca[7], &ca[8] ); break;
		default: printf("Too many return values\n"); break;
		} break;
	case 5:
		switch (num_ret.num) {
		case 0: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4] );
					break;
		case 1: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4],
					&ca[5] ); break;
		case 2: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4],
					&ca[5], &ca[6] ); break;
		case 3: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4],
					&ca[5], &ca[6], &ca[7] ); break;
		case 4: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4],
					&ca[5], &ca[6], &ca[7], &ca[8] ); break;
		case 5: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4],
					&ca[5], &ca[6], &ca[7], &ca[8],
					&ca[9]); break;
		default: printf("Too many return values\n"); break;
		} break;
	default: printf( "Too many argument values\n");
	}
#else
	switch( total_args ) {
	case 0: err = proc_ptr( ); break;
	case 1: err = proc_ptr( ca[0] ); break;
	case 2: err = proc_ptr( ca[0], ca[1] ); break;
	case 3: err = proc_ptr( ca[0], ca[1], ca[2] ); break;
	case 4: err = proc_ptr( ca[0], ca[1], ca[2], ca[3] ); break;
	case 5: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4] ); break;
	case 6: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5] );
			        break;
	case 7: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
			       ca[6] ); break;
	case 8: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
			       ca[6], ca[7] ); break;
	case 9: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
			       ca[6], ca[7], ca[8] ); break;
	case 10: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9] ); break;
	case 11: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9], ca[10] ); break;
	case 12: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9], ca[10], ca[11] );
				break;
	case 13: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9], ca[10], ca[11],
				ca[12] ); break;
	case 14: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9], ca[10], ca[11],
				ca[12], ca[13] ); break;
	case 15: err = proc_ptr( ca[0], ca[1], ca[2], ca[3], ca[4], ca[5],
				ca[6], ca[7], ca[8], ca[9], ca[10], ca[11],
				ca[12], ca[13], ca[14] ); break;

	default:
	    printf( "Can't handle more than %d call args and return vals: %ld\n",
							MAX_ARGS, total_args );

	}
#endif

	if (err == ERR_ok) {
	    long j = 0;
	    if (is_iter.tf == false) {
		for (i = num_args.num; i < num_args.num + num_ret.num; i++){
#ifdef sparc
			stack.vec->data[sp.num+j] = ca[i].num;
#else
			stack.vec->data[sp.num+j] = *(long*)ca[i].ref;
#endif
			j += 1;
		}
	    }
	    stack.vec->data[sp.num-1] = ERR_ok;
	    signal(ERR_ok);
	}
	else{
	    stack.vec->data[sp.num-1] = err;
	    for (i = 0; i < MAX_SIG_VALS ; i++) {
		stack.vec->data[sp.num+i] = elist[i].num;
		}
		signal( ERR_ok );
	      }

def_err_hdlr:

	printf( "In call_clu, at def_err_hdlr...\n" );
	/* NOTE: Should give a description of why the failure occurred. */
/*	printf( "Press Return to Continue..." );  */
/*	scanf( "%s", temp_str ); */
	elist[0].num = -33;
	signal( ERR_failure );
      }


errcode errcmp2(str1, str2, ans)
CLUREF str1, str2;
CLUREF *ans;
{
	if (str1.num == str2.num) {ans->tf = true; signal(ERR_ok);}
	if ((str1.num >= 0) && (str1.num < MAX_INTERNAL_ERROR)) {
		if ((str2.num >= 0) && (str2.num < MAX_INTERNAL_ERROR)) {
			ans->tf = (str1.num == str2.num);
			}
		else {
			ans->tf = false;
			}
		}
	else {
		if ((str2.num >= 0) && (str2.num < MAX_INTERNAL_ERROR)) {
			ans->tf = false;
			}
		else {
			ans->tf = !(strcmp(str1.ref, str2.ref));
			}
		}
	signal(ERR_ok);
	}

errcode _pclu_erstr2(sig, ans)
CLUREF sig;
CLUREF *ans;
{
	*ans = _pclu_erstr(sig.num);
	signal(ERR_ok);
	}
