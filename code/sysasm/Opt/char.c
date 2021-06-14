/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			char			*/
/*						*/


#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
extern errcode istreamOPgeti(CLUREF ist, CLUREF *ret_1);
extern errcode istreamOPputi(CLUREF ist, CLUREF i);
extern errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);
extern errcode pstreamOPtextc(CLUREF ps, CLUREF c, CLUREF *ret_1);

extern errcode charOPprint();


errcode
charOPi2c(CLUREF i, CLUREF *ans)
{

    if (i.num < 0 || UCHAR_MAX < i.num)
	signal(ERR_illegal_char);

    ans->ch = i.num;
    signal(ERR_ok);
}


errcode
charOPc2i(CLUREF c, CLUREF *ans)
{
    ans->num = (unsigned char)c.ch;
    signal(ERR_ok);
}


errcode
charOPlt(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char)c1.ch < (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPle(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char)c1.ch <= (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPge(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char) c1.ch >= (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPgt(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char)c1.ch > (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPequal(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char)c1.ch == (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPsimilar(CLUREF c1, CLUREF c2, CLUREF *ans)
{
    ans->tf = ((unsigned char)c1.ch == (unsigned char)c2.ch);
    signal(ERR_ok);
}


errcode
charOPcopy(CLUREF c, CLUREF *ans)
{
    ans->num = c.ch;
    signal(ERR_ok);
}


errcode
charOPdebug_print(CLUREF c, CLUREF pst)
{
    errcode err;

    err = charOPprint(c, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
charOPprint(CLUREF c, CLUREF pst)
{
    CLUREF temp;
    errcode err;
    CLUREF temp_str, temp_ref;
    static bool init = false;
    static CLUREF t1, t2, t3, t4, t5, ans;
    bool done = false;

    if (init == 0) {
	err = stringOPcons("'\\^", CLU_1, CLU_3, &t1);
	err = stringOPcons("'\\!", CLU_1, CLU_3, &t2);
	err = stringOPcons("'\\",  CLU_1, CLU_2, &t3);
	err = stringOPcons("'\\&", CLU_1, CLU_3, &t4);
	err = stringOPcons("'",    CLU_1, CLU_1, &t5);
	init = true;
    }

    temp.ch = c.ch & 0x7f;
    if (temp.ch == '\177') {
	temp_str = t1;
	if (c.ch != temp.ch) temp_str = t2;
	temp.ch = '?';
	done = true;
    }
    if (!done && (temp.ch == '\'' || temp.ch == '\\')) {
	temp_str = t3;
	if (temp.ch != c.ch) temp_str = t4;
	done = true;
    }
    if (!done && (' ' <= temp.ch)) {
	temp_str = t5;
	if (temp.ch != c.ch) temp_str = t4;
	done = true;
    }
    if (!done && (temp.ch != c.ch)) {
	temp_str = t2;
	temp.ch += 64;
	done = true;
    }
    if (!done && (temp.ch == '\n')) {
	temp_str = t3;
	temp.ch = 'n';
	done = true;
    }
    if (!done && (temp.ch == '\t')) {
	temp_str = t3;
	temp.ch = 't';
	done = true;
    }
    if (!done && (temp.ch == '\f')) {
	temp_str = t3;
	temp.ch = 'p';
	done = true;
    }
    if (!done && (temp.ch == '\b')) {
	temp_str = t3;
	temp.ch = 'b';
	done = true;
    }
    if (!done && (temp.ch == '\r')) {
	temp_str = t3;
	temp.ch = 'r';
	done = true;
    }
    if (!done && (temp.ch == '\v')) {
	temp_str = t3;
	temp.ch = 'v';
	done = true;
    }
    if (!done) {
	temp_str = t1;
	temp.ch += 64;
    }

    err = pstreamOPtext(pst, temp_str, &ans);
    err = pstreamOPtextc(pst, temp, &ans);

    temp_ref.ch = '\'';
    err = pstreamOPtextc(pst, temp_ref, &ans);

    signal(ERR_ok);
}


errcode
charOPencode(CLUREF c, CLUREF ist)
{
    errcode err;

    err = istreamOPputi(ist, c);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
charOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    CLUREF temp;

    err = istreamOPgeti(ist, &temp);
    if (err == ERR_not_possible || err == ERR_end_of_file)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    if (temp.num < 256) {
	ans->num = temp.num;
	signal(ERR_ok);
    }
    else {
	elist[0] = bad_format_STRING;
	signal(ERR_not_possible);
    }
}


errcode
charOP_gcd(CLUREF c, CLUREF tab, CLUREF *ans)
{
    CLU_NOREF(c);
    CLU_NOREF(tab);

    ans->num = -1;
    signal(ERR_ok);
}



OWN_ptr char_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &char_own_init,		\
    .op_owns = &char_own_init,			\
}

static CLU_proc char_oe_equal = CLU_proc_INIT(charOPequal);
static CLU_proc char_oe_similar = CLU_proc_INIT(charOPsimilar);
static CLU_proc char_oe_copy = CLU_proc_INIT(charOPcopy);
static CLU_proc char_oe_print = CLU_proc_INIT(charOPprint);
static CLU_proc char_oe_encode = CLU_proc_INIT(charOPencode);
static CLU_proc char_oe_decode = CLU_proc_INIT(charOPdecode);
static CLU_proc char_oe__gcd = CLU_proc_INIT(charOP_gcd);
static CLU_proc char_oe_debug_print = CLU_proc_INIT(charOPdebug_print);
static CLU_proc char_oe_i2c = CLU_proc_INIT(charOPi2c);
static CLU_proc char_oe_c2i = CLU_proc_INIT(charOPc2i);
static CLU_proc char_oe_lt = CLU_proc_INIT(charOPlt);
static CLU_proc char_oe_le = CLU_proc_INIT(charOPle);
static CLU_proc char_oe_ge = CLU_proc_INIT(charOPge);
static CLU_proc char_oe_gt = CLU_proc_INIT(charOPgt);


static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[14];
} char_ops_actual = {
    14,
    &char_own_init,
    &char_own_init,
    {
	{ &char_oe_equal, "equal" },
	{ &char_oe_similar, "similar" },
	{ &char_oe_copy, "copy" },
	{ &char_oe_print, "print" },
	{ &char_oe_encode, "encode" },
	{ &char_oe_decode, "decode" },
	{ &char_oe__gcd, "_gcd" },
	{ &char_oe_debug_print, "debug_print" },
	{ &char_oe_i2c, "i2c" },
	{ &char_oe_c2i, "c2i" },
	{ &char_oe_lt, "lt" },
	{ &char_oe_le, "le" },
	{ &char_oe_ge, "ge" },
	{ &char_oe_gt, "gt" },
    }
};

struct OPS *char_ops = (struct OPS *)&char_ops_actual;
