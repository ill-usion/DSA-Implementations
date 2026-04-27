#include "single_ll.h"
#include <assert.h>

typedef struct {
    sll_t* sll;
    sll_node_t* top;
    size_t len;
} sll_stack_t;

void slls_init(sll_stack_t* slls) {
    sll_t* sll = (sll_t*) malloc(sizeof(sll_t));
    slls->sll = sll;
    slls->top = NULL;
    slls->len = 0;
}

void slls_print(sll_stack_t* slls) {
    if (slls->len != 0) {
        printf("TOP ");
        sll_node_t* current = slls->sll->head;
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
    }

    printf("NULL\n");
}

sll_node_t* slls_push(sll_stack_t* slls, int x) {
    assert(slls->sll != NULL);
    sll_node_t* new_node = sll_prepend(slls->sll, x);
    slls->top = new_node;
    slls->len++;

    return new_node;
}

sll_node_t* slls_pop(sll_stack_t* slls) {
    assert(slls->len != 0 && "Attempting to pop an empty stack");

    sll_node_t* popped_node = sll_pop(slls->sll, 0);
    slls->top = popped_node->next;
    slls->len--;

    return popped_node;
}

int slls_pop_val(sll_stack_t* slls) {
    assert(slls->len != 0 && "Attempting to pop an empty stack");

    sll_node_t* popped_node = sll_pop(slls->sll, 0);
    slls->top = popped_node->next;
    slls->len--;

    int value = popped_node->data;
    free(popped_node);

    return value;
}

void slls_destroy(sll_stack_t* slls) {
    sll_destroy(slls->sll);
    slls->top = NULL;
    slls->len = 0;
}
