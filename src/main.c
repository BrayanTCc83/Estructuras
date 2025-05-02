#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"
#include "headers/static_sorted_list.h"
#include "headers/static_circular_queue.h"

int main() {
    StaticCircularQueue *queue = new_static_circular_queue(10);

    printf("Queue: %d\n", sizeof(StaticQueue));
    printf("Circular Queue: %d\n", sizeof(StaticCircularQueue));
    
    for(int i = 1; i < 11; i++) {
        static_circular_queue_enqueue(queue, i);
    }

    for(int i = 0; i < 5; i++) {
        int res = static_circular_queue_dequeue(queue);
        printf("Dequeue: %d\n", res);
    }
    
    for(int i = 11; i < 16; i++) {
        static_circular_queue_enqueue(queue, i);
    }

    delete_static_circular_queue(queue);
    queue = NULL;
    return EXIT_SUCCESS;
}