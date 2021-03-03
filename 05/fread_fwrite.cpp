#include <stdio.h>
#include "apue.h"

int main() {
    float data[10] = { 1.1, 2, 32.2, 34, 1.3, 3.2, 5.7, 8 };
    if ( fwrite(&data[3], sizeof(float), 5, stdout) != 5 ) {
        err_sys("fwrite erroe\n");
    }

}
