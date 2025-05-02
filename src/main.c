#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"
#include "headers/static_sorted_list.h"
#include "headers/static_circular_queue.h"
#include "headers/static_circular_list.h"

int main() {
    StaticCircularList *list = new_static_circular_list(10, ASCENDING);
    printf("Sorted List: %d\n", sizeof(StaticSortedList));
    printf("Circular List: %d\n", sizeof(StaticCircularList));
    
    for(int i = 1; i < 11; i++) {
        static_circular_list_insert(list, i);
    }

    for(int i = 0; i < 5; i++) {
        int res = static_circular_list_remove(list, 10 - i);
        printf("List: %d\n", res);
    }
    
    for(int i = 11; i < 16; i++) {
        static_circular_list_insert(list, i);
    }

    printf("Lista[%d] = %d\n", 3, static_circular_list_get(*list, 3));

    delete_static_circular_list(list);
    list = NULL;
    return EXIT_SUCCESS;
}