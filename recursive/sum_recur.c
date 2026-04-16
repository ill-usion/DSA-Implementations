#include "common.h"


int sum(int arr[], size_t len)
{
    if (len == 0)
        return 0;

    return arr[len - 1] + sum(arr, len - 1);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    int* nums = parse_numbers(argc, argv);
    size_t len = argc - 1;

    int result = sum(nums, len);
    printf("%d\n", result);
    return 0;
}
