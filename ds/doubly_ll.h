#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <stdint.h>
#include <stdlib.h>

typedef struct dll_node_t {
    int data;
    struct dll_node_t* next;
    struct dll_node_t* prev;
} dll_node_t;

typedef struct {
    dll_node_t* head;
    dll_node_t* tail;
    size_t len;
} dll_t;

void dll_init(dll_t* dll) {
    dll->head = NULL;
    dll->tail = NULL;
    dll->len = 0;
}

void dll_print(dll_t* dll) {
    dll_node_t* current = dll->head;
    printf("[len=%d] ", dll->len);
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

dll_node_t* dll_new_node(int x) {
    dll_node_t* node = (dll_node_t*) malloc(sizeof(dll_node_t));
    if (node == NULL) {
        perror("Error allocating new node");
        exit(1);
    }

    node->data = x;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

dll_node_t* dll_get(dll_t* dll, int pos) {
    if (dll->len - 1 < pos)
        return NULL;

    int count = 0;
    dll_node_t* current = dll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }

    return current;
}

dll_node_t* dll_set(dll_t* dll, int pos, int x) {
    dll_node_t* current = dll_get(dll, pos);
    if (current == NULL)
        return NULL;

    current->data = x;
    return current;
}

dll_node_t* dll_append(dll_t* dll, int x) {
    // Empty list
    if (dll->tail == NULL) {
        dll_node_t* headtail = dll_new_node(x);
        dll->head = headtail;
        dll->tail = headtail;
        dll->len++;

        return headtail;
    }
    
    dll_node_t* new_node = dll_new_node(x);

    new_node->prev = dll->tail; // Make previous node the tail
    dll->tail->next = new_node; // Make the tail point to our new node
    dll->tail = new_node;       // Assign the new node as tail
    dll->len++;

    return new_node;
}

dll_node_t* dll_append_node(dll_t* dll, dll_node_t* node) {
    // Empty list
    if (dll->tail == NULL) {
        dll->head = node;
        dll->tail = node;
    }
    else {
        node->prev = dll->tail; // Make previous node the tail
        dll->tail->next = node; // Make the tail point to our new node
        dll->tail = node;       // Assign the new node as tail
    }
    dll->len++;

    return node;
}

dll_node_t* dll_insert(dll_t* dll, int pos, int x) {
    // Index is out of bounds
    if (dll->len < pos)
        return NULL;
    
    dll_node_t* new_node = NULL;
    // Insert at the beginning
    if (pos == 0) {
        new_node = dll_new_node(x);

        new_node->next = dll->head;
        dll->head->prev = new_node;
        dll->head = new_node;

        dll->len++;
    }
    // Insert at the end
    else if (pos == dll->len) {
        new_node = dll_append(dll, x); 
    }
    // Insert somewhere in the middle
    else {
        dll_node_t* current = dll_get(dll, pos - 1);
        new_node = dll_new_node(x);

        new_node->next = current->next;
        current->next = new_node;
        new_node->prev = current;
        new_node->next->prev = new_node;

        dll->len++;
    }

    return new_node;
}

dll_node_t* dll_insert_node(dll_t* dll, int pos, dll_node_t* node) {
    // Index is out of bounds
    if (dll->len < pos)
        return NULL;
    
    dll_node_t* new_node = NULL;
    // Insert at the beginning
    if (pos == 0) {
        node->next = dll->head;
        dll->head->prev = node;
        dll->head = node;

        dll->len++;

        new_node = node;
    }
    // Insert at the end
    else if (pos == dll->len) {
        new_node = dll_append_node(dll, node); 
    }
    // Insert somewhere in the middle
    else {
        dll_node_t* current = dll_get(dll, pos - 1);

        node->next = current->next;
        current->next = node;
        node->prev = current;
        node->next->prev = new_node;

        dll->len++;

        new_node = node;
    }

    return new_node;
}

dll_node_t* dll_pop_last(dll_t* dll) {
    // Attemptying to pop empty list
    if (dll->tail == NULL)
        return NULL;

    dll_node_t* popped = dll->tail;
    // There exists a previous node
    if (popped->prev) {
        dll->tail = popped->prev; // Move tail to previous node
        // Completely detach old tail
        popped->prev->next = NULL;
        popped->prev = NULL;
    }
    // If previous was empty, it means head = tail
    else {
        // Detach node from list
        dll->head = NULL;
        dll->tail = NULL;
    }
    dll->len--;

    return popped;
}

dll_node_t* dll_pop(dll_t* dll, int pos) {
    // Index out of bounds
    if (dll->len - 1 < pos)
        return NULL;

    int count = 0;
    dll_node_t* current = dll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }
    
    dll_node_t* next = current->next;
    dll_node_t* prev = current->prev;
    // Trying to pop the head
    if (dll->head == current)
        dll->head = next; // Update head to be the next node
    
    // Trying to pop the tail
    if (dll->tail == current)
        dll->tail = prev; // Update tail to be the previous node

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
    dll->len--;

    return current;
}

void dll_delete(dll_t* dll, int pos) {
    // Index out of bounds
    if (dll->len - 1 < pos)
        return;

    int count = 0;
    dll_node_t* current = dll->head;
    while (count < pos) {
        current = current->next;
        count++;
    }
    
    dll_node_t* next = current->next;
    dll_node_t* prev = current->prev;
    // Trying to delete the head
    if (dll->head == current)
        dll->head = next; // Update head to be the next node
    
    // Trying to delete the tail
    if (dll->tail == current)
        dll->tail = prev; // Update tail to be the previous node

    // The above statements would still produce a vaid list
    // even when next and/or prev are NULL

    // There exists a previous node (current is not head)
    if (prev != NULL)
        prev->next = next; // Connect previous to next
    
    // There exists a next node (current is not tail)
    if (next != NULL)
        next->prev = prev; // Connect next to previous
    
    dll->len--;
    free(current);
}

void dll_destroy(dll_t* dll) {
    dll_node_t* current = dll->head;

    while (current) {
        dll_node_t* next = current->next;
        free(current);
        current = next;
    }

    dll->len = 0;
    dll->head = NULL;
    dll->tail = NULL;
}

#endif
