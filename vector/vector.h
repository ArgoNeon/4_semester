#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef int data;

struct container;

typedef struct table{
	void (* destroy)(struct container * cont);
	void (* print)(struct container * cont);
	int (* push)(struct container * cont, int val);
	void (* delet)(struct container * cont, size_t pos);
	int (* swap)(struct container * cont, size_t pos1, size_t pos2);
	size_t (* get_size)(struct container * cont);
	data (* get_val)(struct container * cont, size_t i, int * flag);
	int (* set_val)(struct container * cont, size_t i, int val);
} table;

typedef struct container {
	table * m;
} container;

container * vector_create_zero();
container * vector_create_empty(size_t capacity);
container * vector_create_full(size_t capacity, size_t size, data * data);
container * vector_generate(size_t capacity);

#endif // VECTOR_H
