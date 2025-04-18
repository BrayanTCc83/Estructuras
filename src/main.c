#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"
#include "headers/static_sorted_list.h"

int main() {
    StaticSortedList *sortedlList = new_static_sorted_list(10, ASCENDING);

    static_sorted_list_insert(sortedlList, 5);
    static_sorted_list_insert(sortedlList, 4);
    static_sorted_list_insert(sortedlList, 2);
    static_sorted_list_insert(sortedlList, 10);
    
    printf("El dato 2, esta en: %d\n", static_sorted_list_get_index(*sortedlList, 2));
    printf("El dato 1, esta en: %d\n", static_sorted_list_get_index(*sortedlList, 1));
    printf("El dato 3, esta en: %d\n", static_sorted_list_get_index(*sortedlList, 3));
    
    static_sorted_list_remove(sortedlList, 10);
    static_sorted_list_reverse(sortedlList);

    delete_static_sorted_list(sortedlList);
    sortedlList = NULL;
    return EXIT_SUCCESS;
}