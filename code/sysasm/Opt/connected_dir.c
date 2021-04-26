/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*							*/
/*		GET CURRENT (-or- CONNECTED) DIRECTORY	*/
/*							*/

/* TODO: signals could more nearly emulate original	*/

#include <sys/param.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

errcode stringOPcons(const char *buf, CLUREF start, CLUREF len, CLUREF *ans);


/*
 * connected_dir = proc () returns (string)
 */
errcode
connected_dir(CLUREF *ans)
{
    CLUREF temp;
    errcode err;

    static char name[MAXPATHLEN]; /* static: CLU does not support threading */
    const char *result = getcwd(name, sizeof(name));
    if (result == NULL) {
	elist[0] = cannot_get_connected_directory_STRING;
#if 0
	/* new behavior: probably unnecessary */
	elist[1] = _unix_erstr(errno);
#endif
	signal(ERR_failure);
    }

    size_t len = strlen(name);
    if (len == 0 || name[0] != '/') {
	elist[0] = cannot_get_connected_directory_STRING;
	signal(ERR_failure);
    }

    if (len > 1)	/* not root (single "/") */
	++len;		/* dst: space for slash; src: '\0' terminator */
    err = stringOPcons(name, CLU_1, CLUREF_make_num(len), &temp);
    if (err != ERR_ok)
	resignal(err);

    if (len > 1)
	temp.str->data[len - 1] = '/';
    ans->str = temp.str;
    signal(ERR_ok);
}
