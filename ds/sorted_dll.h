#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sdll_node_t {
    int data;
    struct sdll_node_t* next;
    struct sdll_node_t* prev;
} sdll_node_t;

typedef struct {
    sdll_node_t* head;
    sdll_node_t* tail;
    size_t len;
} sdll_t;

void sdll_init(sdll_t* sdll) {
    sdll->head = NULL;
    sdll->tail = NULL;
    sdll->len = 0;
}

void sdll_print(sdll_t* sdll) {
    sdll_node_t* current = sdll->head;
    printf("[len=%d] ", sdll->len);
    while (current) {
        if (current->prev == NULL && current->next == NULL)
            printf("NULL <- %d -> ", current->data);
        else if (current->prev == NULL) 
            printf("NULL <- %d <-> ", current->data);
        else if (current->prev->next == current && current->next != NULL)
            printf("%d <-> ", current->data);
        else
            printf("%d -> ", current->data);

        current = current->next;
    }
    printf("NULL\n");
}

sdll_node_t* sdll_new_node(int x) {
    sdll_node_t* node = (sdll_node_t*) malloc(sizeof(sdll_node_t));
    if (node == NULL) {
        perror("Error allocating new node");
        exit(1);
    }

    node->data = x;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

sdll_node_t* sdll_get(sdll_t* sdll, int pos) {
    if (sdll->len - 1 < pos)
        return NULL;

    int count = 0;
    sdll_node_t* current = sdll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }

    return current;
}

sdll_node_t* sdll_set(sdll_t* sdll, int pos, int x) {
    sdll_node_t* current = sdll_get(sdll, pos);
    if (current == NULL)
        return NULL;

    current->data = x;
    return current;
}

bool sdll_is_sorted(sdll_t* sdll) {
    if (sdll->len == 0 || sdll->len == 1)
        return true;

    sdll_node_t* current = sdll->head->next;
    while (current) {
        if (current->data < current->prev->data)
            return false;

        current = current->next;
    }

    return true;
}

sdll_node_t* sdll_push(sdll_t* sdll, int x) {
    // Empty list
    if (sdll->tail == NULL) {
        sdll_node_t* headtail = sdll_new_node(x);
        sdll->head = headtail;
        sdll->tail = headtail;
        sdll->len++;

        return headtail;
    }
    
    // Look for the smallest node greater than x
    sdll_node_t* current = sdll->head;
    while (current->next && current->data < x)
        current = current->next;

    sdll_node_t* new_node = sdll_new_node(x);
    // If there was no "smallest node greater than x",
    // it could possibly be a tail node, so push in front of current
    if (x > current->data) {
        new_node->prev = current;
        current->next = new_node;
        
        // Make new node tail if current is tail
        // since we pushed after current
        if (current == sdll->tail)
            sdll->tail = new_node;
    }
    else {
        // Otherwise insert the new node before our current node
        new_node->next = current;
        
        // Update previous node's next pointer (current != head)
        if (current->prev)
            current->prev->next = new_node;
        
        // Make new node's previous node to current's previous (could be NULL)
        new_node->prev = current->prev;
        current->prev = new_node; // Update the current node's previous pointer
    
        // Make new node head if current is head
        // since we pushed before head
        if (current == sdll->head)
            sdll->head = new_node;
    }

    sdll->len++;

    return new_node;
}

sdll_node_t* sdll_push_node(sdll_t* sdll, sdll_node_t* node) {
    if (node == NULL)
        return NULL;

    // Empty list
    if (sdll->tail == NULL) {
        sdll->head = node;
        sdll->tail = node;
    }
    else {
        sdll_node_t* current = sdll->head;
        // Look for the smallest node greater than node data
        while (current->next && current->data < node->data)
            current = current->next;

        // If there was no "smallest node greater than node data",
        // it could possibly be a tail node, so push in front of current
        if (node->data > current->data) {
            node->prev = current;
            current->next = node;

            // Make new node tail if current is tail
            // since we pushed after current
            if (current == sdll->tail)
                sdll->tail = node;
        }
        else {
            // Otherwise insert the new node before our current node
            node->next = current;

            // Update previous node's next pointer (current != head)
            if (current->prev)
                current->prev->next = node;

            // Make new node's previous node to current's previous (could be NULL)
            node->prev = current->prev;
            current->prev = node; // Update the current node's previous pointer

            // Make new node head if current is head
            // since we pushed before current
            if (current == sdll->head)
                sdll->head = node;
        }
    }
    sdll->len++;

    return node;
}

sdll_node_t* sdll_pop_last(sdll_t* sdll) {
    // Attemptying to pop empty list
    if (sdll->tail == NULL)
        return NULL;

    sdll_node_t* popped = sdll->tail;
    // There exists a previous node
    if (popped->prev) {
        sdll->tail = popped->prev; // Move tail to previous node
        // Completely detach old tail
        popped->prev->next = NULL;
        popped->prev = NULL;
    }
    // If previous was empty, it means head = tail
    else {
        // Detach node from list
        sdll->head = NULL;
        sdll->tail = NULL;
    }
    sdll->len--;

    return popped;
}

sdll_node_t* sdll_pop(sdll_t* sdll, int pos) {
    // Index out of bounds
    if (sdll->len - 1 < pos)
        return NULL;

    int count = 0;
    sdll_node_t* current = sdll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }
    
    sdll_node_t* next = current->next;
    sdll_node_t* prev = current->prev;
    // Trying to pop the head
    if (sdll->head == current)
        sdll->head = next; // Update head to be the next node
    
    // Trying to pop the tail
    if (sdll->tail == current)
        sdll->tail = prev; // Update tail to be the previous node

    // The above statements would still produce a vaid list
    // even when next and/or prev are NULL

    // There exists a previous node (current is not head)
    if (prev != NULL)
        prev->next = next; // Connect previous to next
    
    // There exists a next node (current is not tail)
    if (next != NULL)
        next->prev = prev; // Connect next to previous
    
    // Detach popped node
    current->next = NULL;
    current->prev = NULL;
    sdll->len--;

    return current;
}

void sdll_delete(sdll_t* sdll, int pos) {
    // Index out of bounds
    if (sdll->len - 1 < pos)
        return;

    int count = 0;
    sdll_node_t* current = sdll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }
    
    sdll_node_t* next = current->next;
    sdll_node_t* prev = current->prev;
    // Trying to delete the head
    if (sdll->head == current)
        sdll->head = next; // Update head to be the next node
    
    // Trying to delete the tail
    if (sdll->tail == current)
        sdll->tail = prev; // Update tail to be the previous node

    // The above statements would still produce a vaid list
    // even when next and/or prev are NULL

    // There exists a previous node (current is not head)
    if (prev != NULL)
        prev->next = next; // Connect previous to next
    
    // There exists a next node (current is not tail)
    if (next != NULL)
        next->prev = prev; // Connect next to previous
    
    sdll->len--;
    free(current);
}

// Simple bubble sort
void sdll_sort(sdll_t* sdll) {
    bool swapped = false;
    sdll_node_t* node_a, * node_b;

    for (int i = 0; i < sdll->len; i++) {
        swapped = false;
        for (int j = sdll->len - 1; j > i; j--) {
            node_a = sdll_get(sdll, j);
            node_b = sdll_get(sdll, j - 1);

            if (node_a->data < node_b->data) {
                node_a->data = node_a->data ^ node_b->data;
                node_b->data = node_a->data ^ node_b->data;
                node_a->data = node_a->data ^ node_b->data;

                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void sdll_destroy(sdll_t* sdll) {
    sdll_node_t* current = sdll->head;

    while (current) {
        sdll_node_t* next = current->next;
        free(current);
        current = next;
    }

    sdll->len = 0;
    sdll->head = NULL;
    sdll->tail = NULL;
}
