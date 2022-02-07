#include <stdio.h>

#include "vector.h"

int main() {
	struct vector * vector;
	vector = vector_generate();
	vector_print(vector);
	vector_bubbleSort(vector);
	vector_print(vector);
	vector_destroy(vector);
	
	return 0;
}
