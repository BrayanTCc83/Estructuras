#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/static_list.h"

static void static_list_print(StaticList *list) {
    printf("List[%p]:", list);
    for(int i = 0; i < list->size; i++) {
        printf(" %d", list->array[i]);
    }
    printf("\n");
}

StaticList *new_static_list(size_t capacity) {
    StaticList *list = (StaticList*) malloc( sizeof(StaticList) );
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

    return list;
}

bool static_list_is_void(StaticList list) {
    return !list.size;
}

bool static_list_is_full(StaticList list) {
    return list.size == list.capacity;
}

void delete_static_list(StaticList *list) {
    for(int i = 0; i < list->size; i++) {
        list->array[i] = 0;
    }
    free(list->array);
    list->array = NULL;
    list->capacity = 0;
    list->size = 0;
    free(list);
}

bool static_list_push(StaticList *list, int value) {
    if(static_list_is_full(*list)) {
        return false;
    }

    list->array[list->size] = value;
    list->size++;

    #ifdef DEV
    static_list_print(list);
    #endif

    return true;
}

bool static_list_shift(StaticList *list, int value) {
    if(static_list_is_full(*list)) {
        return false;
    }

    for(int i = list->size; i >= 0; i--) {
        list->array[i + 1] = list->array[i];
    }

    list->array[0] = value;
    list->size++;

    #ifdef DEV
    static_list_print(list);
    #endif

    return true;
}

int static_list_pull(StaticList *list) {
    if(static_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    list->size--;
    int value = list->array[list->size];

    #ifdef DEV
    static_list_print(list);
    #endif

    return value;
}

int static_list_unshift(StaticList *list) {
    if(static_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int value = list->array[0];
    --list->size;
    for(int i = 0; i < list->size; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->array[list->size] = 0;

    #ifdef DEV
    static_list_print(list);
    #endif

    return value;
}

bool static_list_insert_after(StaticList *list, int value, int reference) {
    if(static_list_is_full(*list)) {
        return false;
    }

    int index = static_list_get_last_index(*list, reference);
    if(index == -1) {
        return false;
    }

    for(int i = index + 2; i < list->size; i++) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index + 1] = value;
    list->size++;

    #ifdef DEV
    static_list_print(list);
    #endif

    return true;
}

bool static_list_insert_before(StaticList *list, int value, int reference) {
    if(static_list_is_full(*list)) {
        return false;
    }

    int index = static_list_get_first_index(*list, reference);
    if(index == -1) {
        return false;
    }

    for(int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[ index > 0 ? index : 0 ] = value;
    list->size++;

    #ifdef DEV
    static_list_print(list);
    #endif

    return true;
}

int static_list_remove_first(StaticList *list, int value) {
    if(static_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int index = static_list_get_first_index(*list, value);
    if(index == -1) {
        return ERROR_VALUE;
    }

    int result = list->array[index];
    list->size--;
    for(int i = index; i < list->size; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->array[list->size] = 0;

    #ifdef DEV
    static_list_print(list);
    #endif

    return result;
}

int static_list_remove_last(StaticList *list, int value) {
    if(static_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int index = static_list_get_last_index(*list, value);
    if(index == -1) {
        return ERROR_VALUE;
    }

    int result = list->array[index];
    list->size--;
    for(int i = index; i < list->size; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->array[list->size] = 0;

    #ifdef DEV
    static_list_print(list);
    #endif

    return result;
}

int static_list_remove_all(StaticList *list, int value) {
    if(static_list_is_void(*list)) {
        return ERROR_VALUE;
    }

    int count = 0;
    while(static_list_remove_first(list, value) != ERROR_VALUE) {
        count++;
    }
    return count;
}

int static_list_get(StaticList list, size_t index) {
    if(index < 0) {
        return ERROR_VALUE;
    }
    return list.array[index];
}

int static_list_get_first_index(StaticList list, int value) {
    if(static_list_is_void(list)) {
        return -1;
    }

    int index = -1;
    for(int i = 0; i < list.size; i++) {
        if(list.array[i] == value) {
            index = i;
            break;
        }
    }

    return index;
}

int static_list_get_last_index(StaticList list, int value) {
    if(static_list_is_void(list)) {
        return -1;
    }

    int index = -1;
    for(int i = list.size - 1; i >= 0; i--) {
        if(list.array[i] == value) {
            index = i;
            break;
        }
    }

    return index;
}

size_t static_list_count(StaticList list, int value) {
    if(static_list_is_void(list)) {
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