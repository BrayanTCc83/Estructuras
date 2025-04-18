#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"

int main() {
    StaticList *list = new_static_list(10);
    static_list_push(list, 10);
    static_list_push(list, 9);
    static_list_shift(list, 8);
    static_list_shift(list, 7);
    static_list_push(list, 10);
    static_list_push(list, 10);

    int result = static_list_unshift(list);
    printf("Value: %d\n", result);
    result = static_list_pull(list);
    printf("Value: %d\n", result);
    
    printf("Index of 10: %d\n", static_list_get_last_index(*list, 10));
    printf("Index of 3: %d\n", static_list_get_last_index(*list, 3));
    printf("Index of 10: %d\n", static_list_get_first_index(*list, 10));
    printf("Index of 3: %d\n", static_list_get_first_index(*list, 3));
    
    static_list_insert_after(list, 5, 9);
    static_list_insert_before(list, 5, 9);
    static_list_remove_first(list, 10);
    static_list_remove_last(list, 10);
    static_list_shift(list, 8);
    static_list_shift(list, 8);
    static_list_shift(list, 8);
    printf("Se eliminaron %d valores.\n", static_list_remove_all(list, 5));
    printf("Hay %d repeticiones del numero 8.\n", static_list_count(*list, 8));

    delete_static_list(list);
    list = NULL;
    
    return EXIT_SUCCESS;
}