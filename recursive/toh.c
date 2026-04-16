#include "stack.h"
#include "common.h"

void move(stack_t *start, stack_t *goal);
void toh(int n, stack_t *start, stack_t *goal, stack_t *temp);
void print_peg(stack_t *p);
void print_pegs(stack_t *start, stack_t *goal, stack_t *temp);
void print_steps(stack_t *start, stack_t *goal, stack_t *temp);

void move(stack_t *start, stack_t *goal) {
    int el = pop_stack(start);
    push_stack(goal, el);
}

void toh(int n, stack_t *start, stack_t *goal, stack_t *temp) {
    if (n == 0) return;
    toh(n - 1, start, temp, goal);
    move(start, goal);
    print_steps(start, goal, temp);
    toh(n - 1, temp, goal, start);
}

void print_peg(stack_t *p) {
    printf("|");
    for (int i = 0; i < p->len; i++) {
        printf("%c", (char)p->mem[i]);
    }
    printf("--\n");
}

void print_pegs(stack_t *start, stack_t *goal, stack_t *temp) {
    printf("start ");
    print_peg(start);
    printf("temp  ");
    print_peg(temp);
    printf("goal  ");
    print_peg(goal);
}

void print_steps(stack_t *start, stack_t *goal, stack_t *temp) {
    static int moves = 0;
    moves++;

    printf("Move #%d\n", moves);
    print_pegs(start, goal, temp);
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }

    size_t len = argc - 1;
    int* arr = (int*) malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = argv[i + 1][0];
    }

    stack_t start, goal, temp;
    const size_t PEG_CAP = 5;
    init_stack(&start, PEG_CAP);
    init_stack(&goal, PEG_CAP);
    init_stack(&temp, PEG_CAP);

    for (int i = len - 1; i >= 0; i--) {
        push_stack(&start, arr[i]);
    }

    printf("START:\n");
    print_pegs(&start, &goal, &temp);
    printf("\n");
    toh(len, &start, &goal, &temp);

    discard_stack(&start);
    discard_stack(&goal);
    discard_stack(&temp);
    return 0;
}
