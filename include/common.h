#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* parse_numbers(int argc, char** argv) {
    size_t len = argc - 1;
    int* nums = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        nums[i] = atol(argv[i + 1]);

    return nums;
}

void print_numbers(int* nums, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%ld ", nums[i]);
    }
    printf("\n");
}

int rand_range(int a, int b) {
    return a + (rand() * (b - a));
}

#endif
