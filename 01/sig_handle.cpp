#include <sys/wait.h>
#include "apue.h"

static void sig_int(int);

int main() {
    char buff[MAXLINE];
    pid_t pid;
    int status;

    // the handler of signal SIGINT
    if ( signal(SIGINT, sig_int) == SIG_ERR ) {
        err_sys("signal error\n");
    }

    printf("%% ");
    while ( fgets(buff, MAXLINE, stdin) != NULL ) {
        if ( buff[strlen(buff) - 1] == '\n' ) {
            buff[strlen(buff) - 1] = '\0';
        }

        pid = fork();
        if ( pid < 0 ) {
            err_sys("fork error\n");
        } else if ( pid == 0  ) {
            execlp(buff, buff, (char*)0);
            // if execlp execute successfully, the next 2 lines in child
            // will not be executed
            err_ret("couldn't execute: %s", buff);
            exit(127);
        }
        //parent
        if ( (pid = waitpid(pid, &status, 0)) < 0 ) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo) {
    printf("interrupt\n");
}
