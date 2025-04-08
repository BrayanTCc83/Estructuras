#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"

int main() {
    /*StaticStack *sstack = new_static_stack(10);
    printf("Stack en %p\n", sstack);

    static_stack_push(sstack, 10);
    static_stack_push(sstack, 15);

    int result;
    while(result != ERROR_VALUE) {
        result = static_stack_pop(sstack);
        printf("Valor pop: %d\n", result);
    }
    printf("Stack vacio.\n");

    delete_static_stack(sstack);
    sstack = NULL;
    printf("Fin del programa\n");*/
    StaticQueue *squeue = new_static_queue(10);
    for(int i = 1; i <= 10; i++) {
        static_queue_enqueue(squeue, i * 2);
    }
    printf("Cola llena\n");

    int result = static_queue_dequeue(squeue);
    while(result != ERROR_VALUE) {
        //printf("Valor deseconlado: %d\n", result);
        result = static_queue_dequeue(squeue);
    }
    printf("La Queue esta vacia.\n");

    delete_static_queue(squeue);
    squeue = NULL;

    return EXIT_SUCCESS;
}