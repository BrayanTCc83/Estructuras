#ifndef _DATA_STRUCTS_STATIC_QUEUE
#define _DATA_STRUCTS_STATIC_QUEUE

#include <stdlib.h>
#include <stdbool.h>
#define ERROR_VALUE INT_MIN

typedef struct _static_queue {
    int *array;
    size_t capacity, size;
} StaticQueue;

StaticQueue *new_static_queue(size_t);
bool static_queue_enqueue(StaticQueue*, int);
int static_queue_dequeue(StaticQueue*);
bool static_queue_is_void(StaticQueue);
bool static_queue_is_full(StaticQueue);
void delete_static_queue(StaticQueue*);

#endif // _DATA_STRUCTS_STATIC_QUEUE