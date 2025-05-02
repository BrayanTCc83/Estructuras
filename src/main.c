#include <stdio.h>
#include <stdlib.h>
#include "headers/static_stack.h"
#include "headers/static_queue.h"
#include "headers/static_list.h"
#include "headers/static_sorted_list.h"
#include "headers/static_circular_queue.h"
#include "headers/static_circular_list.h"
#include "headers/bit_set.h"

int main() {
    BitSet *set = new_bit_set(-31, 32);
    BitSet *set2 = new_bit_set(-31, 32);

    bit_set_insert(set, 31);
    bit_set_insert(set, -12);
    bit_set_insert(set, 14);
    bit_set_insert(set, -14);
    bit_set_insert(set, -12);
    bit_set_remove(set, 31);
    
    bit_set_insert(set2, 1);
    bit_set_insert(set2, 9);
    bit_set_insert(set2, -7);
    bit_set_insert(set2, -14);

    BitSet *complement = bit_set_complement(set);
    BitSet *unionset = bit_set_union(*set, *set2);
    BitSet *difference = bit_set_difference(*set, *set2);
    BitSet *difference2 = bit_set_difference(*set2, *set);
    BitSet *simetric = bit_set_simetric_difference(*set2, *set);
    BitSet *intersection = bit_set_intersection(*set2, *set);

    delete_bit_set(set);
    set = NULL;
    return EXIT_SUCCESS;
}