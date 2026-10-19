#include <stdio.h>
#include <stdlib.h>
#include "my_assert.h"

void my_assert_fail(const char *expression, const char *file,
                    int line, const char *function)
{
    fprintf(stderr, "%s:%d: %s: Assertion `%s' failed.\n",
            file, line, function, expression);

    abort();
}

