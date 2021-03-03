#include <fcntl.h>
#include "apue.h"

int main(int argc, char* argv[]) {
    int val;
    if ( argc != 2 ) {
        err_quit("usage: a.out <description#>");
    }
    if ( (val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0 ) {
        err_sys("fcntl error for fd %d\n", atoi(argv[1]));
    }
    switch(val & O_ACCMODE) {
    case O_RDONLY:
        printf("read only\n");
        break;
    case O_WRONLY:
        printf("write only\n");
        break;
    case O_RDWR:
        printf("read and write\n");
        break;
    default:
        err_dump("unknow access mode\n");
    }

    if ( val & O_APPEND ) {
        printf(", append\n");
    }
    if ( val & O_NONBLOCK ) {
        printf(", nonblock\n");
    }
    if ( val & O_SYNC ) {
        printf(", sync writes\n");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if ( val & O_FSYNC ) {
        prinf(", sync writes\n");
    }
#endif

    putchar('\n');
    exit(0);
}
