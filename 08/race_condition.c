#include "apue.h"

static void charatatime(char *);

int main() {
    pid_t pid;
    TELL_WAIT();
    if ( (pid = fork()) < 0 ) {
        err_sys("fork error");
    } else if ( pid == 0 ) {
        WAIT_PARENT();
        charatatime("123456789abcdefghijklmnopqrstuvwxyz\n");
    } else {
        charatatime("123456789abcdefghijklmnopqrstuvwxyz\n");
        TELL_CHILD(pid);
    }
    exit(0);
}

static void charatatime(char* msg) {
    char *ptr;
    int c;
    setbuf(stdout, NULL);
    for ( ptr = msg; (c = *ptr++) != 0; ) {
        putc(c, stdout);
    }
}
