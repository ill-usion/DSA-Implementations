#include "common.h"

void bubble_sort(int *arr, size_t len)
{
    bool swapped;
    for (int i = 0; i < len; i++)
    {
        swapped = false;
        for (int j = len - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                arr[j] = arr[j] ^ arr[j - 1];
                arr[j - 1] = arr[j] ^ arr[j - 1];
                arr[j] = arr[j] ^ arr[j - 1];
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("%s x1, x2, x3, ..., xn\n", argv[0]);
        return 1;
    }

    size_t len = argc - 1;
    int *arr = parse_numbers(argc, argv);
    bubble_sort(arr, len);
    print_numbers(arr, len);
}
