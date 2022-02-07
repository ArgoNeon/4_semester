#ifndef VECTOR_H
#define VECTOR_H

struct node{
	int num;
	int data;
};

struct vector {
	int size;
	struct node * zero;
};

struct vector * vector_create(int size);
void vector_destroy(struct vector * vector);
void vector_print (struct vector * vector);
struct vector * vector_generate();
void vector_push(struct vector * vector, int pos, int inf);
void vector_delete(struct vector * vector, int pos);
void vector_bubbleSort(struct vector * vector);

#endif // VECTOR_H
