#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_queue.h"

StaticQueue *new_static_queue(size_t capacity) {
    StaticQueue *queue = (StaticQueue*) malloc( sizeof(StaticQueue) );
    if(!queue) {
        printf("Error al reservar memoria para la cola estatica.\n");
        exit(EXIT_FAILURE);
    }

    queue->array = (int*) malloc( capacity * sizeof(int) );
    if(!queue->array) {
        printf("Error al reservar memoria para el arreglo de la cola estatica.");
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->size = 0;
}

// O(1)
/*bool static_queue_enqueue(StaticQueue *queue, int value) {
    if(static_queue_is_full(*queue)) {
        return false;
    }

    queue->array[queue->size] = value;
    queue->size++;

    #ifdef DEV
    printf("Queue[%p]:", queue);
    for(int i = 0; i < queue->size; i++) {
        printf(" %d", queue->array[i]);
    }
    printf("\n");
    #endif

    return true;
}

// O(n)
int static_queue_dequeue(StaticQueue *queue) {
    if(static_queue_is_void(*queue)) {
        return ERROR_VALUE;
    }

    int value = queue->array[0];
    --queue->size;
    for(int i = 0; i < queue->size; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    queue->array[queue->size] = 0;

    #ifdef DEV
    printf("Queue[%p]:", queue);
    for(int i = 0; i < queue->size; i++) {
        printf(" %d", queue->array[i]);
    }
    printf("\n");
    #endif

    return value;
}*/

// O(n)
bool static_queue_enqueue(StaticQueue *queue, int value) {
    if(static_queue_is_full(*queue)) {
        return false;
    }

    for(int i = queue->size; i >= 0; i--) {
        queue->array[i + 1] = queue->array[i];
    }

    queue->array[0] = value;
    queue->size++;

    #ifdef DEV
    printf("Queue[%p]:", queue);
    for(int i = 0; i < queue->size; i++) {
        printf(" %d", queue->array[i]);
    }
    printf("\n");
    #endif

    return true;
}

// O(1)
int static_queue_dequeue(StaticQueue *queue) {
    if(static_queue_is_void(*queue)) {
        return ERROR_VALUE;
    }

    int value = queue->array[--queue->size];
    queue->array[queue->size] = 0;

    #ifdef DEV
    printf("Queue[%p]:", queue);
    for(int i = 0; i < queue->size; i++) {
        printf(" %d", queue->array[i]);
    }
    printf("\n");
    #endif

    return value;
}

bool static_queue_is_void(StaticQueue queue) {
    return queue.size == 0;
}

bool static_queue_is_full(StaticQueue queue) {
    return queue.size == queue.capacity;
}

void delete_static_queue(StaticQueue *queue) {
    if(queue->size != 0) {
        for(int i = 0; i < queue->size; i++) {
            queue->array[i] = 0;
        }
    }
    free(queue->array);
    queue->capacity = 0;
    queue->size = 0;
    free(queue);
}