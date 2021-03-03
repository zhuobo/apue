#include <stdio.h>

int main() {
    FILE *file = fopen("foo", "r");
    if ( file == NULL ) {
        printf("open erro\n");
    }
    char buffer[1024];
    while ( (fgets(buffer, 1024, file)) != NULL ) {
        fputs(buffer, stdout);
    }
    return 0;
}
