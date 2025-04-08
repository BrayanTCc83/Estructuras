#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_stack.h"

StaticStack *new_static_stack(size_t capacity) {
    StaticStack *stack = (StaticStack*) malloc( sizeof(StaticStack) );
    if(!stack) {
        printf("Error al reservar memoria para la pila estatica.\n");
        exit(EXIT_FAILURE);
    }

    stack->array = (int*) malloc( capacity * sizeof(int) );
    if(!stack->array) {
        printf("Error al reservar memoria para el arreglo de la pila estatica.");
        exit(EXIT_FAILURE);
    }

    stack->capacity = capacity;
    stack->size = 0;
}

bool static_stack_push(StaticStack *stack, int value) {
    if(static_stack_is_full(*stack)) {
        return false;
    }

    stack->array[stack->size] = value;
    stack->size++;

    #ifdef DEV
    printf("Stack[%p]:", stack);
    for(int i = 0; i < stack->size; i++) {
        printf(" %d", stack->array[i]);
    }
    printf("\n");
    #endif

    return true;
}

int static_stack_pop(StaticStack *stack) {
    if(static_stack_is_void(*stack)) {
        return ERROR_VALUE;
    }

    stack->size--;
    int value = stack->array[stack->size];

    #ifdef DEV
    printf("Stack[%p]:", stack);
    for(int i = 0; i < stack->size; i++) {
        printf(" %d", stack->array[i]);
    }
    printf("\n");
    #endif

    return value;
}

bool static_stack_is_void(StaticStack stack) {
    return stack.size == 0;
}

bool static_stack_is_full(StaticStack stack) {
    return stack.size == stack.capacity;
}

void delete_static_stack(StaticStack *stack) {
    if(stack->size != 0) {
        for(int i = 0; i < stack->size; i++) {
            stack->array[i] = 0;
        }
    }
    free(stack->array);
    stack->capacity = 0;
    stack->size = 0;
    free(stack);
}