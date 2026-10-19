#include <stdio.h>
#include <stdlib.h>
#include "my_assert.h"

void foo(int num)
{
    my_assert(((num >= 0) && (num <= 100)));

    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[])
{
    int num;

    if (argc < 2) {
        fprintf(stderr,
                "Usage: %s aNumber\n(0 <= aNumber <= 100)\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    num = atoi(argv[1]);
    foo(num);

    return EXIT_SUCCESS;
}
