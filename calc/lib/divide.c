#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

double divide(double a, double b)
{
    if (b == 0.0) {
        fprintf(stderr, "Error: division by zero.\n");
        exit(EXIT_FAILURE);
    }

    return a / b;
}
