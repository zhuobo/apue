#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main() {
    int len = sizeof(environ) / sizeof(environ[0]);
    for ( int i = 0; i < len; ++i ) {
        printf("%s\n", environ[i]);
    }
    exit(0);
}
