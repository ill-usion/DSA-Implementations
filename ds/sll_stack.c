#include "../include/common.h"
#include "sll_stack.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1, x2, ..., xn\n", argv[0]);
        return 1;
    }
    
    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;
    sll_stack_t slls;
    slls_init(&slls);
    
    printf("Pushing elements into SLL Stack:\n");
    for (int i = 0; i < len; i++) {
        slls_push(&slls, arr[i]);
        slls_print(&slls);
    }

    printf("Popping elements from SLL Stack:\n");
    int val;
    for (int i = 0; i < len; i++) {
        val = slls_pop_val(&slls);
        printf("Popped value: %d\n", val);
        slls_print(&slls);
    }

    slls_destroy(&slls);
    free(arr);
    return 0;
}
