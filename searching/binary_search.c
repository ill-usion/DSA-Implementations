#include "common.h"

int binary_search(int val, int *arr, size_t len)
{
    int left = 0, right = len - 1, mid;
    while (right >= left)
    {
        mid = (right + left) / 2;
        if (arr[mid] == val)
        {
            if ((mid > left) && (arr[mid - 1] == val))
                right = mid - 1;
            else
                return mid;
        }
        else if (arr[mid] > val)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int binary_search_smallest(int val, int *arr, size_t len)
{
    int left = 0, right = len - 1, mid;
    while (right >= left)
    {
        mid = (right + left) / 2;

        if (arr[mid] > val)
        {
            right = mid - 1;
        }
        else if ((mid < right) && (arr[mid + 1] < val))
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
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
    int idx = binary_search(13, arr, len);
    int idx_smallest = binary_search_smallest(13, arr, len);
    printf("binary_search(13) = %d\n", idx);
    printf("binary_search_smallest(13) = %d\n", idx_smallest);
    return 0;
}