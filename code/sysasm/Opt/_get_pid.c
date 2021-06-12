/* Copyright Massachusetts Institute of Technology 1990,1991 */

/*						*/
/*		Get (Unix) Process Id		*/
/*						*/

#include "pclu_err.h"
#include "pclu_sys.h"

#include <unistd.h>


errcode
_get_pid(CLUREF *ans)
{
    pid_t pid = getpid();

    ans->num = pid;
    signal(ERR_ok);
}
