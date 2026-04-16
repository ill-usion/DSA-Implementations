
#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
    if (n == 0) return m;
    
    return gcd(n, m % n);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("%s m n\n");
        return 1;
    }

    int n = atoi(argv[2]);
    int m = atoi(argv[1]);

    int result = gcd(m, n);
    printf("%d\n", result);
}
