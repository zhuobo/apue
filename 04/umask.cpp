#include <fcntl.h>
#include "apue.h"

int main() {
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    umask(0);
    int fd1 = creat("foo", mode);
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    int fd2 = creat("bar", mode);
}
