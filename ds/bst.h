#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <assert.h>

typedef struct bst_node_t {
    struct bst_node_t* left;
    struct bst_node_t* right;
    int data;
} bst_node_t;

typedef struct {
    bst_node_t* root;
} bst_t;

bst_node_t* bst_new_node(int x) {
    bst_node_t* node = (bst_node_t*) malloc(sizeof(bst_node_t));
    node->left = NULL;
    node->right = NULL;
    node->data = x;

    return node;
}

void bst_node_print_preorder(bst_node_t* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    bst_node_print_preorder(node->left);
    bst_node_print_preorder(node->right);
}

void bst_print_preorder(bst_t* bst) {
    bst_node_print_preorder(bst->root);
    printf("\n");
}

void bst_node_add(bst_node_t* new_node, bst_node_t* parent) {
    assert(parent != NULL && "Attemping to add a new node to a NULL parent");

    if (parent->data > new_node->data) {
        if (parent->left)
            bst_node_add(new_node, parent->left);
        else
            parent->left = new_node;
    }
    else {
        if (parent->right)
            bst_node_add(new_node, parent->right);
        else
            parent->right = new_node;
    }
}

bst_node_t* bst_add(bst_t* bst, int x) {
    bst_node_t* new_node = bst_new_node(x);
    if (bst->root == NULL) {
        bst->root = new_node;
    }
    else {
        bst_node_add(new_node, bst->root);
    }

    return new_node;
}

bst_node_t* bst_node_search(bst_node_t* node, int x) {
    if (node == NULL)
        return NULL;

    if (node->data == x)
        return node;
    else if (node->data < x)
        return bst_node_search(node->right, x);
    else
        return bst_node_search(node->left, x);
}

bst_node_t* bst_search(bst_t* bst, int x) {
    return bst_node_search(bst->root, x);
}

void bst_destroy_node(bst_node_t* node) {
    if (node == NULL)
        return;

    bst_destroy_node(node->left);
    bst_destroy_node(node->right);
    free(node);
}

void bst_destroy(bst_t* bst) {
    bst_destroy_node(bst->root);
}

#endif
