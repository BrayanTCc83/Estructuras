#ifndef _DATA_STRUCTS_STATIC_SORTED_LIST
#define _DATA_STRUCTS_STATIC_SORTED_LIST

#include <stdlib.h>
#include <stdbool.h>
#define ERROR_VALUE INT_MIN

typedef enum _sort_mode {
    ASCENDING = 1,
    DESCENDING = -1
} SortMode;

typedef bool (*SortFunction)(int, int);

typedef struct _static_sorted_list {
    int *array;
    size_t capacity, size;
    SortMode mode;
} StaticSortedList;

StaticSortedList *new_static_sorted_list(size_t, SortMode);
bool static_sorted_list_insert(StaticSortedList*, int);
int static_sorted_list_remove(StaticSortedList*, int);
int static_sorted_list_remove_all(StaticSortedList*, int);
int static_sorted_list_get(StaticSortedList, size_t);
int static_sorted_list_get_index(StaticSortedList, int);
size_t static_sorted_list_count(StaticSortedList, int);
void static_sorted_list_reverse(StaticSortedList*);
bool static_sorted_list_is_void(StaticSortedList);
bool static_sorted_list_is_full(StaticSortedList);
void delete_static_sorted_list(StaticSortedList*);

#endif // _DATA_STRUCTS_STATIC_SORTED_LIST