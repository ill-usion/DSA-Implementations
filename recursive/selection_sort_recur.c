#include "common.h"

void selection_sort_recur(int arr[], size_t start, size_t end)
{
    if (start == end - 1)
        return;
    
    int min = start;
    for (int i = start + 1; i < end; i++)
        if (arr[i] < arr[min])
            min = i;

    int temp = arr[start];
    arr[start] = arr[min];
    arr[min] = temp;

    selection_sort_recur(arr, start + 1, end);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    int* nums = parse_numbers(argc, argv);
    size_t len = argc - 1;

    selection_sort_recur(nums, 0, len);

    print_numbers(nums, len);
    return 0;
}
