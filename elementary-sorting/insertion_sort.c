#include "common.h"

void insertion_sort(int *arr, size_t len)
{
    int temp;
    int j;
    for (int i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i;
        while ((j > 0) && (arr[j - 1] < temp))
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
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
    insertion_sort(arr, len);
    print_numbers(arr, len);

    return 0;
}
