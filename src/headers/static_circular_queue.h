#ifndef _DATA_STRUCTS_STATIC_CIRCULAR_QUEUE
#define _DATA_STRUCTS_STATIC_CIRCULAR_QUEUE

#include <stdlib.h>
#include <stdbool.h>
#define ERROR_VALUE INT_MIN

typedef struct _static_circular_queue {
    int *array;
    size_t capacity, size;
    size_t begin, end;
} StaticCircularQueue;

StaticCircularQueue *new_static_circular_queue(size_t);
bool static_circular_queue_enqueue(StaticCircularQueue*, int);
int static_circular_queue_dequeue(StaticCircularQueue*);
bool static_circular_queue_is_void(StaticCircularQueue);
bool static_circular_queue_is_full(StaticCircularQueue);
void delete_static_circular_queue(StaticCircularQueue*);

#endif // _DATA_STRUCTS_STATIC_CIRCULAR_QUEUE