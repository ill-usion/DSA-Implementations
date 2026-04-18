#include <stdio.h>
#include "../include/common.h"

void merge(int* arr, size_t start, size_t middle, size_t end) {
    int i, j;
    size_t aux_len = end - start + 1;
    int aux[aux_len];
    // Copy first half
    for (i = start; i <= middle; i++) {
        aux[i - start] = arr[i];
    }

    // Copy second half
    for (j = middle + 1; j <= end; j++) {
        aux[j - start] = arr[j];
    }

    i = start;
    j = middle + 1;
    for (size_t k = start; k <= end; k++) {
        // First half is exhausted, copy second half
        if (i > middle) {
            arr[k] = aux[j - start];
            j++;
        }
        // Second half is exhausted, copy first half
        else if (j > end) {
            arr[k] = aux[i - start];
            i++;
        }
        else if (aux[j - start] < aux[i - start]) {
            arr[k] = aux[j - start];
            j++;
        }
        else {
            arr[k] = aux[i - start];
            i++;
        }
    }
}

void merge_sort(int* arr, size_t start, size_t end) {
    if (start >= end)
        return;
    
    size_t middle = (start + end) / 2;
    merge_sort(arr, start, middle);
    merge_sort(arr, middle + 1, end);

    merge(arr, start, middle, end);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    
    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;
        
    merge_sort(arr, 0, len - 1);
    print_numbers(arr, len);
    free(arr);
    return 0;
}
