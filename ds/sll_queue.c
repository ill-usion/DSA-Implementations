#include <stdio.h>
#include "sll_queue.h"
#include "../include/common.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s x1 x2 x3 ... xn\n", argv[0]);
        return 1;
    }
    
    int* arr = parse_numbers(argc, argv);
    size_t len = argc - 1;

    sll_queue_t sllq;
    sllq_init(&sllq);

    printf("Adding numbers to queue:\n");
    sllq_print(&sllq);
    for (int i = 0; i < len; i++) {
        sllq_enqueue(&sllq, arr[i]);
        sllq_print(&sllq);
    }

    printf("\nRemoving numbers from queue:\n");
    sllq_print(&sllq);
    int val;
    for (int i = 0; i < len; i++) {
        val = sllq_dequeue_val(&sllq);
        printf("Dequeued value: %d\n", val);
        sllq_print(&sllq);
    }

    sllq_destroy(&sllq);
    free(arr);
    return 0;
}
