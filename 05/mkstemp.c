#include "apue.h"
#include <stdio.h>

void make_temp(char *temp);


int main() {
    char good_temp[] = "/temp/dirXXXXXX"; // store in stack
    char *bad_temp = "/temp/dirXXXXXX";   // store in readonly data
    printf("trying to create first temp file...\n");
    make_temp(good_temp);
    printf("trying to create second temp file...\n");
    make_temp(bad_temp);
    exit(0);
}

void make_temp(char *temp) {
    int fd;
    struct stat sbuf;
    if ( (fd = mkstemp(temp)) < 0 ) {
        err_sys("can't create temp file");
    }
    printf("temp name = %s\n", temp);
    close(fd);
    if ( stat(temp, &sbuf) < 0 ) {
        if ( errno == ENOENT ) {
            printf("file doesn't exist\n");
        } else {
            err_sys("stat failed");
        }
    } else {
        printf("file exists\n");
        unlink(temp);
    }
}
