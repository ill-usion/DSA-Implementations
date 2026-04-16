#include "common.h"

int fib_iter(int n)
{
    int a;
    int b = 0;
    int result = 1;

    for (int i = 0; i < n - 1; i++)
    {
        a = b;
        b = result;
        result = a + b;
    }

    return result;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int result = fib_iter(n);
    printf("%d\n", result);

    return 0;
}
