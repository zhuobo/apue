#include <stdio.h>
#include <fcntl.h>

int main() {
    FILE* file = fopen("foo", "r");
    char c;
    while ( (c = getc(file)) != EOF ) {
        printf("%c", c);
    }
    putchar('\n');
}
