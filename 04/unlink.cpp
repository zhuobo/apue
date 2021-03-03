#include <fcntl.h>
#include "apue.h"

int main() {
    if ( open("tempfile", O_RDWR) < 0 ) {
        err_sys("open error\n");
    }
    // remove does the same job as unlink
    if ( unlink("tempfile") < 0 ) {
        err_sys("unlink error\n");
    }
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    exit(0);
}
