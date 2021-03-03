#include <sys/stat.h>
#include <string>
#include "apue.h"

using std::string;

int main(int argc, char *argv[]) {
    struct stat buff;
    for ( int i = 1; i < argc; ++i ) {
        printf("%s: ", argv[i]);
        string msg;
        if ( lstat(argv[i], &buff) < 0 ) {
            err_ret("lstat error\n");
            continue;
        }
        if ( S_ISREG(buff.st_mode) ) {
            msg = "regular";
        } else if ( S_ISDIR(buff.st_mode) ) {
            msg = "directory";
        } else if ( S_ISBLK(buff.st_mode) ) {
            msg = "block special";
        } else if ( S_ISFIFO(buff.st_mode) ) {
            msg = "name pipe";
        } else if ( S_ISLNK(buff.st_mode) ) {
            msg = "symbolic link";
        } else if ( S_ISCHR(buff.st_mode) ) {
            msg = "character special";
        } else if ( S_ISSOCK(buff.st_mode) ) {
            msg = "socket";
        } else {
            msg = "** unknow mode **";
        }
        printf("%s\n", msg.c_str());
    }
    exit(0);
}
