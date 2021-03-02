#include <error.h>
#include "apue.h"

int main(int argc, char* argv[]) {
    fprintf(stderr, "EACCCES: %s\n", strerror(EBADF));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
