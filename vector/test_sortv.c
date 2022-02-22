#include <stdio.h>

#include "vector.h"

void vector_bubbleSort(vector * vector) {
size_t size = vector_get_size(vector);
int flag1, flag2;

for (int i = 0; i < size - 1; i++) {
	for (int j = size - 1; j > i; j--) {
		if (vector_get_val(vector, j, &flag1) < vector_get_val(vector, j - 1, &flag2))
			vector_swap(vector, j - 1, j);
		}
	}
}

int main() {
	vector * vector;
	vector = vector_generate_size(65);
	vector_push(vector, -34);
	vector_delete(vector, 64);
	vector_print(vector);
	vector_bubbleSort(vector);
	vector_print(vector);
	vector_destroy(vector);
	
	return 0;
}
