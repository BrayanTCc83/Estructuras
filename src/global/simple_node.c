#include <stdio.h>
#include <stdlib.h>
#include "../headers/simple_node.h"

SimpleNode *new_simple_node(int value, SimpleNode *next) {
    SimpleNode *node = (SimpleNode*) malloc( sizeof(SimpleNode) );

    if(!node) {
        printf("Error al reservar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = next;

    return node;
}

void simple_node_print(SimpleNode *node) {
    printf("Node[%p]: { .value: %d, .next: %p }\n", node, node->value, node->next);
}

void simple_node_set_next(SimpleNode *node, SimpleNode *next) {
    node->next = next;
}

void delete_simple_node(SimpleNode *node) {
    node->next = NULL;
    node->value = 0;
    free(node);
}
