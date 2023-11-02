//#include "apue.h"
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif
#define OPEN_MAX_GUESS 256
/*
* Если константа PATH_MAX не определена
* адекватность следующего числа не гарантируется
*/
long open_max(void) {
    if (openmax == 0) {
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0)
                openmax = OPEN_MAX_GUESS; /* неопределенный предел */
            else
                printf("Error");
        }
    }
    else {
        return openmax;
    }
    return(openmax);
}

int main() {
    long res = open_max();
    printf("OPEN_MAX: %ld", res);
    return 0;
}