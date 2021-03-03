#include <fcntl.h>
#include "apue.h"

int set_fl(int fd, int flag) {
    int old_option = fcntl(fd, F_GETFL, 0);
    if ( old_option < 0 ) {
        err_sys("fcntl getfl error\n");
    }
    int new_option = old_option | flag;
    if ( fcntl(fd, F_SETFL, new_option ) < 0) {
        err_sys("fcntl setfl error\n");
    }
    return old_option;
}
