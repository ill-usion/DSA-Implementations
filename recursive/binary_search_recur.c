#include <stdio.h>
#include "../include/common.h"

int binary_search_recur(int x, int* arr, int start, int end) {
    if (start >= end)
        return arr[end] == x ? end : -1;

    int mid = (start + end) / 2;
    if (arr[mid] == x) {
        return mid;
    }
    else if (arr[mid] > x) {
        return binary_search_recur(x, arr, 0, mid - 1);
    }
    else {
        return binary_search_recur(x, arr, mid + 1, end);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }

    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;

    int x;
    printf("Enter the number you want to search for: ");
    scanf("%d", &x);
    int idx = binary_search_recur(x, arr, 0, len - 1);
    if (idx == -1) {
        printf("%d was not found\n", x);
    }
    else {
        printf("%d was found at index %d\n", x, idx);
    }

    free(arr);
    return 0;
}
