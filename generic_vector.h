#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H
#include "generic.h"
#include "status.h"

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(ITEM(*fp_init_copy)(ITEM hItem), void (*fp_destroy)(ITEM* phItem));


Boolean generic_vector_is_empty(GENERIC_VECTOR hVector); 
int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM hItem);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);
ITEM generic_vector_at(GENERIC_VECTOR hVector, int index);

void generic_vector_destroy (GENERIC_VECTOR* phVector);  

#endif