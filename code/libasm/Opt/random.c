/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			random			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

static CLUREF random_hi;
static CLUREF random_lo;
static int random_init = 0;

#define hi random_hi
#define lo random_lo
#define init random_init


/*
 * Restore initial seed.
 */
errcode
randomOPreset(void)
{
    hi.num = 0xbfc896df;
    lo.num = 0x6ab8724a;
    init = true;
    signal(ERR_ok);
}


/*
 * Modify current seed.
 */
errcode
randomOPseed(CLUREF x)
{
    if (!init) {
	hi.num = 0xbfc896df;
	lo.num = 0x6ab8724a;
	init = true;
    }
    hi.num = hi.num ^ x.num;
    signal(ERR_ok);
}


/*
 * 0 <= res < x
 */
errcode
randomOPnext(CLUREF x, CLUREF *ans)
{
    CLUREF temphi, templo;	/* aka n1 n0 */
    CLUREF save;		/* aka n2 */
    int flag;

    if (!init) {
	hi.num = 0xbfc896df;
	lo.num = 0x6ab8724a;
	init = true;
    }
    templo.num = lo.num;
    temphi.num = hi.num;
    lo.num = temphi.num;
    save.num = temphi.num;
    flag = temphi.num & 1;
#if 0				/* not necessary */
    temphi.num = temphi.num >> 1;
#endif
    templo.num = templo.num >> 1;
    templo.num = (templo.num & 0x7fffffff) | (flag << 31);
    save.num = save.num ^ templo.num;
    hi.num = save.num;
    save.num = save.num >> 2;

    /* force result non-negative */
    ans->num = (save.num & 0x7fffffff) % x.num;
    signal(ERR_ok);
}
