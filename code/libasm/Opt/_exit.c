/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*						*/
/*		IMPLEMENTATION OF		*/
/*			_exit			*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"
#undef _exit /* _OPexit */

#include <unistd.h>

errcode _chanOP_save_tty(void);
errcode _cleanup_(void);


errcode
_OPexit(CLUREF status)
{
    _cleanup_();
    _chanOP_save_tty();
    _exit(status.num);
}
