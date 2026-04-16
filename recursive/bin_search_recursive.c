#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* parse_integers(int argc, char** argv)
{
    int len = argc - 1;
    int* nums = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
       nums[i] = atoi(argv[i + 1]);
    }
    return nums;
}

int binary_search_recur(int x[], int key, int left, int right)
{
    int middle = (left + right) / 2;
    if (left >= right)
        return -1;
    else
    {
        if (x[middle] == key)
            return middle;
        else if (x[middle] < key)
            return binary_search_recur(x, key, middle + 1, right);
        else if (x[middle] > key)
            return binary_search_recur(x, key, left, middle - 1);
    }
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Usage: %s x1, x2, x3, ...\n", argv[0]);
        return 1;
    }

    int len = argc - 1;
    int* nums = parse_integers(argc, argv);
    int idx = binary_search_recur(nums, 7, 0, len);

    if (idx == -1)
        printf("7 Not found\n");
    else
        printf("Found %d at %d\n", nums[idx], idx);

    free(nums);
    return 0;
}
