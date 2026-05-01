#include <stdio.h>
#include "bst.h"
#include "../include/common.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1 x2 x3 ... xn\n", argv[0]);
        return 1;
    }
    
    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;
    bst_t bst;
    
    printf("Adding numbers to BST:\n");
    bst_print_preorder(&bst);
    for (int i = 0; i < len; i++) { 
        bst_add(&bst, arr[i]);
        bst_print_preorder(&bst);
    }

    printf("\nSearching for 13:\n");
    bst_node_t* node = bst_search(&bst, 13);
    if (node)
        printf("Found node data=%d, left=%p, right=%p\n", node->data, node->left, node->right);
    else
        printf("Node not found\n");

    bst_destroy(&bst);
    free(arr);
    return 0;
}
