#ifndef ORDERED_ARRAY_H
#define ORDERED_ARRAY_H

#include <system.h>

typedef int (*less_than_predictate_t)(type_t, type_t);

typedef struct
{
    type_t *array;
    uint32_t size;
    uint32_t max_size;
    less_than_predictate_t less_than;
} ordered_array_t;

int standard_less_than_predicate(type_t a, type_t b);

ordered_array_t create_ordered_array(uint32_t max_size, less_than_predictate_t less_than);
ordered_array_t place_ordered_array(void * addr, uint32_t max_size, less_than_predictate_t less_than);

void destroy_orderred_array(ordered_array_t *array);

void insert_ordered_array(type_t item, ordered_array_t *array);

type_t lookup_ordered_array(uint32_t i, ordered_array_t *array);

void remove_ordered_array(uint32_t i, ordered_array_t *array);

#endif /* ORDERED_ARRAY_H */