#include <stdio.h>
#include "sorted_dll.h"
#include "../include/common.h"


int main(int argc, char** argv) {
    if (argc < 4) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;
    sdll_t sdll;
    sdll_init(&sdll);
        
    printf("Pushing numbers:\n");
    sdll_print(&sdll);
    for (int i = 0; i < len; i++) {
        sdll_push(&sdll, arr[i]);
        sdll_print(&sdll);
    }
    
    printf("\nPopping head:\n");
    sdll_node_t* head_node = sdll_pop(&sdll, 0);
    printf("Head node: { data=%d, prev=%p, next=%p }\n", head_node->data, head_node->prev, head_node->next);
    sdll_print(&sdll); 

    printf("\nPopping tail:\n");
    sdll_node_t* tail_node = sdll_pop_last(&sdll);
    printf("Tail node: { data=%d, prev=%p, next=%p }\n", tail_node->data, tail_node->prev, tail_node->next);
    sdll_print(&sdll); 

    printf("\nModifying head:\n");
    sdll.head->data++;
    sdll.head->data *= 2;
    sdll_print(&sdll); 

    printf("\nModifying middle:\n");
    sdll_node_t* mid_node = sdll_get(&sdll, sdll.len / 2);
    mid_node->data %= 2;
    sdll_print(&sdll); 

    printf("\nModifying tail:\n");
    sdll.tail->data--;
    sdll.tail->data /= 2;
    sdll_print(&sdll); 

    printf("\nPushing old head and tail nodes:\n");
    sdll_push_node(&sdll, head_node);
    sdll_push_node(&sdll, tail_node);
    sdll_print(&sdll); 

    if (sdll_is_sorted(&sdll)) {
        printf("\nLinked list is sorted\n");
    }
    else {
        printf("\nLinked list is unsorted. Sorting...\n");
        sdll_sort(&sdll);
    }

    sdll_print(&sdll); 

    sdll_destroy(&sdll);
    free(arr);
    return 0;
}
