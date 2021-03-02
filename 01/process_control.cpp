#include <sys/wait.h>
#include "apue.h"

int main() {
    char buff[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while ( fgets(buff, MAXLINE, stdin) != NULL ) {
        if ( buff[strlen(buff) - 1] == '\n' ) {
            buff[strlen(buff) - 1] = 0;
        }
        pid = fork();
        if ( pid < 0 ) {
            err_sys("fork error\n");
        } else if ( pid == 0 ) {
            // child process
            execlp(buff, buff, (char*)0);
            err_ret("could't execute: %s\n", buff);
            exit(127);
        }
        printf("%d\n", pid);
        // parent
        if ( (pid = waitpid(pid, &status, 0)) < 0 ) {
            err_sys("waitpid error\n");
        }
        printf("%% ");
    }
    exit(0);
}
