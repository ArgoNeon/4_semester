#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct vector {
	data * arr;
	size_t capacity;
	size_t size;
};

vector * vector_create_zero() {
	vector * vector = malloc(sizeof(vector));

	if (vector == NULL) 
		return NULL;

	vector->arr = NULL;
	vector->capacity = 0;
	vector->size = 0;
	return vector;
}

vector * vector_create_empty(size_t capacity) {
	vector * vector = malloc(sizeof(vector));
	
	if (vector == NULL)
		return NULL;

	vector->arr = malloc(sizeof(data) * capacity);

	if (vector->arr == NULL) {
		free(vector);
		return NULL;
	}

	vector->capacity = capacity;
	vector->size = 0;
	return vector;	
};

vector * vector_create_full(size_t capacity, size_t size, data * arr) {
	if (size > capacity)
		return NULL;

	vector * vector = malloc(sizeof(vector));
	
	if (vector == NULL)
		return NULL;

	vector->arr = malloc(sizeof(data) * capacity);

	if (vector->arr == NULL) {
		free(vector);
		return NULL;
	}

	vector->capacity = capacity;
	vector->size = size;

	for (int i = 0; i < size; i++) {
		vector->arr[i] = arr[i];
	}
	
	return vector;
};

void vector_destroy(vector * vector) {
	free(vector->arr);
	free(vector);
	vector = NULL;
}

void vector_print(vector * vector) {
	int i;
	printf("capacity: %ld\nsize: %ld\n", vector->capacity, vector->size);

	for (i = 0; i < vector->size; i++) {
		printf("num  %d  data  %d\n", i, vector->arr[i]);	
	}
}

int vector_extension(vector * vector) {
	if (vector->capacity == 0)
		vector->capacity = 1;
	else
		vector->capacity = vector->capacity * 2;
	data * arr = malloc(sizeof(data) * vector->capacity);
	
	if (arr == NULL)
		return 1;

	for (int i = 0; i < vector->size; i++) 
		arr[i] = vector->arr[i];

	free(vector->arr);
	vector->arr = arr;
	return 0;
}

int vector_push(vector * vector, int val) {
	vector->size = vector->size + 1;
	
	if (vector->size > vector->capacity)
		if (vector_extension(vector) == 1)
			return 1;

	vector->arr[vector->size - 1] = val;
	return 0;
}

void vector_delete(vector * vector, size_t pos) {
	vector->size = vector->size - 1;

	for (int i = pos; i < vector->size; i++) 
		vector->arr[i] = vector->arr[i + 1];
}

int vector_swap(vector * vector, size_t pos1, size_t pos2) {
	if ((pos1 > vector->size) || (pos2 > vector->size))
		return 1;

	int swp = vector->arr[pos1];
	vector->arr[pos1] = vector->arr[pos2];
	vector->arr[pos2] = swp;
	return 0;
}

size_t vector_get_size(vector * vector) {
	size_t size = vector->size;
	return size;
}

data vector_get_val(vector * vector, size_t i, int * flag) {
	if (i > vector->size) {
		* flag = 1;
		return 0;
	}

	* flag = 0;
	return vector->arr[i];
};

int vector_set_val(vector * vector, size_t i, int val) {
	if (i > vector->size)
		return 1;
	
	vector->arr[i] = val;
	return 0;
};


vector * vector_generate() {
	int capacity = rand() % 100 + 1;
	vector * vector = malloc(sizeof(vector));
	
	if (vector == NULL)
		return NULL;

	data * arr = malloc(sizeof(data) * capacity);

	if (arr == NULL) {
		free(vector);
		return NULL;
	}

	vector->capacity = capacity;
	vector->size = capacity;
	vector->arr = arr;
	
	for (int i = 0; i < vector->size; i++) {
		vector->arr[i] = rand() % 1000 + 1;
	}

	return vector;
}

vector * vector_generate_size(size_t capacity) {
	vector * vector = malloc(sizeof(vector));

	if (vector == NULL)
		return NULL;

	data * arr = malloc(sizeof(data) * capacity);

	if (arr == NULL) {
		free(vector);
		return NULL;
	}

	vector->capacity = capacity;
	vector->size = capacity;
	vector->arr = arr;
	
	for (int i = 0; i < vector->size; i++) {
		vector->arr[i] = rand() % 1000 + 1;
	}
	
	return vector;
}
