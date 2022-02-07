#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct vector * vector_create(int size) {
	struct vector * vector = calloc(1, sizeof(struct vector));
	struct node * node = calloc(size, sizeof(struct node));
	vector->size = size;
	vector->zero = node;

	for (int i = 0; i < size; i++)
		vector->zero[i].num = i;

	return vector;
}

void vector_destroy(struct vector * vector) {
	free(vector->zero);
	free(vector);
}

void vector_print(struct vector * vector) {
	int i;
	printf("size: %d\n", vector->size);

	for (i = 0; i < vector->size; i++) {
		printf("num  %d  data  %d\n", vector->zero[i].num, vector->zero[i].data);	
	}
}

void vector_push(struct vector * vector, int pos, int inf) {
	int size = vector->size + 1;
	struct node * node = calloc(size, sizeof(struct node));
	vector->size = size;
	
	for (int i = 0; i < size; i++)
		node[i].num = i;

	for (int i = 0; i < pos; i++) 
		node[i].data = vector->zero[i].data;

	node[pos].data = inf;

	for (int i = pos + 1; i < size; i++) 
		node[i].data = vector->zero[i - 1].data;
		
	free(vector->zero);
	vector->zero = node;
}

void vector_delete(struct vector * vector, int pos) {
	int size = vector->size - 1;
	vector->size = size;

	for (int i = pos; i < size; i++) 
		vector->zero[i].data = vector->zero[i + 1].data;
	
	vector->zero = realloc(vector->zero, size);
}

void vector_swap(struct vector * vector, int pos1, int pos2) {
	int swp = vector->zero[pos1].data;
	vector->zero[pos1].data = vector->zero[pos2].data;
	vector->zero[pos2].data = swp;
}

struct vector * vector_generate() {
	int size = rand() % 100 + 1;
	struct vector * vector = calloc(1, sizeof(struct vector));
	struct node * node = calloc(size, sizeof(struct node));
	vector->size = size;
	vector->zero = node;
	
	for (int i = 0; i < size; i++) {
		vector->zero[i].num = i;
		vector->zero[i].data = rand() % 1000 + 1;
	}

	return vector;
}

void vector_bubbleSort(struct vector * vector) {
	
	for (int i = 0; i < vector->size - 1; i++) {
		for (int j = (vector->size - 1); j > i; j--) {
			if (vector->zero[j].data < vector->zero[j - 1].data)
				vector_swap(vector, j - 1, j);
		}
	}
}
