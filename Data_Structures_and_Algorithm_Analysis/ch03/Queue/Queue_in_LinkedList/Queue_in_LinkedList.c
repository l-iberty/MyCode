#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ElementType int

typedef struct QueueDemo *Queue;

Queue createQueue();
int isEmpty(Queue Q);
void enqueue(ElementType inData, Queue Q);
void dequeue(Queue Q);
void display(Queue Q);

struct QueueDemo
{
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

int isEmpty(Queue Q) {
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

void dequeue(Queue Q) {
	Queue front;

	if (isEmpty(Q))
		printf_s("Empty Queue");
	else {
		front = Q->next;
		Q->next = Q->next->next;
		free(front);
	}
}

void display(Queue Q) {
	Queue current;

	if (isEmpty(Q))
		printf_s("Empty Queue");
	else {
		current = Q->next;
		while (current != NULL) {
			printf("%d ", current->data);
			current = current->next;
		}
	}
}

int main() {
	Queue Q;
	int i;

	Q = createQueue();
	if (Q == NULL) {
		printf_s("Error");
		return 1;
	}

	for (i = 0; i < 5; i++)
		enqueue(i, Q);
	display(Q);
	for (i = 0; i < 5; i++) {
		printf_s("\nPress any key to dequeue...");
		_getch();
		dequeue(Q);
		display(Q);
	}

	return 0;
}