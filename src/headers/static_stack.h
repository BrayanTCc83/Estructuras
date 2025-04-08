#ifndef _DATA_STRUCTS_STATIC_STACK
#define _DATA_STRUCTS_STATIC_STACK

#include <stdlib.h>
#include <stdbool.h>
#define ERROR_VALUE INT_MIN

typedef struct _static_stack {
    int *array;
    size_t capacity, size;
} StaticStack;

StaticStack *new_static_stack(size_t);
bool static_stack_push(StaticStack*, int);
int static_stack_pop(StaticStack*);
bool static_stack_is_void(StaticStack);
bool static_stack_is_full(StaticStack);
void delete_static_stack(StaticStack*);

#endif // _DATA_STRUCTS_STATIC_STACK