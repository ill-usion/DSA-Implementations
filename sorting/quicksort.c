#include "../include/common.h"

void compare_swap(int* arr, int left, int right) {
    if (arr[right] < arr[left])
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}    

int partition(int* arr, int left, int right) {
    // Changing the partition does not affect the algorithm
    int pivot = right;
    int i = left;
    int j = right - 1;
    int temp;
    while (j > i) {
        while (i <= j && arr[i] <= arr[pivot])
            i++;

        while (i <= j && arr[j] > arr[pivot])
            j--;

        if (j > i) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap elements at positions i and pivot
    temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;

    return i;
}


void quick_sort(int* arr, int left, int right) {
    if ((right - left + 1) <= 2) // 0, 1, or 2 elements
    {
        if ((right - left + 1) == 2)
            compare_swap(arr, left, right);
        return;
    }

    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    size_t len = argc - 1;
    int* arr = parse_numbers(argc, argv);
    
    quick_sort(arr, 0, len - 1);
    print_numbers(arr, len);

    free(arr);
    return 0;
}
