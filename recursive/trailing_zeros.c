#include <stdlib.h>
#include <stdio.h>

int count_trailing_zeros(int n) {
    if (n == 0) return 32;
    if ((n & 1) == 0) return 1 + count_trailing_zeros(n >> 1);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s bin\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int trailing = count_trailing_zeros(n);
    printf("%d\n", trailing);
    return 0;
}
