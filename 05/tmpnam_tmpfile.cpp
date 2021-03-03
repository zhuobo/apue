#include "apue.h"

int main() {
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    // two tmp name is different
    printf("%s\n", tmpnam(NULL)); // static
    tmpnam(name); // save in name
    printf("%s\n", name); // 
    // a temp file, will delete when the program is ended
    if ( (fp = tmpfile()) == NULL ) {
        err_sys("tmpfile error\n");
    }
    fputs("one line of output\n", fp);
    rewind(fp);
    if ( fgets(line, sizeof(line), fp) == NULL ) {
        err_sys("fgets error\n");
    }
    fputs(line, stdout);
}
