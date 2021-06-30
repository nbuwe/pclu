/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_groups			*/
/*						*/

#include <sys/param.h>
#include <errno.h>
#include <unistd.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

errcode sequenceOPnew(CLUREF *ans);

/*
 * POSIX requires {NGROUPS_MAX} to be at least 8, NetBSD has 16, but
 * Linux has 64K, so allocating that statically or dynamically is a
 * bit of an overkill.
 *
 * {NGROUPS_MAX} is not necessarily a constant on all implementations.
 */
#define NGROUPS_STATIC 16


errcode
_groups(CLUREF *ans)
{
    int ngroups;

    gid_t gidset_static[NGROUPS_STATIC];
    int ngroups_max = NGROUPS_STATIC;
    gid_t *gidset = gidset_static;

    ngroups = getgroups(ngroups_max, gidset);
    if (ngroups < 0) {
	if (errno != EINVAL)
	    goto ex_errno;

	/*
	 * EINVAL means the local fixed size array was too small, so
	 * we need to go dynamic.  Ask the system how much we need
	 * (and assume that that value won't change).
	 */
	ngroups_max = getgroups(0, gidset);
	if (ngroups_max < 0)	/* very unlikely */
	    goto ex_errno;

	clu_alloc_atomic(ngroups_max * sizeof(gid_t), &gidset);
	ngroups = getgroups(ngroups_max, gidset);
	if (ngroups < 0)
	    goto ex_errno;
    }

    if (ngroups == 0) {		/* should not happen */
	sequenceOPnew(ans);
	signal(ERR_ok);
    }

    CLUREF groups;
    sequenceOPnew2(CLUREF_make_num(ngroups), &groups);
    for (int i = 0; i < ngroups; ++i)
	groups.vec->data[i] = gidset[i];

    *ans = groups;
    signal(ERR_ok);

  ex_errno: {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }
}
