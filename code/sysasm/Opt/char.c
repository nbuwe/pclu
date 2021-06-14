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
    *ans = c;
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
    errcode err;
    CLUREF ignored;

    static CLUREF plain, backslash, c0, c1, g1;
    static bool init = false;
    if (!init) {
	stringOPcons("'",    CLU_1, CLU_1, &plain);
	stringOPcons("'\\",  CLU_1, CLU_2, &backslash);
	stringOPcons("'\\^", CLU_1, CLU_3, &c0);
	stringOPcons("'\\!", CLU_1, CLU_3, &c1);
	stringOPcons("'\\&", CLU_1, CLU_3, &g1);
	init = true;
    }

    CLUREF prefix;
    CLUREF ascii = { .ch = (unsigned char)c.ch & 0x7f };
    bool meta = (ascii.ch != c.ch);

    /* DEL is a "control" outside C0/C1 */
    if (ascii.ch == '\177') {
	prefix = meta ? c1 : c0;
	ascii.ch = '?';
    }
    /* escape single quote or backslash in G0, not special in G1 */
    else if (ascii.ch == '\'' || ascii.ch == '\\') {
	prefix = meta ? g1 : backslash;
    }
    /* general G0 or G1 */
    else if (' ' <= ascii.ch) {
	prefix = meta ? g1 : plain;
    }
    /* general C1 */
    else if (meta) {
	prefix = c1;
	ascii.ch += '@';	/* to upper case letters */
    }
    /* named C0 escapes */
    else if (ascii.ch == '\n') {
	prefix = backslash;
	ascii.ch = 'n';
    }
    else if (ascii.ch == '\t') {
	prefix = backslash;
	ascii.ch = 't';
    }
    else if (ascii.ch == '\f') {
	prefix = backslash;
	ascii.ch = 'p';
    }
    else if (ascii.ch == '\b') {
	prefix = backslash;
	ascii.ch = 'b';
    }
    else if (ascii.ch == '\r') {
	prefix = backslash;
	ascii.ch = 'r';
    }
    else if (ascii.ch == '\v') {
	prefix = backslash;
	ascii.ch = 'v';
    }
    /* general C0 */
    else {
	prefix = c0;
	ascii.ch += '@';	/* to upper case letters */
    }

    err = pstreamOPtext(pst, prefix, &ignored);
    if (err != ERR_ok)
	goto ex_0;

    err = pstreamOPtextc(pst, ascii, &ignored);
    if (err != ERR_ok)
	goto ex_0;

    err = pstreamOPtextc(pst, CLUREF_make_ch('\''), &ignored);
    if (err != ERR_ok)
	goto ex_0;

    signal(ERR_ok);
  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
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
