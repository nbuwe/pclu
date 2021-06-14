/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*								*/
/*		STRING IMPLEMENTATION				*/
/*								*/

/* TODO: sc2s, s2sc */

#include "pclu_err.h"
#include "pclu_sys.h"

extern errcode arrayOPpredict(CLUREF low, CLUREF size, CLUREF *ans);
extern errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
extern errcode istreamOPgetbv(CLUREF ist, CLUREF *ret_1);
extern errcode istreamOPputbv(CLUREF ist, CLUREF bvec);
extern errcode pstreamOPget_max_width(CLUREF ps, CLUREF *ret_1);
extern errcode pstreamOPtext(CLUREF ps, CLUREF s, CLUREF *ret_1);
extern errcode pstreamOPtextc(CLUREF ps, CLUREF c, CLUREF *ret_1);
extern errcode sequenceOPfill(CLUREF length, CLUREF x, CLUREF *ans);

extern errcode stringOPprint(CLUREF s, CLUREF pst);

#define	CLU_roundup(x, y)	((((x)+((y)-1))/(y))*(y))


static inline size_t
stringOPOPmemsize(size_t size)
{
    /*
     * string header w/out the "inflexible" data[] array
     * and extra space for NUL at the end
     */
    size += offsetof(CLU_string, data) + 1;

    /* round up to word size */
    size = CLU_roundup(size, CLUREFSZ);

    return size;
}


static inline void
stringOPOPalloc(size_t size, CLUREF *pnew)
{
    size_t bufsz = stringOPOPmemsize(size);

    clu_alloc_atomic(bufsz, pnew);
    CLUTYPE_set(pnew->str->typ, CT_STRING);
    pnew->str->size = size;
}



errcode
stringOPsize(CLUREF s, CLUREF *ans)
{
    ans->num = s.str->size;
    signal(ERR_ok);
}


errcode
stringOPindexs(CLUREF find, CLUREF s, CLUREF *ans)
{
    long i,j;
    bool found;
    for (i = 0; i < s.str->size; ++i) {
	found = true;
	for (j = 0; j < find.str->size; ++j) {
	    if (s.str->data[i+j] != find.str->data[j]) {
		found = false;
		break;
	    }
	}
	if (found == true) {
	    ans->num = i + 1;
	    signal(ERR_ok);
	}
    }
    ans->num = 0;
    signal(ERR_ok);
}


errcode
stringOPindexc(CLUREF find, CLUREF s, CLUREF *ans)
{
    for (long i = 0; i < s.str->size; ++i) {
	if (s.str->data[i] == find.ch) {
	    ans->num = i + 1;
	    signal(ERR_ok);
	}
    }
    ans->num = 0;
    signal(ERR_ok);
}


errcode
stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans)
{
    CLUREF s;
    stringOPOPalloc(len.num, &s);

    /*
     * The destination is at least one byte larger than the size and
     * the allocator zeroes out the returned memory, so we get the
     * trailing NUL byte by construction.
     */
    memcpy(s.str->data, buf + start.num - 1, len.num);

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPcons0(CLUREF len, CLUREF *ans)
{
    CLUREF s;
    stringOPOPalloc(len.num, &s);

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPc2s(CLUREF ch, CLUREF *ans)
{
    CLUREF s;
    stringOPOPalloc(1, &s);
    s.str->data[0] = ch.ch;

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPconcat(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    if (s1.str->size == 0) {
	ans->str = s2.str;
	signal(ERR_ok);
    }

    if (s2.str->size == 0) {
	ans->str = s1.str;
	signal(ERR_ok);
    }

    // assert(s1.str->size > 0);
    // assert(s1.str->size <= MAX_STR)
    // assert(s2.str->size > 0);
    // assert(s2.str->size <= MAX_STR)
    if (s1.str->size > MAX_STR - s2.str->size) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    CLUREF s;
    stringOPOPalloc(s1.str->size + s2.str->size, &s);
    memcpy(s.str->data, s1.str->data, s1.str->size);
    memcpy(s.str->data + s1.str->size, s2.str->data, s2.str->size);

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPappend(CLUREF s, CLUREF c, CLUREF *ans)
{
    if (s.str->size > MAX_STR - 1) {
	elist[0] = huge_allocation_request_STRING;
	signal(ERR_failure);
    }

    CLUREF s2;
    stringOPOPalloc(s.str->size + 1, &s2);
    memcpy(s2.str->data, s.str->data, s.str->size);
    s2.str->data[s.str->size] = c.ch;

    ans->str = s2.str;
    signal(ERR_ok);
}


errcode
stringOPempty(CLUREF s, CLUREF *ans)
{
    if (s.str->size == 0)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
stringOPsubstr(CLUREF s, CLUREF start, CLUREF len, CLUREF *ans)
{
    errcode err;
    CLUREF temp;
    CLUREF count;

    if (start.num <= 0)
	signal(ERR_bounds);
    if (start.num > (s.str->size + 1))
	signal(ERR_bounds);
    if (len.num < 0)
	signal(ERR_negative_size);

    /* inlined int$min 8/28/90 dcurtis */
    count.num = s.str->size - start.num + 1;
    if (len.num < count.num)
	count.num = len.num;

    err = stringOPcons(s.str->data, start, count, &temp);
    if (err != ERR_ok)
	resignal(err);

    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
stringOPrest(CLUREF s, CLUREF start, CLUREF *ans)
{
    errcode err;
    CLUREF temp;
    CLUREF count;

    if (start.num <= 0)
	signal(ERR_bounds);
    if (start.num > s.str->size + 1)
	signal(ERR_bounds);

    count.num = s.str->size - start.num + 1;
    err = stringOPcons(s.str->data, start, count, &temp);
    if (err != ERR_ok)
	resignal(err);

    ans->str = temp.str;
    signal(ERR_ok);
}


errcode
stringOPs2ac(CLUREF s, CLUREF *ans)
{
    errcode err;

    CLUREF a;
    err = arrayOPpredict(CLU_1, CLUREF_make_num(s.str->size), &a);
    if (err != ERR_ok)
	resignal(err);

    CLUREF c = CLUREF_make_num(0); /* init all bytes */
    long dst = a.array->int_low;
    for (long src = 0; src < s.str->size; ++src, ++dst) {
	c.ch = s.str->data[src];
	a.array->store->data[dst] = c.num;
    }
    a.array->ext_size = s.str->size;
    a.array->ext_high = s.str->size;

    ans->array = a.array;
    signal(ERR_ok);
}


errcode
stringOPac2s(CLUREF a, CLUREF *ans)
{
    CLUREF s;
    stringOPOPalloc(a.array->ext_size, &s);

    long src = a.array->int_low;
    for (long dst = 0; src < a.array->ext_size; ++src, ++dst) {
	CLUREF c = { .num = a.array->store->data[src] };
	s.str->data[dst] = c.ch;
    }

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPs2sc(CLUREF s, CLUREF *ans)
{
    errcode err;

    CLUREF q;
    err = sequenceOPfill(CLUREF_make_num(s.str->size), CLU_0, &q);
    if (err != ERR_ok)
	resignal(err);

    for (long i = 0; i < s.str->size; ++i) {
	q.vec->data[i] = (unsigned char)s.str->data[i];
    }

    ans->vec = q.vec;
    signal(ERR_ok);
}


errcode
stringOPsc2s(CLUREF q, CLUREF *ans)
{
    CLUREF s;
    stringOPOPalloc(q.vec->size, &s);

    for (long i = 0; i < q.vec->size; ++i) {
	s.str->data[i] = q.vec->data[i];
    }

    ans->str = s.str;
    signal(ERR_ok);
}


errcode
stringOPchars(CLUREF s, errcode (*iterbod)(), void *locals, errcode *ecode2)
{
    errcode err;

    CLUREF iv_1 = CLUREF_make_num(0); /* init all bytes */
    for (long i = 0; i < s.str->size; ++i) {
	iv_1.ch = s.str->data[i];

	err = (*iterbod)(iv_1, locals, ecode2);
	if (err != ERR_ok)
	    signal(err);
    }
    signal(ERR_ok);
}


errcode
stringOPlt(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long size, i;

    ans->tf = true;
    size = s1.str->size;
    if (s2.str->size < size)
	size = s2.str->size;

    for (i = 0; i < size; ++i) {
	if (s1.str->data[i] != s2.str->data[i]) {
	    if (s1.str->data[i] >= s2.str->data[i])
		ans->tf = false;
	    signal(ERR_ok);
	}
    }
    if (s1.str->size >= s2.str->size)
	ans->tf = false;
    signal(ERR_ok);
}


errcode
stringOPle(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long size, i;

    ans->tf = true;
    size = s1.str->size;
    if (s2.str->size < size)
	size = s2.str->size;

    for (i = 0; i < size; ++i) {
	if (s1.str->data[i] != s2.str->data[i]) {
	    if (s1.str->data[i] > s2.str->data[i])
		ans->tf = false;
	    signal(ERR_ok);
	}
    }
    if (s1.str->size > s2.str->size)
	ans->tf = false;
    signal(ERR_ok);
}


errcode stringOPge(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long size, i;

    ans->tf = true;
    size = s1.str->size;
    if (s2.str->size < size)
	size = s2.str->size;

    for (i = 0; i < size; ++i) {
	if (s1.str->data[i] != s2.str->data[i]) {
	    if (s1.str->data[i] < s2.str->data[i])
		ans->tf = false;
	    signal(ERR_ok);
	}
    }
    if (s1.str->size < s2.str->size)
	ans->tf = false;
    signal(ERR_ok);
}


errcode stringOPgt(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long size, i;

    ans->tf = true;
    size = s1.str->size;
    if (s2.str->size < size)
	size = s2.str->size;

    for (i = 0; i < size; ++i) {
	if (s1.str->data[i] != s2.str->data[i]) {
	    if (s1.str->data[i] <= s2.str->data[i])
		ans->tf = false;
	    signal(ERR_ok);
	}
    }
    if (s1.str->size <= s2.str->size)
	ans->tf = false;
    signal(ERR_ok);
}


errcode
stringOPfetch(CLUREF s, CLUREF i, CLUREF *ans)
{
    if (i.num < 1)
	signal(ERR_bounds);
    if (i.num > s.str->size)
	signal(ERR_bounds);

    ans->ch = s.str->data[i.num - 1];
    signal(ERR_ok);
}


errcode
stringOPequal(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long i;

    if (s1.str->size == s2.str->size) {
	for (i = 0; i < s1.str->size; ++i) {
	    if (s1.str->data[i] == s2.str->data[i])
		continue;
	    ans->tf = false;
	    signal(ERR_ok);
	}
	ans->tf = true;
	signal(ERR_ok);
    }
    else {
	ans->tf = false;
	signal(ERR_ok);
    }
}


errcode
stringOPsimilar(CLUREF s1, CLUREF s2, CLUREF *ans)
{
    long i;

    if (s1.str->size == s2.str->size) {
	for (i = 0; i < s1.str->size; ++i) {
	    if (s1.str->data[i] == s2.str->data[i])
		continue;
	    ans->tf = false;
	    signal(ERR_ok);
	}
	ans->tf = true;
	signal(ERR_ok);
    }
    else {
	ans->tf = false;
	signal(ERR_ok);
    }
}


errcode
stringOPcopy(CLUREF s1, CLUREF *ans)
{
    ans->str = s1.str;
    signal(ERR_ok);
}


errcode
stringOPdebug_print(CLUREF s, CLUREF pst)
{
    errcode err;

    err = stringOPprint(s, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
stringOPprint(CLUREF s, CLUREF pst)
{
    errcode err;
    CLUREF lim, temp_str, ch;
    long i, count;
    char nthch, lowch, outch;
    CLUREF prefix, ans;
    bool meta;

    static bool init = false;
    static CLUREF t0, t1, t2, t3, t4;

    if (init == 0) {
	err = stringOPcons("", CLU_1, CLU_0, &t0);
	err = stringOPcons("\\^", CLU_1, CLU_2, &t1);
	err = stringOPcons("\\!", CLU_1, CLU_2, &t2);
	err = stringOPcons("\\",  CLU_1, CLU_1, &t3);
	err = stringOPcons("\\&", CLU_1, CLU_2, &t4);
	init = true;
    }

    err = pstreamOPget_max_width(pst, &lim);
    if (err != ERR_ok)
	resignal(err);

    lim.num = lim.num*16 + 4;

    ch.ch = '"';
    err = pstreamOPtextc(pst, ch, &ans);
    if (err != ERR_ok)
	resignal(err);

    count = s.str->size;
    if (count != 0) {
#if 0
	max.num = lim.num + 3;
#endif
	for (i = 0; i < count; ++i) {
	    if (i >= lim.num) {
		err = stringOPcons("...", CLU_1, CLU_3, &temp_str);
		if (err != ERR_ok)
		    resignal(err);

		err = pstreamOPtext(pst, temp_str, &ans);
		if (err != ERR_ok)
		    resignal(err);

		break;
	    }
	    nthch = s.str->data[i];
	    prefix = t0;
	    meta = false;
	    if ((nthch & 0x80) != 0)
		meta = true;
	    lowch = nthch & 0x7f;
	    outch = lowch;
	    do {
		if (lowch == '\177') {
		    prefix = t1;
		    if (meta) prefix = t2;
		    outch = '?';
		    break;
		}
		if (lowch == '"' || lowch == '\\') {
		    prefix = t3;
		    if (meta) prefix = t4;
		    break;
		}
		if (lowch >= ' ') {
		    if (!meta) break;
		    prefix = t4;
		    break;
		}
		if (meta) {
		    prefix = t2;
		    outch += 0x40;
		    break;
		}
		if (outch == '\n') {
		    prefix = t3;
		    outch = 'n';
		    break;
		}
		if (outch == '\t') {
		    prefix = t3;
		    outch = 't';
		    break;
		}
		if (outch == '\f') {
		    prefix = t3;
		    outch = 'p';
		    break;
		}
		if (outch == '\b') {
		    prefix = t3;
		    outch = 'b';
		    break;
		}
		if (outch == '\r') {
		    prefix = t3;
		    outch = 'r';
		    break;
		}
		if (outch == '\v') {
		    prefix = t3;
		    outch = 'v';
		    break;
		}
		prefix = t1;
		outch += 0x40;
	    } while (false);

	    err = pstreamOPtext(pst, prefix, &ans);
	    if (err != ERR_ok)
		resignal(err);

	    ch.ch = outch;
	    err = pstreamOPtextc(pst, ch, &ans);
	    if (err != ERR_ok)
		resignal(err);
	}
    }

    ch.ch = '"';
    err = pstreamOPtextc(pst, ch, &ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
stringOPencode(CLUREF s, CLUREF ist)
{
    errcode err;

    err = istreamOPputbv(ist, s);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
stringOPdecode(CLUREF ist, CLUREF *ans)
{
    errcode err;
    CLUREF temp;

    err = istreamOPgetbv(ist, &temp);
    if (err == ERR_end_of_file)
	signal(err);
    if (err == ERR_not_possible)
	signal(err);
    if (err != ERR_ok)
	resignal(err);

    ans->str = temp.str;
    signal(ERR_ok);
}

errcode
stringOP_gcd(CLUREF s, CLUREF tab, CLUREF *ans)
{
    errcode err;

    CLUREF ginfo; 		// := ginfo$make_a_bvec(nil)
    err = oneofOPnew(CLU_1, CLU_0, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    long sz = stringOPOPmemsize(s.str->size);
    err = gcd_tabOPinsert(tab, CLUREF_make_num(sz), ginfo, s, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr string_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &string_own_init,		\
    .op_owns = &string_own_init,		\
}

static CLU_proc string_oe_copy = CLU_proc_INIT(stringOPcopy);
static CLU_proc string_oe_size = CLU_proc_INIT(stringOPsize);
static CLU_proc string_oe_fetch = CLU_proc_INIT(stringOPfetch);
static CLU_proc string_oe_equal = CLU_proc_INIT(stringOPequal);
static CLU_proc string_oe_similar = CLU_proc_INIT(stringOPsimilar);
static CLU_proc string_oe_indexs = CLU_proc_INIT(stringOPindexs);
static CLU_proc string_oe_indexc = CLU_proc_INIT(stringOPindexc);
static CLU_proc string_oe_cons = CLU_proc_INIT(stringOPcons);
static CLU_proc string_oe_cons0 = CLU_proc_INIT(stringOPcons0);
static CLU_proc string_oe_c2s = CLU_proc_INIT(stringOPc2s);
static CLU_proc string_oe_concat = CLU_proc_INIT(stringOPconcat);
static CLU_proc string_oe_append = CLU_proc_INIT(stringOPappend);
static CLU_proc string_oe_empty = CLU_proc_INIT(stringOPempty);
static CLU_proc string_oe_substr = CLU_proc_INIT(stringOPsubstr);
static CLU_proc string_oe_rest = CLU_proc_INIT(stringOPrest);
static CLU_proc string_oe_s2ac = CLU_proc_INIT(stringOPs2ac);
static CLU_proc string_oe_ac2s = CLU_proc_INIT(stringOPac2s);
static CLU_proc string_oe_s2sc = CLU_proc_INIT(stringOPs2sc);
static CLU_proc string_oe_sc2s = CLU_proc_INIT(stringOPsc2s);
static CLU_proc string_oe_chars = CLU_proc_INIT(stringOPchars);
static CLU_proc string_oe_lt = CLU_proc_INIT(stringOPlt);
static CLU_proc string_oe_le = CLU_proc_INIT(stringOPle);
static CLU_proc string_oe_ge = CLU_proc_INIT(stringOPge);
static CLU_proc string_oe_gt = CLU_proc_INIT(stringOPgt);
static CLU_proc string_oe_print = CLU_proc_INIT(stringOPprint);
static CLU_proc string_oe_encode = CLU_proc_INIT(stringOPencode);
static CLU_proc string_oe_decode = CLU_proc_INIT(stringOPdecode);
static CLU_proc string_oe__gcd = CLU_proc_INIT(stringOP_gcd);
static CLU_proc string_oe_debug_print = CLU_proc_INIT(stringOPdebug_print);


static struct /* OPS */ {
    long count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[29];
} string_ops_actual = {
    29,
    &string_own_init,
    &string_own_init,
    {
	{ &string_oe_equal, "equal" },
	{ &string_oe_similar, "similar" },
	{ &string_oe_copy, "copy" },
	{ &string_oe_print, "print" },
	{ &string_oe_encode, "encode" },
	{ &string_oe_decode, "decode" },
	{ &string_oe__gcd, "_gcd" },
	{ &string_oe_debug_print, "debug_print" },
	{ &string_oe_size, "size" },
	{ &string_oe_fetch, "fetch" },
	{ &string_oe_indexs, "indexs" },
	{ &string_oe_indexc, "indexc" },
	{ &string_oe_cons, "cons" },
	{ &string_oe_cons0, "cons0" },
	{ &string_oe_c2s, "c2s" },
	{ &string_oe_concat, "concat" },
	{ &string_oe_append, "append" },
	{ &string_oe_empty, "empty" },
	{ &string_oe_substr, "substr" },
	{ &string_oe_rest, "rest" },
	{ &string_oe_s2ac, "s2ac" },
	{ &string_oe_ac2s, "ac2s" },
	{ &string_oe_s2sc, "s2sc" },
	{ &string_oe_sc2s, "sc2s" },
	{ &string_oe_chars, "chars" },
	{ &string_oe_lt, "lt" },
	{ &string_oe_le, "le" },
	{ &string_oe_ge, "ge" },
	{ &string_oe_gt, "gt" },
    }
};

struct OPS *string_ops = (struct OPS *)&string_ops_actual;
