#include <stdlib.h>
#include <assert.h>

static const size_t REALLOC_SIZE = 8;

typedef struct {
    int* mem;
    int* top;
    size_t len;
    size_t cap;
} stack_t;

void init_stack(stack_t *s, size_t cap) {
    s->mem = (int*) malloc(sizeof(int) * cap);
    s->top = NULL;
    s->len = 0;
    s->cap = cap;
}

void realloc_stack(stack_t *s, size_t cap) {
    s->mem = (int*) realloc(s->mem, cap * sizeof(int));
    s->cap = cap;
}

void push_stack(stack_t *s, int el) {
    if (s->len + 1 >= s->cap)
        realloc_stack(s, s->cap + REALLOC_SIZE);

    s->mem[s->len++] = el;
    s->top = s->mem + s->len - 1;
}

int pop_stack(stack_t *s) {
    assert(s->len > 0 && "Attempt to call pop with an empty stack");

    int el = s->mem[--s->len];
    s->top = s->mem + s->len - 1;

    return el;
}

void discard_stack(stack_t *s) {
    free(s->mem);
    s->len = 0;
    s->cap = 0;
    s->top = NULL;
}
