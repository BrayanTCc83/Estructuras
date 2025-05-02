#ifndef _DATA_STRUCTS_BIT_SET
#define _DATA_STRUCTS_BIT_SET

#include <stdbool.h>

typedef struct _bit_set {
    unsigned char *array;
    size_t capacity, size;
    long long min, max;
} BitSet;

BitSet *new_bit_set(long long, long long);
bool bit_set_insert(BitSet*, long long);
bool bit_set_remove(BitSet*, long long);
bool bit_set_contains(BitSet, long long);
BitSet *bit_set_complement(BitSet*);
BitSet *bit_set_union(BitSet, BitSet);
BitSet *bit_set_intersection(BitSet, BitSet);
BitSet *bit_set_difference(BitSet, BitSet);
BitSet *bit_set_simetric_difference(BitSet, BitSet);
void delete_bit_set(BitSet*);

#endif // _DATA_STRUCTS_BIT_SET