#include "apue.h"
#include <sys/stat.h>
#include <stdio.h>

void my_setbuf(FILE *fp, char* buf) {
    if ( buf == NULL ) {
        setvbuf(fp, buf, _IONBF, 0);
    } else {
        struct stat fp_stat;
        fstat(fileno(fp), &fp_stat);
        if ( S_ISCHR(fp_stat.st_mode) ) {
            setvbuf(fp, buf, _IOLBF, BUFSIZ);
        } else {
            setvbuf(fp, buf, _IONBF, BUFSIZ);
        }

    }
}
