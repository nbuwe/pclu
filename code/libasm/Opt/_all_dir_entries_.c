/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_all_dir_entries_	*/
/*						*/

#include <sys/types.h>
#include <dirent.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>

errcode _bytevecOPcreate(CLUREF sz, CLUREF *ans);


/* _all_dir_entries_ iterator body callback */
typedef errcode (*iter_body_t)(CLUREF iv_1, CLUREF iv_2,
			       void *locals, errcode *iecode);

errcode
_all_dir_entries_(CLUREF dir,
		  iter_body_t iterbody, void *user_locals, errcode *iecode)
{
    errcode err;

    DIR *dirp;
    dirp = opendir(dir.str->data);
    if (dirp == NULL)  {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    for (;;) {
	struct dirent *dp;

	errno = 0; /* NULL is returned both at the end and on error */
	dp = readdir(dirp);
	if (dp == NULL) {
	    if (errno != 0) {	/* really an error */
		elist[0] = _unix_erstr(errno);
		signal(ERR_not_possible);
	    }

	    /* end of the directory */
	    break;
	}

	/* skip "." and ".." */
	if (dp->d_name[0] == '.'
	    && (dp->d_name[1] == '\0'
		|| (dp->d_name[1] == '.'
		    && (dp->d_name[2] == '\0'))))
	    continue;

	CLUREF name;
	size_t namelen = strlen(dp->d_name);
	err = _bytevecOPcreate(CLUREF_make_num(namelen), &name);
	if (err != ERR_ok)
	    goto ex_0;

	strcpy(name.str->data, dp->d_name);
	err = (*iterbody)(CLU_1, name, /* yields */
			  user_locals, iecode);
	if (err == ERR_ok)
	    continue;

#if 0	/* XXX? */
	if (err == ERR_break) signal(err); /* was: break; */
	if (err == ERR_forbodyexit) signal(err);
	if (err == ERR_forbodyreturn) signal(err);
	if (err == ERR_forbodysignal) signal(err);
	if (err == ERR_iterforbodyexit) signal(err);
	if (err == ERR_iterforbodyreturn) signal(err);
	if (err == ERR_iterforbodysignal) signal(err);
#endif
	signal(err);
    }

    closedir(dirp);
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
