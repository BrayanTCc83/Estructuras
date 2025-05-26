#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../headers/simple_node.h"
#include "../../../headers/queue.h"

void queue_print(Queue *queue) {
    SimpleNode *aux = queue->head;
    printf("Queue[%p] = {\n", queue);
    while(aux) {
        printf("\t");
        simple_node_print(aux);
        aux = aux->next;
    }
    printf("}\n");
}

Queue *new_queue() {
    Queue *queue = (Queue*) malloc( sizeof(Queue) );

    if(!queue) {
        printf("Error al reservar memoria para la cola.\n");
        exit(EXIT_FAILURE);
    }
    
    queue->head = queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_enqueue(Queue *queue, int value) {
    SimpleNode *node = new_simple_node(value, NULL);
    if(!queue->head) {
        queue->head = queue->tail = node;
    } else {
        simple_node_set_next(queue->tail, node);
        queue->tail = node;
    }
    queue->size++;
    #ifdef DEV
    queue_print(queue);
    #endif
}

int queue_dequeue(Queue *queue) {
    if(queue_is_void(*queue)) {
        return INT_MIN;
    }

    SimpleNode *head = queue->head;
    int x = head->value;

    queue->head = head->next;
    delete_simple_node(head);

    queue->size--;
    #ifdef DEV
    queue_print(queue);
    #endif

    return x;
}

bool queue_is_void(const Queue queue) {
    return queue.size == 0;
}

void delete_queue(Queue *queue) {
    SimpleNode *aux = queue->head, *next = NULL;
    while(aux) {
        next = aux->next;
        delete_simple_node(aux);
        aux = next;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    free(queue);
}
