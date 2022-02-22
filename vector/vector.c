#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

typedef struct vector {
	data * arr;
	size_t capacity;
	size_t size;
} vector;

void vector_destroy(container * cont);
void vector_print (container * cont);
int vector_push(container * cont, int val);
void vector_delet(container * cont, size_t pos);
int vector_swap(container * cont, size_t pos1, size_t pos2);
size_t vector_get_size(container * cont);
data vector_get_val(container * cont, size_t i, int * flag);
int vector_set_val(container * cont, size_t i, int val);

container * vector_create_zero() {
	container * cont = malloc(sizeof(container) + sizeof(vector));

	if (cont == NULL) 
		return NULL;
	
	cont->m = malloc(sizeof(table));
	
	if (cont->m == NULL) {
		free(cont);
		return NULL;
	}

	vector * vect = (vector *)(cont + 1);

	vect->arr = NULL;
	cont->m->destroy = &vector_destroy;
	cont->m->print = &vector_print;
	cont->m->push = &vector_push;
	cont->m->delet = &vector_delet;
	cont->m->swap = &vector_swap;
	cont->m->get_size = &vector_get_size;
	cont->m->get_val = &vector_get_val;
	cont->m->set_val = &vector_set_val;
	vect->capacity = 0;
	vect->size = 0;
	return cont;
}

container * vector_create_empty(size_t capacity) {
	container * cont = malloc(sizeof(container) + sizeof(vector));
	
	if (cont == NULL)
		return NULL;

	cont->m = malloc(sizeof(table));

	if (cont->m == NULL) {
		free(cont);
		return NULL;
	}

	vector * vect = (vector *)(cont + 1);

	vect->arr = malloc(sizeof(data) * capacity);

	if (vect->arr == NULL) {
		free(cont->m);
		free(cont);
		return NULL;
	}

	cont->m->destroy = &vector_destroy;
	cont->m->print = &vector_print;
	cont->m->push = &vector_push;
	cont->m->delet = &vector_delet;
	cont->m->swap = &vector_swap;
	cont->m->get_size = &vector_get_size;
	cont->m->get_val = &vector_get_val;
	cont->m->set_val = &vector_set_val;
	vect->capacity = capacity;
	vect->size = 0;
	return cont;	
}

container * vector_create_full(size_t capacity, size_t size, data * arr) {
	if (size > capacity)
		return NULL;

	container * cont = malloc(sizeof(container) + sizeof(vector));
	
	if (cont == NULL)
		return NULL;

	cont->m = malloc(sizeof(table));

	if (cont->m == NULL) {
		free(cont);
		return NULL;
	}

	vector * vect = (vector *)(cont + 1);

	vect->arr = malloc(sizeof(data) * capacity);

	if (vect->arr == NULL) {
		free(cont->m);
		free(cont);
		return NULL;
	}

	cont->m->destroy = &vector_destroy;
	cont->m->print = &vector_print;
	cont->m->push = &vector_push;
	cont->m->delet = &vector_delet;
	cont->m->swap = &vector_swap;
	cont->m->get_size = &vector_get_size;
	cont->m->get_val = &vector_get_val;
	cont->m->set_val = &vector_set_val;
	vect->capacity = capacity;
	vect->size = size;

	for (int i = 0; i < size; i++) {
		vect->arr[i] = arr[i];
	}
	
	return cont;
}

void vector_destroy(container * cont) {
	vector * vect = (vector *)(cont + 1);

	free(vect->arr);
	free(cont);
	vect = NULL;
}

void vector_print(container * cont) {
	int i;
	vector * vect = (vector *)(cont + 1);

	printf("capacity: %ld\nsize: %ld\n", vect->capacity, vect->size);

	for (i = 0; i < vect->size; i++) {
		printf("num  %d  data  %d\n", i, vect->arr[i]);	
	}
}

int vector_extension(container * cont) {
	vector * vect = (vector *)(cont + 1);
	
	if (vect->capacity == 0)
		vect->capacity = 1;
	else
		vect->capacity = vect->capacity * 2;
	data * arr = malloc(sizeof(data) * vect->capacity);
	
	if (arr == NULL)
		return 1;

	for (int i = 0; i < vect->size; i++) 
		arr[i] = vect->arr[i];

	free(vect->arr);
	vect->arr = arr;
	return 0;
}

int vector_push(container * cont, int val) {
	vector * vect = (vector *)(cont + 1);

	vect->size = vect->size + 1;
	
	if (vect->size > vect->capacity)
		if (vector_extension(cont) == 1)
			return 1;

	vect->arr[vect->size - 1] = val;
	return 0;
}

void vector_delet(container * cont, size_t pos) {
	vector * vect = (vector *)(cont + 1);

	vect->size = vect->size - 1;

	for (int i = pos; i < vect->size; i++) 
		vect->arr[i] = vect->arr[i + 1];
}

int vector_swap(container * cont, size_t pos1, size_t pos2) {
	vector * vect = (vector *)(cont + 1);
	
	if ((pos1 > vect->size) || (pos2 > vect->size))
		return 1;

	int swp = vect->arr[pos1];
	vect->arr[pos1] = vect->arr[pos2];
	vect->arr[pos2] = swp;
	return 0;
}

size_t vector_get_size(container * cont) {
	vector * vect = (vector *)(cont + 1);

	size_t size = vect->size;
	return size;
}

data vector_get_val(container * cont, size_t i, int * flag) {
	vector * vect = (vector *)(cont + 1);
	
	if (i > vect->size) {
		* flag = 1;
		return 0;
	}

	* flag = 0;
	return vect->arr[i];
}

int vector_set_val(container * cont, size_t i, int val) {
	vector * vect = (vector *)(cont + 1);
	
	if (i > vect->size)
		return 1;
	
	vect->arr[i] = val;
	return 0;
}

container * vector_generate(size_t capacity) {
	container * cont = malloc(sizeof(container) + sizeof(vector));

	if (cont == NULL)
		return NULL;
	
	cont->m = malloc(sizeof(table));

	if (cont->m == NULL) {
		free(cont);
		return NULL;
	}

	vector * vect = (vector *)(cont + 1);

	vect->arr = malloc(sizeof(data) * capacity);

	if (vect->arr == NULL) {
		free(cont->m);
		free(cont);
		return NULL;
	}
	
	cont->m->destroy = &vector_destroy;
	cont->m->print = &vector_print;
	cont->m->push = &vector_push;
	cont->m->delet = &vector_delet;
	cont->m->swap = &vector_swap;
	cont->m->get_size = &vector_get_size;
	cont->m->get_val = &vector_get_val;
	cont->m->set_val = &vector_set_val;
	vect->capacity = capacity;
	vect->size = capacity;
	
	for (int i = 0; i < vect->size; i++) {
		vect->arr[i] = rand() % 1000 + 1;
	}
	
	return cont;
}
