/* Copyright Massachusetts Institute of Technology 1990,1991 */

#include <sys/param.h>
#include <errno.h>
#include <unistd.h>
#undef signal

#include "pclu_err.h"
#include "pclu_sys.h"


errcode
_host_name(CLUREF *ans)
{
    int status;

    char buf[MAXHOSTNAMELEN];
    status = gethostname(buf, sizeof(buf));
    if (status != 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    size_t len = strlen(buf);
    stringOPcons(buf, CLU_1, CLUREF_make_num(len), ans);
    signal(ERR_ok);
}
