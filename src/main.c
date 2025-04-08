#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"

int main() {
    StaticStack *sstack = new_static_stack(10);
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
    printf("Fin del programa\n");

    return EXIT_SUCCESS;
}