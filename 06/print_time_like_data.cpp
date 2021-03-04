#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    struct tm *temp;
    char buff[64];
    time(&t);
    temp = localtime(&t);
    if ( strftime(buff, 64, "%a %d %b %G %r %Z", temp) == 0) {
        printf("buff too small\n");
    } else {
        printf("%s\n", buff);
    }
    exit(0);
}
