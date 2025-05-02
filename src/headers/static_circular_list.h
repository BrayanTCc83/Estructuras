#ifndef _DATA_STRUCTS_STATIC_CIRCULAR_LIST
#define _DATA_STRUCTS_STATIC_CIRCULAR_LIST

#include <stdlib.h>
#include <stdbool.h>
#include "static_sorted_list.h"

typedef struct _static_circular_list {
    int *array;
    size_t capacity, size;
    SortMode mode;
    size_t begin, end;
} StaticCircularList;

StaticCircularList *new_static_circular_list(size_t, SortMode);
bool static_circular_list_insert(StaticCircularList*, int);
int static_circular_list_remove(StaticCircularList*, int);
int static_circular_list_remove_all(StaticCircularList*, int);
int static_circular_list_get(StaticCircularList, size_t);
int static_circular_list_get_index(StaticCircularList, int);
size_t static_circular_list_count(StaticCircularList, int);
bool static_circular_list_is_void(StaticCircularList);
bool static_circular_list_is_full(StaticCircularList);
void delete_static_circular_list(StaticCircularList*);

#endif // _DATA_STRUCTS_STATIC_CIRCULAR_LIST