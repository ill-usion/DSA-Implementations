#ifndef SLL_QUEUE_H
#define SLL_QUEUE_H

#include "single_ll.h"
#include <assert.h>

typedef struct {
    sll_t* sll;
    sll_node_t* front;
    sll_node_t* rear;
    size_t len;
} sll_queue_t;

void sllq_init(sll_queue_t* sllq) {
    sll_t* sll = (sll_t*) malloc(sizeof(sll_t));
    sllq->sll = sll;
    sllq->front = NULL;
    sllq->rear = NULL;
    sllq->len = 0;
}

void sllq_print(sll_queue_t* sllq) {
    printf("FRONT ");
    if (sllq->len != 0) {
        sll_node_t* current = sllq->sll->head;
        while (current) {
            printf("%d <- ", current->data);
            current = current->next;
        }
    }
    printf("REAR\n");
}

sll_node_t* sllq_enqueue(sll_queue_t* sllq, int x) {
    sll_node_t* new_node = sll_append(sllq->sll, x);
    if (sllq->len == 0) {
        sllq->front = new_node; 
    }
    sllq->rear = new_node;
    sllq->len++;

    return new_node;
}

sll_node_t* sllq_dequeue(sll_queue_t* sllq) {
    assert(sllq->len != 0 && "Queue is empty");

    sll_node_t* dequeued = sll_pop(sllq->sll, 0);
    if (sllq->front == sllq->rear) {
        sllq->front = NULL;
        sllq->rear = NULL;
    }
    else {
        sllq->front = dequeued->next;
    }

    sllq->len--;
    return dequeued;
}

int sllq_dequeue_val(sll_queue_t* sllq) {
    assert(sllq->len != 0 && "Queue is empty");

    sll_node_t* dequeued = sll_pop(sllq->sll, 0);
    if (sllq->front == sllq->rear) {
        sllq->front = NULL;
        sllq->rear = NULL;
    }
    else {
        sllq->front = dequeued->next;
    }

    sllq->len--;
    int val = dequeued->data;
    free(dequeued);
    return val;
}

void sllq_destroy(sll_queue_t* sllq) {
    sll_destroy(sllq->sll);
    free(sllq->sll);

    sllq->front = NULL;
    sllq->rear = NULL;
    sllq->len = 0;
}

#endif
