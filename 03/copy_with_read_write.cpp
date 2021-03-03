#include "apue.h"

#define BUFFSIZE 4096

int main() {
    int n;
    char buff[BUFFSIZE];

    while ( (n = read(STDIN_FILENO, buff, BUFFSIZE - 1)) > 0 ) {
        if ( write(STDOUT_FILENO, buff, n) != n ) {
            err_sys("write error\n");
        }
    }
    if ( n < 0 ) {
        err_sys("read error\n");
    }
    exit(0);
}
