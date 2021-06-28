/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		IMPLEMENTATION OF		*/
/*			_read_link		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <errno.h>
#include <unistd.h>

errcode file_nameOPunparse(CLUREF x, CLUREF *ret_1);
errcode file_name_fill(CLUREF fn, CLUREF dsuffix, CLUREF *ret_1);



errcode
_read_link(fn, buf, ans)
CLUREF fn, buf, *ans;
{
    errcode err;

    CLUREF newfn;
    err = file_name_fill(fn, CLU_empty_string, &newfn);
    if (err != ERR_ok)
	goto ex_0;

    CLUREF name;
    err = file_nameOPunparse(newfn, &name);
    if (err != ERR_ok)
	goto ex_0;

    /*
     * readlink(2) doesn't append a NUL byte, but clu allocator zeroes
     * the memory it returns, and _bytevec allocates an extra byte
     * (not acoounted for by buf.str->size), so there's always a NUL
     * byte after the string in the buffer.
     *
     * readlink(2) truncates silently.  "bounds" is not declared to be
     * signaled by _read_link() but if we wanted to detect it we would
     * need to pass size+1 to readlink to see if the extra terminator
     * byte is overwritten (and fix it up if it is).
     */
    ssize_t nbytes = readlink(name.str->data, buf.str->data, buf.str->size);
    if (nbytes < 0) {
	elist[0] = _unix_erstr(errno);
	signal(ERR_not_possible);
    }

    ans->num = nbytes;
    signal(ERR_ok);

  ex_0: {
	if (err != ERR_failure)
	    elist[0] = _pclu_erstr(err);
	signal(ERR_failure);
    }
}
