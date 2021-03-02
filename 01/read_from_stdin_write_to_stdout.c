#include "apue.h"
/* #include "myerr.h" */

//////////////////////////////////////////////////////////////////////////////
// Description: 
//      This program reads from stdin and write to stdout.
//////////////////////////////////////////////////////////////////////////////
#define BUFFER_SIZE 4096

int main() {
    int n; 
    char buff[BUFFER_SIZE];
    while ( (n = read(STDIN_FILENO, buff, BUFFER_SIZE)) > 0 ) {
        if ( write(STDOUT_FILENO, buff, n) != n ) {
            err_sys("write error\n");
        }
    }
    if ( n < 0 ) err_sys("read erro\n");
    exit(0);
}
