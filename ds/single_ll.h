#include <stdint.h>
#include <stdlib.h>

typedef struct sll_node_t {
    int data;
    struct sll_node_t* next;
} sll_node_t;

typedef struct {
    sll_node_t* head;
} sll_t;

void sll_print(sll_t* sll) {
    sll_node_t* current = sll->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

sll_node_t* sll_new_node(int x) {
    sll_node_t* node = (sll_node_t*) malloc(sizeof(sll_node_t));
    node->data = x;
    node->next = NULL;

    return node;
}

sll_node_t* sll_append(sll_t* sll, int x) {
    if (sll->head == NULL) {
        sll_node_t* head = sll_new_node(x);
        sll->head = head;
        return head;
    }
    
    sll_node_t* new_node = sll_new_node(x);
    sll_node_t* current = sll->head;
    while (current->next)
        current = current->next;

    current->next = new_node;
    return new_node;
}

sll_node_t* sll_prepend(sll_t* sll, int x) {
    if (sll->head == NULL) {
        sll_node_t* head = sll_new_node(x);
        sll->head = head;
        return head;
    }
    
    sll_node_t* new_node = sll_new_node(x);
    new_node->next = sll->head;
    sll->head = new_node;
    
    return new_node;
}

sll_node_t* sll_insert(sll_t* sll, int pos, int x) {
    if (sll->head == NULL) {
        sll_node_t* head = sll_new_node(x);
        sll->head = head;
        return head;
    }

    int count = 0;
    sll_node_t* current = sll->head;
    while (count < pos - 1) {
        count++;
        current = current->next;
    }

    sll_node_t* new_node = sll_new_node(x);
    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}

sll_node_t* sll_pop(sll_t* sll, int pos) {
    int count = 0;
    sll_node_t* prev = NULL;
    sll_node_t* current = sll->head;
    while (count < pos) {
        prev = current;
        current = current->next;
        count++;
    }
    
    sll_node_t* next = current->next;
    if (sll->head == current)
        sll->head = next;

    if (prev != NULL)
        prev->next = next;

    current->next = NULL;
    return current;
}

void sll_delete(sll_t* sll, int pos) {
    int count = 0;
    sll_node_t* prev = NULL;
    sll_node_t* current = sll->head;
    while (count < pos) {
        prev = current;
        current = current->next;
        count++;
    }
    
    sll_node_t* next = current->next;
    if (sll->head == current)
        sll->head = next;

    if (prev != NULL)
        prev->next = next;

    free(current);
}

void sll_destroy(sll_t* sll) {
    sll_node_t* current = sll->head;

    while (current) {
        sll_node_t* next = current->next;
        free(current);
        current = next;
    }
}
