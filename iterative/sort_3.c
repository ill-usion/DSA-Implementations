#include "common.h"

void sort_3(int* arr) {
    if (arr[0] > arr[1]) {
        arr[0] = arr[0] ^ arr[1];
        arr[1] = arr[0] ^ arr[1];
        arr[0] = arr[0] ^ arr[1];
    }

    if (arr[0] > arr[2]) {
        arr[0] = arr[0] ^ arr[2];
        arr[2] = arr[0] ^ arr[2];
        arr[0] = arr[0] ^ arr[2];
    }

    if (arr[1] > arr[2]) {
        arr[1] = arr[1] ^ arr[2];
        arr[2] = arr[1] ^ arr[2];
        arr[1] = arr[1] ^ arr[2];
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("%s x1, x2, x3\n", argv[0]);
        return 1;
    }

    size_t len = argc - 1;
    int* arr = parse_numbers(argc, argv);
    sort_3(arr);
    print_numbers(arr, len);

    free(arr);
}
