#include <stdio.h>

#include "vector.h"

void vector_bubbleSort(container * cont) {
size_t size = cont->m->get_size(cont);
int flag1, flag2;

for (int i = 0; i < size - 1; i++) {
	for (int j = size - 1; j > i; j--) {
		if (cont->m->get_val(cont, j, &flag1) < cont->m->get_val(cont, j - 1, &flag2))
			cont->m->swap(cont, j - 1, j);
		}
	}
}

int main() {
	container * cont;
	cont = vector_generate(65);
	cont->m->push(cont, -34);
	cont->m->delet(cont, 64);
	cont->m->print(cont);
	vector_bubbleSort(cont);
	cont->m->print(cont);
	cont->m->destroy(cont);
	
	return 0;
}
