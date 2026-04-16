#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_digits(int n) {
    if (n < 10) {
        printf("%d ", n);
    }
    else {
        // recursive call then print => prints in order
        // print then recursive call => prints in reverse order
        printf("%d ", n % 10);
        print_digits(n / 10);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    print_digits(n);
    printf("\n");

    return 0;
}
