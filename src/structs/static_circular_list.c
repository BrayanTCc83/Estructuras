#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_circular_list.h"

static void static_circular_list_print(StaticCircularList *list) {
    printf("Circular List[%p]:", list);
    if(list->end > list->begin) {
        for(int i = list->begin; i < list->end; i++) {
            printf("%d ", list->array[i]);
        }
    } else {
        for(int i = list->begin; i < list->capacity; i++) {
            printf("%d ", list->array[i]);
        }
        for(int i = 0; i < list->end; i++) {
            printf("%d ", list->array[i]);
        }
    }
    printf("\n");
}

StaticCircularList *new_static_circular_list(size_t capacity, SortMode mode) {
    StaticCircularList *list = (StaticCircularList*) malloc( sizeof(StaticCircularList) );
    if(!list) {
        printf("Error al reservar memoria para la lista estatica.\n");
        exit(EXIT_FAILURE);
    }

    list->array = (int*) malloc( capacity * sizeof(int) );
    if(!list->array) {
        printf("Error al reservar memoria para el arreglo de la lista estatica.");
        exit(EXIT_FAILURE);
    }

    list->capacity = capacity;
    list->size = 0;
    list->begin = 0;
    list->end = 0;
    list->mode = mode;

    return list;
}

bool static_circular_list_is_void(StaticCircularList list) {
    return !list.size;
}

bool static_circular_list_is_full(StaticCircularList list) {
    return list.size == list.capacity;
}

void delete_static_circular_list(StaticCircularList *list) {
    for(int i = 0; i < list->size; i++) {
        list->array[i] = 0;
    }
    free(list->array);
    list->array = NULL;
    list->capacity = 0;
    list->size = 0;
    list->mode = 0;
    list->begin = 0;
    list->end = 0;
    free(list);
}

int static_circular_list_get(StaticCircularList list, size_t index) {
    if(index < 0) {
        return ERROR_VALUE;
    }
    if(index >= list.size) {
        return ERROR_VALUE;
    }
    int x = (index + list.begin) % list.capacity;
    return list.array[x];
}

static bool sort_ascending(int a, int b) {
    return a > b;
}

static bool sort_descending(int a, int b) {
    return a < b;
}

int static_circular_list_remove_all(StaticCircularList *list, int value) {
    if(static_circular_list_is_void(*list)) {
        return 0;
    }

    int count = 0;
    while(static_circular_list_remove(list, value) != ERROR_VALUE) {
        count++;
    }
    return count;
}

int static_circular_list_get_index(StaticCircularList list, int value) {
    if(static_circular_list_is_void(list)) {
        return -1;
    }

    SortFunction sort = list.mode == ASCENDING ? sort_ascending : sort_descending;
    int index = -1;
    if(list.end > list.begin) {
        for(int i = list.begin; i < list.end; i++) {
            if(!sort(value, list.array[i])) {
                return list.array[i] == value ? i - list.begin: index;
            }
        }
    } else {
        for(int i = list.begin; i < list.capacity; i++) {
            if(!sort(value, list.array[i])) {
                return list.array[i] == value ? i - list.begin: index;
            }
        }
        for(int i = 0; i < list.end; i++) {
            if(!sort(value, list.array[i])) {
                return list.array[i] == value ? i + (list.capacity - list.begin) : index;
            }
        }
    }

    return index;
}

size_t static_circular_list_count(StaticCircularList list, int value) {
    if(static_circular_list_is_void(list)) {
        return 0;
    }

    int count = 0;
    if(list.end > list.begin) {
        for(int i = list.begin; i < list.end; i++) {
            if(list.array[i] == value) {
                count++;
            }
        }
    } else {
        for(int i = list.begin; i < list.capacity; i++) {
            if(list.array[i] == value) {
                count++;
            }
        }
        for(int i = 0; i < list.end; i++) {
            if(list.array[i] == value) {
                count++;
            }
        }
    }

    return count;
}

bool static_circular_list_insert(StaticCircularList *list, int value) {
    if(static_circular_list_is_full(*list)) {
        return false;
    }

    if(list->end >= list->capacity) {
        list->end = 0;
    }

    SortFunction sort = list->mode == ASCENDING ? sort_ascending : sort_descending;
    int i = 0;
    if(list->end >= list->begin) {
        for(i = list->begin; i < list->end; i++) {
            if(!sort(value, list->array[i])) {
                break;
            }
        }
    } else {
        for(i = list->begin; i < list->capacity; i++) {
            if(!sort(value, list->array[i])) {
                goto _sorting;
            }
        }
        for(i = 0; i < list->end; i++) {
            if(!sort(value, list->array[i])) {
                goto _sorting;
            }
        }
    }
    
    _sorting:
    int x = (i + list->begin) % list->capacity;
    if(list->end >= list->begin) {
        for(int i = list->end; i > x; i--) {
            list->array[i] = list->array[i - 1];
        }
    } else if(i > list->begin) {
        for(int i = list->end; i > 0; i--) {
            list->array[i] = list->array[i - 1];
        }
        list->array[0] = list->array[list->capacity - 1];
        for(int j = list->capacity - 1; j > i; j--) {
            list->array[j] = list->array[j - 1];
        }
    } else {
        x = x - list->begin;
        for(int i = list->end; i > x; i--) {
            list->array[i] = list->array[i - 1];
        }
    }
    list->array[x] = value;
    list->size++;
    list->end++;
    
    #ifdef DEV
    static_circular_list_print(list);
    #endif

    return true;
}

int static_circular_list_remove(StaticCircularList *list, int value) {
    if(static_circular_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int index = static_circular_list_get_index(*list, value);
    if(index == -1) {
        return ERROR_VALUE;
    }

    if(list->begin >= list->capacity) {
        list->begin = 0;
    }

    int x = (index + list->begin) % list->capacity;
    int result = list->array[x];
    if(list->end >= list->begin) {
        for(int i = x; i > list->begin; i--) {
            list->array[i] = list->array[i - 1];
        }
    } else if(index > list->begin) {
        for(int i = index; i < list->capacity; i--) {
            list->array[i] = list->array[i - 1];
        }
        list->array[0] = list->array[list->capacity - 1];
        for(int i = 0; i < list->end; i--) {
            list->array[i] = list->array[i - 1];
        }
    } else {
        for(int i = x; i < list->end; i--) {
            list->array[i] = list->array[i - 1];
        }
    }
    list->array[list->begin] = 0;
    list->begin++;
    list->size--;
    
    #ifdef DEV
    static_circular_list_print(list);
    #endif

    return result;
}