#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

ull fib_recur(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib_recur(n - 1) + fib_recur(n - 2);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s n\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    ull fib = fib_recur(n);
    printf("%llu\n", fib);
    return 0;
}
