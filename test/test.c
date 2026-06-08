#include <stdio.h>

#include "rttest.h"

int main(void) {
    printf("[Test] - Running unit tests for the Culm Runtime...\n");

    int retv = 0;

    retv |= rttest_run_all();

    if (retv == 0) {
        printf("[Test] - All unit tests passed.\n");
    } else {
        fprintf(stderr, "[Test] - One or more unit tests failed.\n");
    }

    return retv;
}
