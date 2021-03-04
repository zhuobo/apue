#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    struct tm *temp;
    char buff1[16];
    char buff2[64];
    time(&t);

    temp = localtime(&t);
    if ( strftime(buff1, 16, "time and data %r, %a %b %d, %Y", temp) == 0 ) {
        printf("buff1 length 16 is too small\n");
    } else {
        printf("%s\n", buff1);
    }
    if ( strftime(buff2, 64, "time and data %r, %a %b %d, %Y", temp) == 0 ) {
        printf("buff1 length 16 is too small\n");
    } else {
        printf("%s\n", buff2);
    }
    exit(0);
}
