#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;
    const char *error;
    double a = 10.0;
    double b = 3.0;

    double (*add)(double, double);
    double (*subtract)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);

    handle = dlopen("./lib/libcalc.so", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    dlerror();
    add = dlsym(handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    dlerror();
    subtract = dlsym(handle, "subtract");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    dlerror();
    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    dlerror();
    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    printf("add = %.2f\n", add(a, b));
    printf("subtract = %.2f\n", subtract(a, b));
    printf("multiply = %.2f\n", multiply(a, b));
    printf("divide = %.2f\n", divide(a, b));

    if (dlclose(handle) != 0) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    return 0;
}
