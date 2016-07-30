#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
typedef Vertex ElementType;
typedef struct QueueDemo *Queue;

Queue createQueue();
int isQueueEmpty(Queue Q);
void enqueue(ElementType inData, Queue Q);
ElementType dequeue(Queue Q);
void disposeQueue(Queue Q);

struct QueueDemo {
	ElementType data;
	struct QueueDemo *next;
};


Queue createQueue() {
	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueDemo));
	if (Q == NULL)
		return NULL;
	else {
		Q->next = NULL;
		return Q;
	}
}

int isQueueEmpty(Queue Q) {
	return Q->next == NULL;
}

void enqueue(ElementType inData, Queue Q) {
	Queue rear, current;

	rear = (Queue)malloc(sizeof(struct QueueDemo));
	if (rear == NULL)
		printf_s("Enqueue Failed");
	else {
		rear->data = inData;
		rear->next = NULL;
	}

	current = Q;
	while (current->next != NULL)
		current = current->next;

	current->next = rear;
}

ElementType dequeue(Queue Q) {
	Queue Front;
	ElementType Item;
	
	Front = Q->next;
	Item = Front->data;
	Q->next = Q->next->next;
	free(Front);

	return Item;
}

void disposeQueue(Queue Q) {
	Queue P, AfterP;
	
	P = Q;
	while (P != NULL) {
		AfterP = P->next;
		free(P);
		P = AfterP;
	}
}