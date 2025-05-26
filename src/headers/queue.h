#ifndef _DATA_STRUCTS_QUEUE
#define _DATA_STRUCTS_QUEUE

#include <stdbool.h>
#include "simple_node.h"

typedef struct _queue {
    SimpleNode *head, *tail;
    size_t size;
} Queue;

Queue *new_queue();
void queue_print(Queue*);
void queue_enqueue(Queue*, int);
int queue_dequeue(Queue*);
bool queue_is_void(const Queue);
void delete_queue(Queue*);

#endif // _DATA_STRUCTS_QUEUE