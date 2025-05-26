#ifndef _DATA_STRUCTS_STACK
#define _DATA_STRUCTS_STACK

#include <stdbool.h>
#include "simple_node.h"

typedef struct _stack {
    SimpleNode *top;
    size_t size;
} Stack;

Stack *new_stack();
void stack_print(Stack*);
void stack_push(Stack*, int);
int stack_pop(Stack*);
bool stack_is_void(const Stack);
void delete_stack(Stack*);

#endif // _DATA_STRUCTS_STACK