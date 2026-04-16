#include "common.h"

double harmonic(int n)
{
    if (n == 1)
        return 1;

    return (1 / (double)n) + harmonic(n - 1);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s n\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    double result = harmonic(n);
    printf("%.3f\n", result); 

    return 0;
}
