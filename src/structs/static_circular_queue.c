#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_circular_queue.h"

static void static_sorted_circular_queue_print(StaticCircularQueue *queue) {
    printf("Circular Queue[%p]:", queue);
    if(queue->end > queue->begin) {
        for(int i = queue->begin; i < queue->end; i++) {
            printf("%d ", queue->array[i]);
        }
    } else {
        for(int i = queue->begin; i < queue->capacity; i++) {
            printf("%d ", queue->array[i]);
        }
        for(int i = 0; i < queue->end; i++) {
            printf("%d ", queue->array[i]);
        }
    }
    printf("\n");
}

StaticCircularQueue *new_static_circular_queue(size_t capacity) {
    StaticCircularQueue *queue = (StaticCircularQueue*) malloc( sizeof(StaticCircularQueue) );
    if(!queue) {
        printf("Error al reservar memoria para la cola circular estatica.\n");
        exit(EXIT_FAILURE);
    }

    queue->array = (int*) malloc( capacity * sizeof(int) );
    if(!queue->array) {
        printf("Error al reservar memoria para el arreglo de la cola circular estatica.");
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;

    return queue;
}

bool static_circular_queue_is_void(StaticCircularQueue queue) {
    return queue.size == 0;
}

bool static_circular_queue_is_full(StaticCircularQueue queue) {
    return queue.size == queue.capacity;
}

void delete_static_circular_queue(StaticCircularQueue *queue) {
    for(int i = 0; i < queue->capacity; i++) {
        queue->array[i] = 0;
    }
    free(queue->array);
    queue->capacity = 0;
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;
    free(queue);
}

bool static_circular_queue_enqueue(StaticCircularQueue *queue, int value) {
    if(static_circular_queue_is_full(*queue)) {
        return false;
    }

    if(queue->end >= queue->capacity) {
        queue->end = 0;
    }
    queue->array[queue->end++] = value;
    queue->size++;

    #ifdef DEV
    static_sorted_circular_queue_print(queue);
    #endif

    return true;
}

int static_circular_queue_dequeue(StaticCircularQueue *queue) {
    if(static_circular_queue_is_void(*queue)) {
        return ERROR_VALUE;
    }

    int value = queue->array[queue->begin++];
    if(queue->begin >= queue->capacity) {
        queue->begin = 0;
    }

    queue->size--;

    #ifdef DEV
    static_sorted_circular_queue_print(queue);
    #endif

    return value;
}