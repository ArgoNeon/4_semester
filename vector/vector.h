#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef int data;

struct vector;

typedef struct vector vector;

vector * vector_create_zero();
vector * vector_create_empty(size_t capacity);
vector * vector_create_full(size_t capacity, size_t size, data * data);
void vector_destroy(vector * vector);

void vector_print (vector * vector);
vector * vector_generate();
vector * vector_generate_size(size_t capacity);

void vector_push(vector * vector, int val);
void vector_delete(vector * vector, size_t pos);
int vector_swap(vector * vector, size_t pos1, size_t pos2);
size_t vector_get_size(vector * vector);
data vector_get_val(vector * vector, size_t i);
int vector_set_val(vector * vector, size_t i, int val);

#endif // VECTOR_H
