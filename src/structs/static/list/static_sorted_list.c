#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_sorted_list.h"

static void static_sorted_list_print(StaticSortedList *list) {
    printf("Sorted List[%p]:", list);
    for(int i = 0; i < list->size; i++) {
        printf(" %d", list->array[i]);
    }
    printf("\n");
}

StaticSortedList *new_static_sorted_list(size_t capacity, SortMode mode) {
    StaticSortedList *list = (StaticSortedList*) malloc( sizeof(StaticSortedList) );
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
    list->mode = mode;

    return list;
}

bool static_sorted_list_is_void(StaticSortedList list) {
    return !list.size;
}

bool static_sorted_list_is_full(StaticSortedList list) {
    return list.size == list.capacity;
}

void delete_static_sorted_list(StaticSortedList *list) {
    for(int i = 0; i < list->size; i++) {
        list->array[i] = 0;
    }
    free(list->array);
    list->array = NULL;
    list->capacity = 0;
    list->size = 0;
    list->mode = 0;
    free(list);
}

int static_sorted_list_get(StaticSortedList list, size_t index) {
    if(index < 0) {
        return ERROR_VALUE;
    }
    return list.array[index];
}

static bool sort_ascending(int a, int b) {
    return a > b;
}

static bool sort_descending(int a, int b) {
    return a < b;
}

int static_sorted_list_get_index(StaticSortedList list, int value) {
    if(static_sorted_list_is_void(list)) {
        return -1;
    }

    SortFunction sort = list.mode == ASCENDING ? sort_ascending : sort_descending;
    int index = -1;
    for(int i = 0; i < list.size; i++) {
        if(!sort(value, list.array[i])) {
            return list.array[i] == value ? i : index;
        }
    }

    return index;
}

size_t static_sorted_list_count(StaticSortedList list, int value) {
    if(static_sorted_list_is_void(list)) {
        return 0;
    }

    int count = 0;
    for(int i = 0; i < list.size; i++) {
        if(list.array[i] == value) {
            count++;
        }
    }

    return count;
}

bool static_sorted_list_insert(StaticSortedList *list, int value) {
    if(static_sorted_list_is_full(*list)) {
        return false;
    }

    SortFunction sort = list->mode == ASCENDING ? sort_ascending : sort_descending;
    int i = 0;
    for(; i < list->size; i++) {
        if(!sort(value, list->array[i])) {
            break;
        }
    }

    for(int j = list->size; j > i; j--) {
        list->array[j] = list->array[j - 1];
    }
    list->array[i] = value;
    list->size++;
    
    #ifdef DEV
    static_sorted_list_print(list);
    #endif

    return true;
}

int static_sorted_list_remove(StaticSortedList *list, int value) {
    if(static_sorted_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int index = static_sorted_list_get_index(*list, value);
    if(index == -1) {
        return ERROR_VALUE;
    }

    int result = list->array[index];
    list->size--;
    for(int i = index; i < list->size; i--) {
        list->array[i] = list->array[i + 1];
    }
    list->array[list->size] = 0;
    
    #ifdef DEV
    static_sorted_list_print(list);
    #endif

    return result;
}

int static_sorted_list_remove_all(StaticSortedList *list, int value) {
    if(static_sorted_list_is_void(*list)) {
        return 0;
    }

    int count = 0;
    while(static_sorted_list_remove(list, value) != ERROR_VALUE) {
        count++;
    }
    return count;
}

void static_sorted_list_reverse(StaticSortedList *list) {
    list->mode = list->mode == ASCENDING ? DESCENDING : ASCENDING;

    int tmp = 0;
    for(int i = 0, j = list->size - 1; i < j ; i++, j--) {
        tmp = list->array[i];
        list->array[i] = list->array[j];
        list->array[j] = tmp;
    }

    #ifdef DEV
    static_sorted_list_print(list);
    #endif
}