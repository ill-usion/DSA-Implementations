#include <stdio.h>
#include <stdlib.h>

int gcd(int n, int m) {
    if (n == 0) return m;

    while(m % n > 0)
    {
        int temp = m;
        m = n;
        n = temp % n;
    }
    return n;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("%s n m\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int result = gcd(n, m);
    printf("%d\n", result);
}
