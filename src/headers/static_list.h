#ifndef _DATA_STRUCTS_STATIC_LIST
#define _DATA_STRUCTS_STATIC_LIST

#include <stdlib.h>
#include <stdbool.h>
#define ERROR_VALUE INT_MIN

typedef struct _static_list {
    int *array;
    size_t capacity, size;
} StaticList;

StaticList *new_static_list(size_t);
bool static_list_push(StaticList*, int);
bool static_list_shift(StaticList*, int);
bool static_list_insert_after(StaticList*, int, int);
bool static_list_insert_before(StaticList*, int, int);
int static_list_pull(StaticList*);
int static_list_unshift(StaticList*);
int static_list_remove_first(StaticList*, int);
int static_list_remove_last(StaticList*, int);
int static_list_remove_all(StaticList*, int);
int static_list_get(StaticList, size_t);
int static_list_get_first_index(StaticList, int);
int static_list_get_last_index(StaticList, int);
size_t static_list_count(StaticList, int);
bool static_list_is_void(StaticList);
bool static_list_is_full(StaticList);
void delete_static_list(StaticList*);

#endif // _DATA_STRUCTS_STATIC_LIST