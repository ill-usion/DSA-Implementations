#include "common.h"

void selection_sort(int *arr, size_t len)
{
    int min, temp;
    for (int i = 0; i < len; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] > arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    selection_sort(arr, len);
    print_numbers(arr, len);
}
