#include <stdio.h>

#include "vector.h"

int main() {
	struct vector * vector;
	vector = vector_create(2);
	vector->zero[1].data = 5;
	vector_print(vector);
	vector_destroy(vector);
	
	return 0;
}
