#ifndef MY_ASSERT_H
#define MY_ASSERT_H

void my_assert_fail(const char *expression, const char *file,
                    int line, const char *function);

#ifdef NDEBUG

#define my_assert(expression) ((void)0)

#else

#define my_assert(expression) \
    ((expression) ? (void)0 : \
     my_assert_fail(#expression, __FILE__, __LINE__, __func__))

#endif

#endif
