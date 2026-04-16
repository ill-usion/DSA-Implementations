#include "common.h"

int sequential_search(int val, int *arr, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == val)
            return i;
        else if (arr[i] > val)
            return -1;
    }

    return -1;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("%d x1, x2, x3, ..., xn\n", argv[0]);
    }

    size_t len = argc - 1;
    int *arr = parse_numbers(argc, argv);
    int idx = sequential_search(13, arr, len);
    printf("sequential_search(13) = %d\n", idx);

    return 0;
}