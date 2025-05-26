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
#include "headers/queue.h"

int main() {
    Queue *queue = new_queue();

    for(int i = 1; i <= 10; i++) {
        queue_enqueue(queue, i * 10);
    }

    while(!queue_is_void(*queue)) {
        printf("Dequeue: %d\n", queue_dequeue(queue));
    }

    delete_queue(queue);

    return EXIT_SUCCESS;
}