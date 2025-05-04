#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/bit_set.h"

static void bit_set_print(BitSet *set) {
    printf("BitSet[%p]: { ");
    for(int i = 0; i < set->capacity; i++) {
        if(set->array[i]) {
            unsigned char x = set->array[i];
            char j = 0;
            while(j < 8) {
                if(x & 1) {
                    printf("%d ", (j + i * 8) - set->max + 1);
                }
                j++;
                x >>= 1;
            }
        }
    }
    printf("}\n");
}

BitSet *new_bit_set(long long min, long long max) {
    BitSet *set = (BitSet*) malloc( sizeof(BitSet) );
    if(!set) {
        printf("Error al reservar memoria para el conjunto de bits.\n");
        exit(EXIT_FAILURE);
    }

    set->capacity = ceil((max - min + 1) / 8.0);
    set->array = (unsigned char*) calloc( set->capacity, sizeof(char) );
    if(!set->array) {
        printf("Error al reservar memoria para el arreglo del conjunto de bits.\n");
        exit(EXIT_FAILURE);
    }
    set->max = max;
    set->min = min;
    set->size = 0;

    return set;
}

bool bit_set_insert(BitSet *set, long long value) {
    if(set->min > value) {
        return false;
    }
    if(set->max < value) {
        return false;
    }

    unsigned char old;
    unsigned char x = value - set->min + 1; // 31 - (-31) + 1 = 63
    int index = x / 8; // 7

    old = set->array[index];
    set->array[index] |= (unsigned char) pow(2, x % 8 - 1); // 64
    
    if(old == set->array[index]) {
        return false;
    }

    #ifdef DEV
    bit_set_print(set);
    #endif

    set->size++;
    return true;
}

bool bit_set_remove(BitSet *set, long long value) {
    if(set->min > value) {
        return false;
    }
    if(set->max < value) {
        return false;
    }

    unsigned char old;
    unsigned char x = value - set->min + 1; // 31 - (-31) + 1 = 63
    int index = x / 8; // 7

    old = set->array[index];
    set->array[index] &= ~ (unsigned char) pow(2, x % 8 - 1); // ~ 01000000 = 10111111
    
    if(old == set->array[index]) {
        return false;
    }

    #ifdef DEV
    bit_set_print(set);
    #endif

    set->size--;
    return true;
}

bool bit_set_contains(BitSet set, long long value) {
    if(set.min > value) {
        return false;
    }
    if(set.max < value) {
        return false;
    }

    unsigned char old;
    unsigned char x = value - set.min + 1; // 31 - (-31) + 1 = 63
    int index = x / 8; // 7

    return set.array[index] &= (unsigned char) pow(2, x % 8 - 1); // 64
}

BitSet *bit_set_complement(BitSet *set) {
    BitSet *complement = new_bit_set(set->min, set->max);

    for(int i = 0; i < set->capacity; i++) {
        complement->array[i] = ~ set->array[i];
    }

    #ifdef DEV
    bit_set_print(complement);
    #endif

    return complement;
}

BitSet *bit_set_union(BitSet set1, BitSet set2) {
    if(set1.min != set2.min || set1.max != set2.max) {
        return NULL;
    }

    BitSet *unionset = new_bit_set(set1.min, set1.max);
    for(int i = 0; i < set1.capacity; i++) {
        unionset->array[i] = set1.array[i] | set2.array[i];
    }

    #ifdef DEV
    bit_set_print(unionset);
    #endif

    return unionset;
}

BitSet *bit_set_intersection(BitSet set1, BitSet set2) {
    if(set1.min != set2.min || set1.max != set2.max) {
        return NULL;
    }

    BitSet *intersection = new_bit_set(set1.min, set1.max);
    for(int i = 0; i < set1.capacity; i++) {
        intersection->array[i] = set1.array[i] & set2.array[i];
    }

    #ifdef DEV
    bit_set_print(intersection);
    #endif

    return intersection;
}

BitSet *bit_set_difference(BitSet set1, BitSet set2) {
    if(set1.min != set2.min || set1.max != set2.max) {
        return NULL;
    }

    BitSet *difference = new_bit_set(set1.min, set1.max);
    for(int i = 0; i < set1.capacity; i++) {
        difference->array[i] = set1.array[i] & ~ set2.array[i];
    }

    #ifdef DEV
    bit_set_print(difference);
    #endif

    return difference;
}

BitSet *bit_set_simetric_difference(BitSet set1, BitSet set2) {
    if(set1.min != set2.min || set1.max != set2.max) {
        return NULL;
    }

    BitSet *simetric = new_bit_set(set1.min, set1.max);
    for(int i = 0; i < set1.capacity; i++) {
        simetric->array[i] = set1.array[i] ^ set2.array[i];
    }

    #ifdef DEV
    bit_set_print(simetric);
    #endif

    return simetric;
}

void delete_bit_set(BitSet *set) {
    for(int i = 0; i < set->capacity; i++) {
        set->array[i] = 0;
    }
    free(set->array);
    set->array = NULL;
    set->max = 0;
    set->min = 0;
    set->size = 0;
    free(set);
}