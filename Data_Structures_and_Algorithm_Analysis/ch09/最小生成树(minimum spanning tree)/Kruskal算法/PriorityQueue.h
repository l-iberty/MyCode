#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#define MINDATA -1

typedef int Edge;
typedef Edge ElementType;
typedef int Index;
typedef struct HeapNode *PriorityQueue;

PriorityQueue initializeQueue(int capacity);
void insert(ElementType key, PriorityQueue H);
ElementType deleteMin(PriorityQueue H);
void disposeQueue(PriorityQueue H);
int isFull(PriorityQueue H);
int isEmpty(PriorityQueue H);

struct HeapNode {
	int capacity;
	int size;
	ElementType *Arrays;
};


PriorityQueue initializeQueue(int capacity) {
	PriorityQueue H;

	H = (PriorityQueue)malloc(sizeof(struct HeapNode));
	if (H != NULL) {
		H->capacity = capacity;
		H->size = 0;

		H->Arrays = (ElementType *)malloc(sizeof(ElementType) * (capacity + 1));
		if (H->Arrays != NULL)
			H->Arrays[0] = MINDATA;
	}

	return H;
}

void insert(ElementType key, PriorityQueue H) {
	int i;

	if (isFull(H)) {
		printf_s("Priority queue is full");
		return;
	}

	for (i = ++H->size; H->Arrays[i / 2] > key; i /= 2)
		H->Arrays[i] = H->Arrays[i / 2];
	H->Arrays[i] = key;
}

ElementType deleteMin(PriorityQueue H) {
	int i, child;
	ElementType min, last;

	if (isEmpty(H)) {
		printf_s("Priority queue is empty");
		return MINDATA;
	}
	min = H->Arrays[1];
	last = H->Arrays[H->size--];

	for (i = 1;i * 2 <= H->size;i = child) {
		/* Find smaller child */
		child = i * 2;
		if (child <= H->size && H->Arrays[child + 1] < H->Arrays[child])
			child++;

		if (child <= H->size && last > H->Arrays[child])
			H->Arrays[i] = H->Arrays[child];
		else
			break;
	}
	H->Arrays[i] = last;

	return min;
}

void disposeQueue(PriorityQueue H) {
	if (!isEmpty(H)) {
		free(H->Arrays);
		free(H);
	}
}

int isFull(PriorityQueue H) {
	return H->capacity == H->size;
}

int isEmpty(PriorityQueue H) {
	return H->size == 0;
}
#endif //_PRIORITYQUEUE_H