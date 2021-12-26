/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		WORDVEC IMPLEMENTATION			*/
/*							*/

/* TODO: comp, build, move_rl, move_b (not referenced) 	*/

/*   mutable aggregate of bytes				*/
/*	to hold 32-bit quantities and be accessed in    */
/*		32-bit units				*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <stdio.h>

errcode gcd_tabOPinsert(CLUREF tab, CLUREF z, CLUREF inf, CLUREF x, CLUREF *ans);
errcode stringOPprint(CLUREF s, CLUREF pst);

/*
 * We pun/_cvt between _wordvec and string so observe the same
 * allocation limit.
 */
#define MAX_WVEC	((MAX_STR - 1) / CLUREFSZ)


static inline size_t
_wordvecOPOPmemsize(size_t size)
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


errcode
_wordvecOPcreate(CLUREF sz, CLUREF *ans)
{
    if (sz.num < 0)
	signal(ERR_negative_size);
    if (sz.num > MAX_WVEC)
	signal(ERR_toobig);

    size_t bsize = sz.num * CLUREFSZ; /* size of data in bytes */
    int bufsz = _wordvecOPOPmemsize(bsize);

    CLUREF wv;
    clu_alloc(bufsz, &wv);
    CLUTYPE_set(wv.str->typ, CT_STRING);
    wv.str->size = bsize;

    *ans = wv;
    signal(ERR_ok);
}


errcode
_wordvecOPcopy(CLUREF wv1, CLUREF *ans)
{
    size_t bsize = wv1.str->size; /* size of data in bytes */
    size_t bufsz = _wordvecOPOPmemsize(bsize);

    CLUREF wv2;
    clu_alloc(bufsz, &wv2);
    CLUTYPE_set(wv2.str->typ, CT_STRING);
    wv2.str->size = bsize;

    memcpy(wv2.str->data, wv1.str->data, bsize);
#if 0 // zeroed on alloc
    wv2.str->data[bsize] = '\0';
#endif

    *ans = wv2;
    signal(ERR_ok);
}


errcode
_wordvecOPfetch(CLUREF wv, CLUREF i, CLUREF *ans)
{
    int bi;
    /* 1/10/91 : modified wrt gc_dump */

    bi = (i.num - 1) * CLUREFSZ;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    ans->num = wv.vec->data[i.num - 1];
#else
    ans->num = (wv.str->data[bi]        & 0x000000ff)
	+ ((wv.str->data[bi + 1] <<  8) & 0x0000ff00)
	+ ((wv.str->data[bi + 2] << 16) & 0x00ff0000)
	+ ((wv.str->data[bi + 3] << 24) & 0xff000000);
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPstore(CLUREF wv, CLUREF i, CLUREF w)
{
    int bi;
    /* 1/10/91 : modified wrt gc_dump */

    bi = (i.num - 1) * CLUREFSZ;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    wv.vec->data[i.num - 1] = w.num;
#else
    wv.str->data[bi + 0] =  w.num        & 0xff;
    wv.str->data[bi + 1] = (w.num >>  8) & 0xff;
    wv.str->data[bi + 2] = (w.num >> 16) & 0xff;
    wv.str->data[bi + 3] = (w.num >> 24) & 0xff;
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPfetch2(CLUREF wv, CLUREF i, CLUREF *ans1, CLUREF *ans2)
{
    int bi;

    bi = (i.num - 1) * CLUREFSZ;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    int temp = wv.vec->data[i.num - 1];
    ans1->num = (temp & 0xffff0000) >> 16;
    ans2->num = (temp & 0x0000ffff);
#else
    ans1->num = (wv.str->data[bi + 1] << 8) || wv.str->data[bi + 0];
    ans2->num = (wv.str->data[bi + 3] << 8) || wv.str->data[bi + 2];
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPstore2(CLUREF wv, CLUREF i, CLUREF l, CLUREF r)
{
    int bi;

    bi = (i.num - 1) * CLUREFSZ;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    wv.vec->data[i.num-1] = (r.num & 0xffff) | ((l.num & 0xffff) << 16);
#else
    wv.str->data[bi + 0] =  r.num       & 0xff;
    wv.str->data[bi + 1] = (r.num >> 8) & 0xff;
    wv.str->data[bi + 2] =  l.num       & 0xff;
    wv.str->data[bi + 3] = (l.num >> 8) & 0xff;
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPxstore(CLUREF wv, CLUREF i, CLUREF b, CLUREF l)
{
    int bi;

    bi = (i.num - 1) * CLUREFSZ;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    wv.vec->data[i.num - 1] = (l.num & 0xffffff) | ((b.num & 0xff) << 24);
#else
    wv.str->data[bi + 1] = (l.num >>  8) & 0xff;
    wv.str->data[bi + 2] = (l.num >> 16) & 0xff;
    wv.str->data[bi + 3] =  b.num        & 0xff;
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPbfetch(CLUREF wv, CLUREF i, CLUREF *ans)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);
#if 1
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    int temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	temp = temp & 0xff;
	break;
    case 2:
	temp = temp >> 8;
	temp = temp & 0xff;
	break;
    case 3:
	temp = temp >> 16;
	temp = temp & 0xff;
	break;
    case 4:
	temp = temp >> 24;
	temp = temp & 0xff;
	break;
    }
    ans->num = temp;
#else
    ans->num = wv.str->data[bi];
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPbstore(CLUREF wv, CLUREF i, CLUREF c)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi > wv.str->size)
	signal(ERR_bounds);

#if 1
    c.num = c.num & 0xff;
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    int temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	temp = temp & ~0xff;
	temp = temp | c.num;
	break;
    case 2:
	temp = temp & ~0xff00;
	temp = temp | (c.num << 8);
	break;
    case 3:
	temp = temp & ~0xff0000;
	temp = temp | (c.num << 16);
	break;
    case 4:
	temp = temp & ~0xff000000;
	temp = temp | (c.num << 24);
	break;
    }
    wv.vec->data[wi] = temp;
#else
    temp.num = c.num & 0xff;
    wv.str->data[bi] = (char)temp.num;
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPwfetch(CLUREF wv, CLUREF i, CLUREF *ans)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi >= wv.str->size - 1)
	signal(ERR_bounds);
#if 1
    int temp, temp2;
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	temp = temp & 0xffff;
	ans->num = temp;
	break;
    case 2:
	temp = temp & 0xffff00;
	temp = temp >> 8;
	ans->num = temp;
	break;
    case 3:
	temp = temp & 0xffff0000;
	temp = temp >> 16;
	ans->num = temp;
	break;
    case 4:
	temp = temp & ~0xff000000;
	temp = temp >> 24;
	temp2 = wv.vec->data[wi + 1];
	temp2 = (temp2 & 0xff) << 8;
	temp = temp2 | temp;
	ans->num = temp;
	break;
    }
#else
    ans->num = (wv.str->data[bi + 1] << 8) + wv.str->data[bi];
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPwstore(CLUREF wv, CLUREF i, CLUREF n)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi >= wv.str->size - 1)
	signal(ERR_bounds);

#if 1
    int temp;
    n.num = n.num & 0xffff;
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	temp = temp & ~0xffff;
	temp = temp | n.num;
	wv.vec->data[wi] = temp;
	break;
    case 2:
	temp = temp & ~0xffff00;
	temp = temp | (n.num << 8);
	wv.vec->data[wi] = temp;
	break;
    case 3:
	temp = temp & ~0xffff0000;
	temp = temp | (n.num << 16);
	wv.vec->data[wi] = temp;
	break;
    case 4:
	temp = temp & ~0xff000000;
	temp = temp | (n.num << 24);
	wv.vec->data[wi] = temp;
	temp = wv.vec->data[wi + 1];
	temp = temp & ~0x000000ff;
	temp = temp | ((n.num & 0xff00) >> 8);
	wv.vec->data[wi+1] = temp;
	break;
    }
#else
    wv.str->data[bi + 0] = n.num & 0x00ff;
    wv.str->data[bi + 1] = n.num & 0xff00 >> 8;
#endif
    signal(ERR_ok);
}


errcode
_wordvecOPlfetch(CLUREF wv, CLUREF i, CLUREF *ans)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi >= wv.str->size - 1)
	signal(ERR_bounds);

    int temp, temp2;
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	ans->num = temp;
	break;
    case 2:
	temp = temp & 0xffffff00;
	temp = temp >> 8;
	temp2 = wv.vec->data[wi+1];
	temp2 = (temp2 & 0xff) << 24;
	ans->num = temp | temp2;
	break;
    case 3:
	temp = temp & 0xffff0000;
	temp = temp >> 16;
	temp2 = wv.vec->data[wi + 1];
	temp2 = (temp2 & 0xffff) << 16;
	ans->num = temp | temp2;
	break;
    case 4:
	temp = temp & ~0xff000000;
	temp = temp >> 24;
	temp2 = wv.vec->data[wi + 1];
	temp2 = (temp2 & 0xff) << 8;
	ans->num = temp | temp2;
	break;
    }
    signal(ERR_ok);
}


errcode
_wordvecOPlstore(CLUREF wv, CLUREF i, CLUREF n)
{
    int bi;

    bi = i.num - 1;
    if (bi < 0)
	signal(ERR_bounds);
    if (bi >= wv.str->size - 1)
	signal(ERR_bounds);

    int temp;
    int wi = bi / CLUREFSZ;
    int sub_index = bi - (wi * CLUREFSZ) + 1;

    temp = wv.vec->data[wi];
    switch (sub_index) {
    case 1:
	wv.vec->data[wi] = n.num;
	break;
    case 2:
	temp = temp & ~0xffffff00;
	temp = temp | (n.num << 8);
	wv.vec->data[wi] = temp;
	temp = wv.vec->data[wi + 1];
	temp = temp & ~0xff;
	temp = temp | ((n.num & 0xff000000) >> 24);
	wv.vec->data[wi + 1] = temp;
	break;
    case 3:
	temp = temp & ~0xffff0000;
	temp = temp | (n.num << 16);
	wv.vec->data[wi] = temp;
	temp = wv.vec->data[wi + 1];
	temp = temp & ~0xffff;
	temp = temp | ((n.num & 0xffff0000) >> 16);
	wv.vec->data[wi + 1] = temp;
	break;
    case 4:
	temp = temp & ~0xff000000;
	temp = temp | (n.num << 24);
	wv.vec->data[wi] = temp;
	temp = wv.vec->data[wi + 1];
	temp = temp & ~0x00ffffff;
	temp = temp | ((n.num & 0xffffff00) >> 8);
	wv.vec->data[wi + 1] = temp;
	break;
    }
    signal(ERR_ok);
}


errcode
_wordvecOPsize(CLUREF wv, CLUREF *ans)
{
    ans->num = wv.str->size / CLUREFSZ;
    signal(ERR_ok);
}


errcode
_wordvecOPequal(CLUREF wv1, CLUREF wv2, CLUREF *ans)
{
    if (wv1.str == wv2.str)
	ans->tf = true;
    else
	ans->tf = false;
    signal(ERR_ok);
}


errcode
_wordvecOPindexc(CLUREF c, CLUREF wv, CLUREF first, CLUREF *ans)
{
    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > wv.str->size)
	signal(ERR_bounds);

    for (long i = first.num; i <= wv.str->size; ++i) {
	if (wv.str->data[i - 1] == c.ch) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }

    ans->num = 0;
    signal(ERR_ok);
}


/*
 * Find wv1 in wv2; start looking at wv2[first].
 * Some way to use matchc and/or locc?
 */
errcode
_wordvecOPindexv(CLUREF wv1, CLUREF wv2, CLUREF first, CLUREF *ans)
{
    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > wv2.str->size)
	signal(ERR_bounds);

    bool found;
    for (long i = first.num; i + wv1.str->size - 1 <= wv2.str->size; ++i) {
	found = true;
	for (long j = 1; j <= wv1.str->size; ++j) {
	    if (wv2.str->data[i-1 + j-1] != wv1.str->data[j-1]) {
		found = false;
		break;
	    }
	}
	if (found == true) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }

    ans->num = 0;
    signal(ERR_ok);
}


/*
 * Find wv1 in wv2; start looking at wv2[first].
 * Case doesn't matter.
 */
errcode
_wordvecOPnc_indexv(CLUREF wv1, CLUREF wv2, CLUREF first, CLUREF *ans)
{
    if (first.num < 1)
	signal(ERR_bounds);
    if (first.num > wv2.str->size)
	signal(ERR_bounds);

    bool found;
    for (long i = first.num; i + wv1.str->size - 1 <= wv2.str->size; ++i) {
	found = true;
	for (long j = 1; j <= wv1.str->size; ++j) {
	    char temp_c1 = wv1.str->data[j-1];
	    if (temp_c1 >= MIN_CAP_CHAR && temp_c1 <= MAX_CAP_CHAR)
		temp_c1 += OFF_CHAR;

	    char temp_c2 = wv2.str->data[i-1 + j-1];
	    if (temp_c2 >= MIN_CAP_CHAR && temp_c2 <= MAX_CAP_CHAR)
		temp_c2 += OFF_CHAR;

	    if (temp_c1 != temp_c2) {
		found = false;
		break;
	    }
	}
	if (found == true) {
	    ans->num = i;
	    signal(ERR_ok);
	}
    }

    ans->num = 0;
    signal(ERR_ok);
}


/*
 * original code tries to use more efficient instructions
 *	if the wordvecs are not identical,
 *	if they are the same and the destination is less than the source,
 *	if they are the same and the dest is gtr than the source and the
 *	    size of the dest is greater than the copycount
 *	if a single character is being propagated through a wordvec
 */
errcode
_wordvecOPmove_lr(CLUREF wv1, CLUREF s1, CLUREF wv2, CLUREF s2, CLUREF len)
{
    if (len.num < 0)
	signal(ERR_negative_size);
    if (s1.num < 1)
	signal(ERR_bounds);
    if (s1.num > wv1.str->size)
	signal(ERR_bounds);
    if (s2.num < 1)
	signal(ERR_bounds);
    if (s2.num >wv2.str->size)
	signal(ERR_bounds);

    int copycount = len.num;
    if (copycount + s1.num > wv1.str->size)
	copycount = wv1.str->size - s1.num + 1;
    if (copycount + s2.num > wv2.str->size)
	copycount = wv2.str->size - s2.num + 1;

    for (long i = 0; i < copycount; ++i)
	wv2.str->data[s2.num-1+i] = wv1.str->data[s1.num-1+i];

    signal(ERR_ok);
}



/*
 * Moves chars from a sequence of chars to a wordvec.
 */
errcode
_wordvecOPmove_v(CLUREF qc1, CLUREF s1, CLUREF wv2, CLUREF s2, CLUREF len)
{
    if (len.num < 0)
	signal(ERR_negative_size);
    if (s1.num < 1)
	signal(ERR_bounds);
    if (s1.num > qc1.vec->size)
	signal(ERR_bounds);
    if (s2.num < 1)
	signal(ERR_bounds);
    if (s2.num >wv2.str->size)
	signal(ERR_bounds);

    int copycount = len.num;
    if (copycount + s1.num > qc1.vec->size)
	copycount = qc1.vec->size - s1.num + 1;
    if (copycount + s2.num > wv2.str->size)
	copycount = wv2.str->size - s2.num + 1;

    for (long i = 0; i < copycount; ++i)
	wv2.str->data[s2.num-1+i] = qc1.vec->data[s1.num-1+i];

    signal(ERR_ok);
}


errcode
_wordvecOPmove_rl(CLUREF w1, CLUREF s1, CLUREF w2, CLUREF s2, CLUREF len)
{
    CLU_NOREF(w1);
    CLU_NOREF(s1);
    CLU_NOREF(w2);
    CLU_NOREF(s2);
    CLU_NOREF(len);

    fprintf(stderr, "_wordvec$move_rl not implemented\n");
    signal(ERR_failure);
}


errcode
_wordvecOPget_byte(CLUREF wv, CLUREF wrd, CLUREF bit, CLUREF len, CLUREF *ans)
{
    if (len.num <= 0)
	signal(ERR_illegal_size);
    if (len.num > 32)
	signal(ERR_illegal_size);

    int n1 = wrd.num << 2;
    if (n1 <= 0)
	signal(ERR_bounds);
    if (n1 > wv.str->size)
	signal(ERR_bounds);

    if (len.num > bit.num)
	signal(ERR_bounds);

    int result, mask;
    result = wv.vec->data[wrd.num - 1];
    result = result >> (32 - bit.num);

    mask =  (1 << len.num) - 1;
    /* printf("before %X %X\n", mask, result); */
    result = result & mask;
    /* printf("after %X %X\n", mask, result); */

    ans->num = result;
    signal(ERR_ok);
}


errcode
_wordvecOPset_byte(CLUREF wv, CLUREF byte, CLUREF wrd, CLUREF bit, CLUREF len)
{
    if (len.num <= 0)
	signal(ERR_illegal_size);
    if (len.num > 32)
	signal(ERR_illegal_size);

    int n1 = wrd.num << 2;
    if (n1 <= 0)
	signal(ERR_bounds);
    if (n1 > wv.str->size)
	signal(ERR_bounds);

    if (len.num > bit.num)
	signal(ERR_bounds);

    int slot, new_field, field_mask;
    field_mask = (1 << len.num) - 1;
    new_field = (byte.num & field_mask) << (32 - bit.num);
    field_mask = field_mask << (32 - bit.num);
    slot = wv.vec->data[wrd.num - 1];
    slot = slot & ~field_mask;
    slot |= new_field;
    wv.vec->data[wrd.num - 1] = slot;
    signal(ERR_ok);
}


errcode
_wordvecOPbyte_size(CLUREF *ans)
{
    ans->num = CHAR_BIT;
    signal(ERR_ok);
}


errcode
_wordvecOPword_size(CLUREF *ans)
{
    ans->num = CLUREFSZ * CHAR_BIT;
    signal(ERR_ok);
}


errcode
_wordvecOPbytes_per_word(CLUREF *ans)
{
    ans->num = CLUREFSZ;
    signal(ERR_ok);
}


/*
 * Moves bytes from a _bytevec to a wordvec.
 */
errcode
_wordvecOPmove_b2w(CLUREF b, CLUREF bpos, CLUREF w, CLUREF wpos, CLUREF n)
{
    if (n.num < 0)
	signal(ERR_negative_size); /* interface change */
    if (n.num == 0)
	signal(ERR_ok);

    if (bpos.num < 1)
	signal(ERR_bounds);
    if (bpos.num > b.str->size)
	signal(ERR_bounds);

    if (wpos.num < 1)
	signal(ERR_bounds);
    if (wpos.num > w.str->size)
	signal(ERR_bounds);

    int copycount = n.num;
    if (bpos.num + n.num > b.str->size)
	copycount = b.str->size - bpos.num + 1;
    if (wpos.num + copycount > w.str->size)
	copycount = w.str->size - wpos.num + 1;

    for (long i = 0; i < copycount; ++i)
	w.str->data[wpos.num-1+i] = b.str->data[bpos.num-1+i];

    signal(ERR_ok);
}


/*
 * Moves bytes from a _wordvec to a _bytevec.
 */
errcode
_wordvecOPmove_w2b(CLUREF w, CLUREF wpos, CLUREF b, CLUREF bpos, CLUREF n)
{
    if (n.num < 0)
	signal(ERR_negative_size); /* interface change */
    if (n.num == 0)
	signal(ERR_ok);

    if (bpos.num < 1)
	signal(ERR_bounds);
    if (bpos.num > b.str->size)
	signal(ERR_bounds);

    if (wpos.num < 1)
	signal(ERR_bounds);
    if (wpos.num > w.str->size)
	signal(ERR_bounds);

    int copycount = n.num;
    if (wpos.num + copycount > w.str->size)
	copycount = w.str->size - wpos.num + 1;
    if (bpos.num + copycount > b.str->size)
	copycount = b.str->size - bpos.num + 1;

    for (long i = 0; i < copycount; ++i)
	b.str->data[bpos.num-1+i] = w.str->data[wpos.num-1+i];

    signal(ERR_ok);
}


errcode
_wordvecOP_gcd(CLUREF w, CLUREF tab, CLUREF *ans)
{
    errcode err;

    CLUREF ginfo;		// := ginfo$make_a_bvec()
    err = oneofOPnew(CLU_1, CLU_0, &ginfo);
    if (err != ERR_ok)
	resignal(err);

    /* 8 for type + size, 1 for trailing 0, +3 &~3 to round up */
    CLUREF sz = {
	.num = (8 + (w.str->size + 1 + 3)) & ~3
    };
    err = gcd_tabOPinsert(tab, sz, ginfo, w, ans);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
_wordvecOPprint(CLUREF w, CLUREF pst)
{
    errcode err;

    err = stringOPprint(w, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}


errcode
_wordvecOPdebug_print(CLUREF w, CLUREF pst)
{
    errcode err;

    err = stringOPprint(w, pst);
    if (err != ERR_ok)
	resignal(err);

    signal(ERR_ok);
}



OWN_ptr _wordvec_own_init = { .init_flag = 1 };

#define CLU_proc_INIT(f) {			\
 /* .typ = { .val = CT_PROC }, */		\
    .proc = f,					\
    .type_owns = &_wordvec_own_init,		\
    .op_owns = &_wordvec_own_init,		\
}

static CLU_proc _wordvec_oe_create = CLU_proc_INIT(_wordvecOPcreate);
static CLU_proc _wordvec_oe_copy = CLU_proc_INIT(_wordvecOPcopy);
static CLU_proc _wordvec_oe_fetch = CLU_proc_INIT(_wordvecOPfetch);
static CLU_proc _wordvec_oe_store = CLU_proc_INIT(_wordvecOPstore);
static CLU_proc _wordvec_oe_size = CLU_proc_INIT(_wordvecOPsize);
static CLU_proc _wordvec_oe_equal = CLU_proc_INIT(_wordvecOPequal);
static CLU_proc _wordvec_oe_indexc = CLU_proc_INIT(_wordvecOPindexc);
static CLU_proc _wordvec_oe_indexv = CLU_proc_INIT(_wordvecOPindexv);
static CLU_proc _wordvec_oe_nc_indexv = CLU_proc_INIT(_wordvecOPnc_indexv);
static CLU_proc _wordvec_oe_move_lr = CLU_proc_INIT(_wordvecOPmove_lr);
static CLU_proc _wordvec_oe_move_v = CLU_proc_INIT(_wordvecOPmove_v);
static CLU_proc _wordvec_oe_print = CLU_proc_INIT(_wordvecOPprint);
static CLU_proc _wordvec_oe_debug_print = CLU_proc_INIT(_wordvecOPdebug_print);

static struct /* OPS */ {
    int count;
    OWNPTR type_owns;
    OWNPTR op_owns;
    struct OP_ENTRY entry[13];
} _wordvec_ops_actual = {
    13,
    &_wordvec_own_init,
    &_wordvec_own_init, {
	{ &_wordvec_oe_create, "create" },
	{ &_wordvec_oe_copy, "copy" },
	{ &_wordvec_oe_fetch, "fetch" },
	{ &_wordvec_oe_store, "store" },
	{ &_wordvec_oe_size, "size" },
	{ &_wordvec_oe_equal, "equal" },
	{ &_wordvec_oe_indexc, "indexc" },
	{ &_wordvec_oe_indexv, "indexv" },
	{ &_wordvec_oe_nc_indexv, "nc_indexv" },
	{ &_wordvec_oe_move_lr, "move_lr" },
	{ &_wordvec_oe_move_v, "move_v" },
	{ &_wordvec_oe_print, "print" },
	{ &_wordvec_oe_debug_print, "debug_print" },
    }
};

struct OPS *_wordvec_ops = (struct OPS *)&_wordvec_ops_actual;
