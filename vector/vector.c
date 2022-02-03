#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct vector * vector_create(int size) {
	int i;
	struct vector * vector = calloc(1, sizeof(struct vector));
	struct node * node = calloc(size, sizeof(struct node));
	vector->size = size;
	vector->zero = node;

	for (i = 0; i < size; i++)
		vector->zero[i].num = i;

	return vector;
}

void vector_destroy (struct vector * vector) {
	free(vector->zero);
	free(vector);
}

void vector_print (struct vector * vector) {
	int i;
	printf("size: %d\n", vector->size);

	for (i = 0; i < vector->size; i++) {
		printf("num  %d  data  %d\n", vector->zero[i].num, vector->zero[i].data);	
	}
}
