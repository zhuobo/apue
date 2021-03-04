#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("path: %s\n", getenv("PATH"));
    printf("user: %s\n", getenv("USER"));
    printf("home: %s\n", getenv("HOME"));
    printf("time zone: %s\n", getenv("TZ"));
    return 0;
}
