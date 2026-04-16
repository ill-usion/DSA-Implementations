#include <stdio.h>
#include "doubly_ll.h"
#include "../include/common.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }

    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;
    dll_t dll;
    dll_init(&dll);

    dll_print(&dll);
    printf("\nPushing even indicies:\n");
    for (int i = 0; i < len; i += 2) {
        dll_append(&dll, arr[i]);
        dll_print(&dll);
    }

    printf("\nInserting odd indicies:\n");
    for (int i = 1; i < len; i += 2) {
        dll_insert(&dll, i, arr[i]);
        dll_print(&dll);
    }

    printf("\nPop head:\n");
    dll_node_t* head_node = dll_pop(&dll, 0);
    printf("Old head node: { data=%d, prev=%p, next=%p }\n", head_node->data, head_node->prev, head_node->next);
    dll_print(&dll);

    printf("\nPop tail:\n");
    dll_node_t* tail_node = dll_pop_last(&dll);
    printf("Old tail node: { data=%d, prev=%p, next=%p }\n", tail_node->data, tail_node->prev, tail_node->next);
    dll_print(&dll);
    
    printf("\nAppend old head:\n");
    dll_append_node(&dll, head_node);
    dll_print(&dll);

    printf("\nPrepend old tail:\n");
    dll_insert_node(&dll, 0, tail_node);
    dll_print(&dll);

    dll_destroy(&dll);
    free(arr);
    return 0;
}
