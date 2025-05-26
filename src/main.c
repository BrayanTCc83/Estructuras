#include <stdio.h>
#include <stdlib.h>
// STATIC STRUCTURES
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"
#include "headers/static_sorted_list.h"
#include "headers/static_circular_queue.h"
#include "headers/static_circular_list.h"
#include "headers/bit_set.h"
// DYNAMIC COMPONENTS
#include "headers/simple_node.h"
// DYNAMIC STRUCTURES
#include "headers/stack.h"

int main() {
    Stack *stack = new_stack();

    for(int i = 1; i <= 10; i++) {
        stack_push(stack, i * 10);
    }

    while(!stack_is_void(*stack)) {
        printf("Popped: %d\n", stack_pop(stack));
    }

    delete_stack(stack);

    return EXIT_SUCCESS;
}