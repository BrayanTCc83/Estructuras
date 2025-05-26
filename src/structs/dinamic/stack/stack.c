#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../headers/simple_node.h"
#include "../../../headers/stack.h"

void stack_print(Stack *stack) {
    SimpleNode *aux = stack->top;
    printf("Stack[%p] = {\n", stack);
    while(aux) {
        printf("\t");
        simple_node_print(aux);
        aux = aux->next;
    }
    printf("}\n");
}

Stack *new_stack() {
    Stack *stack = (Stack*) malloc( sizeof(Stack) );

    if(!stack) {
        printf("Error al reservar memoria para la pila.\n");
        exit(EXIT_FAILURE);
    }
    
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void stack_push(Stack *stack, int value) {
    SimpleNode *node = new_simple_node(value, stack->top);
    stack->top = node;
    stack->size++;
    #ifdef DEV
    stack_print(stack);
    #endif
}

int stack_pop(Stack *stack) {
    if(stack_is_void(*stack)) {
        return INT_MIN;
    }

    SimpleNode *top = stack->top;
    int x = top->value;

    stack->top = top->next;
    delete_simple_node(top);

    stack->size--;
    #ifdef DEV
    stack_print(stack);
    #endif

    return x;
}

bool stack_is_void(const Stack stack) {
    return stack.size == 0;
}

void delete_stack(Stack *stack) {
    SimpleNode *aux = stack->top, *next = NULL;
    while(aux) {
        next = aux->next;
        delete_simple_node(aux);
        aux = next;
    }
    stack->top = NULL;
    stack->size = 0;
    free(stack);
}
