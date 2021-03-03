#include <fcntl.h>
#include "apue.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
    int fd = creat("file.hole", FILE_MODE);
    if ( fd < 0 ) {
        err_sys("create file error\n");
    }
    if ( write(fd, buf1, 10) != 10 ) {
        err_sys("buf1 write error\n");
    }

    // create a hole in the file fd
    if ( lseek(fd, 16384, SEEK_SET) == -1 ) {
        err_sys("lseek error");
    }

    if ( write(fd, buf2, 10) != 10 ) {
        err_sys("buf2 write error\n");
    }
    exit(0);
}
