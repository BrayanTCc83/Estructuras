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

int main() {
    SimpleNode *node1 = new_simple_node(10, NULL);
    SimpleNode *node2 = new_simple_node(20, NULL);
    SimpleNode *node3 = new_simple_node(30, NULL);

    simple_node_print(node1);
    simple_node_print(node2);
    simple_node_print(node3);

    simple_node_set_next(node1, node2);
    simple_node_set_next(node2, node3);

    simple_node_print(node1);
    simple_node_print(node2);
    simple_node_print(node3);

    printf("1: %d -> 2: %d -> 3: %d\n", node1->value, node1->next->value, node1->next->next->value);

    delete_simple_node(node1);
    delete_simple_node(node2);
    delete_simple_node(node3);

    node1 = NULL;
    node2 = NULL;
    node3 = NULL;

    return EXIT_SUCCESS;
}