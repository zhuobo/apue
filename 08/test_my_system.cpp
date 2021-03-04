#include "my_system.h"
#include "apue.h"
#include <sys/wait.h>

int main() {
    int status;
    
    if ( (status = my_system("date")) < 0 ) {
        err_sys("my_system() error");
    }
    printf("status: %d\n", status);
    if ( (status = my_system("nosuchconmand")) < 0 ) {
        err_sys("my_system() error");
    }

    printf("status: %d\n", status);

    if ( (status = my_system("who; exit 44")) < 0 ) {
        err_sys("my_system() error");
    }

    printf("status: %d\n", status);

    exit(0);
}
