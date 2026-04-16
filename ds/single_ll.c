#include <stdio.h>
#include "single_ll.h"
#include "../include/common.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 0;
    }

    size_t len = argc - 1;
    int* arr = parse_numbers(argc, argv);

    sll_t sll;
    sll_print(&sll);
    printf("Pushing even indicies:\n");
    for (int i = 0; i < len; i += 2) {
        sll_append(&sll, arr[i]);
        sll_print(&sll);
    }
    
    printf("Inserting odd indicies:\n");
    for (int i = 1; i < len; i += 2) {
        sll_insert(&sll, i, arr[i]);
        sll_print(&sll);
    }

    printf("Deleting even indicies:\n");
    sll_node_t* node;
    for (int i = 0; i < len / 2; i++) {
        node = sll_pop(&sll, i);
        free(node);
        sll_print(&sll);
    }

    sll_destroy(&sll);
    free(arr);
    return 0;
}
