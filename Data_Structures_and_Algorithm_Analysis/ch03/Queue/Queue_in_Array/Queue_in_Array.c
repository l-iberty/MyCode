#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ElementType int

typedef struct QueueDemo *Queue;

Queue createQueue(int size);
int isEmpty(Queue Q);
int isFull(Queue Q);
int circulate(int value, Queue Q);
void enqueue(ElementType inData, Queue Q);
void dequeue(Queue Q);
ElementType front(Queue Q);
void display(Queue Q);
void disposeQueue(Queue Q);

struct QueueDemo
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

Queue createQueue(int size) {
	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueDemo));
	if (Q == NULL)
		return NULL;
	else {
		Q->Array = (ElementType *)malloc(sizeof(ElementType) * size);
		if (Q->Array == NULL)
			return NULL;

		Q->Capacity = size;
		Q->Size = 0;
		Q->Front = 0;
		Q->Rear = -1;
		return Q;
	}
}

int isEmpty(Queue Q) {
	return Q->Size == 0;
}

int isFull(Queue Q) {
	return Q->Size == Q->Capacity;
}

int circulate(int value, Queue Q) {
	if (++value == Q->Capacity)
		value = 0;
	return value;
}

void enqueue(ElementType inData, Queue Q) {
	if (isFull(Q))
		printf_s("Full Queue\n");
	else {
		Q->Size++;
		Q->Rear = circulate(Q->Rear, Q);
		Q->Array[Q->Rear] = inData;
	}
}

void dequeue(Queue Q) {
	if (isEmpty(Q))
		printf_s("Empty Queue\n");
	else {
		Q->Size--;
		Q->Front = circulate(Q->Front, Q);
	}
}

ElementType front(Queue Q) {
	if (isEmpty(Q))
		return -1;
	else
		return Q->Array[Q->Front];
}

void display(Queue Q) {
	int i;
	if (isEmpty(Q))
		printf_s("Display Error: Empty Queue");
	else
		for (i = Q->Front; i <= Q->Rear; i++)
			printf_s("%d ", Q->Array[i]);
}

void disposeQueue(Queue Q) {
	if (Q != NULL) {
		free(Q->Array);
		free(Q);
		printf_s("\nQueue Disposed\n");
	}
}

int main() {
	Queue Q;
	int i, size;

	size = 5;
	Q = createQueue(size);
	if (Q == NULL) {
		printf_s("Error");
		return 1;
	}

	for (i = 0; i < size+2; i++)
		enqueue(i+1, Q);
	display(Q);
	printf("  Front=%d", front(Q));
	for (i = 0; i < size; i++) {
		printf_s("\nPress any key to dequeue... ");
		_getch();
		dequeue(Q);
		display(Q);
		printf("  Front=%d", front(Q));
	}
	disposeQueue(Q);

	return 0;
}