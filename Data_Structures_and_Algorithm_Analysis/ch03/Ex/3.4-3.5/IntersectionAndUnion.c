#include <stdio.h>
#include <stdlib.h>

typedef struct Demo *List;
typedef struct Demo *Position;

struct Demo {
	int data;
	struct Demo *next;
};

List createList();
int isEmpty(List L);
void addElement(int inData, List L);
Position findPrevious(List L, int inData);
void display(List L);
void disposeList(List L);

void Intersection(List L1, List L2);
void Union(List L1, List L2);

List createList() {
	List L;

	L = (List)malloc(sizeof(struct Demo));
	if (L == NULL)
		return NULL;
	else {
		L->next = NULL;
		return L;
	}
}

int isEmpty(List L) {
	return L->next == NULL;
}

void addElement(int inData, List L) {
	List newNode;
	Position current;

	newNode = (List)malloc(sizeof(struct Demo));
	if (newNode == NULL)
		printf_s("Error");
	else {
		current = L;
		while (current->next != NULL)
			current = current->next;

		newNode->data = inData;
		newNode->next = NULL;
		current->next = newNode;
	}
}

Position findPrevious(List L, int inData) {
	Position position;
	position = L;

	while (position->next != NULL && position->next->data != inData)
		position = position->next;

	return position;
}

void display(List L) {
	Position current;
	if (isEmpty(L))
		printf_s("Empty List");
	else {
		current = L->next;
		while (current != NULL) {
			printf_s("%d ", current->data);
			current = current->next;
		}
	}
}

void disposeList(List L) {
	Position current;

	if (isEmpty(L))
		printf_s("Error");
	else {
		current = L;
		while (current != NULL) {
			L = L->next;
			free(current);
			current = L;
		}
	}
}

void Intersection(List L1, List L2) {
	Position P1, P2;
	P1 = L1->next;
	P2 = L2->next;

	while (P1 != NULL && P2 != NULL) {
		if (P1->data > P2->data) {
			P2 = P2->next;
		}
		else if (P1->data < P2->data) {
			P1 = P1->next;
		}
		else {
			printf_s("%d ", P1->data);
			P1 = P1->next;
			P2 = P2->next;
		}
	}
}

void Union(List L1, List L2) {
	Position P1, P2, P;
	P1 = L1->next;
	P2 = L2->next;

	while (P1 != NULL && P2 != NULL) {
		if (P1->data > P2->data) {
			printf_s("%d ", P2->data);
			P2 = P2->next;
		}
		else if (P1->data < P2->data) {
			printf_s("%d ", P1->data);
			P1 = P1->next;
		}
		else {
			printf_s("%d ", P1->data);
			P1 = P1->next;
			P2 = P2->next;
		}
	}

	P = NULL;
	if (P1 != NULL && P2 == NULL)
		P = P1;
	else if (P1 == NULL && P2 != NULL)
		P = P2;

	while (P != NULL) {
		printf_s("%d ", P->data);
		P = P->next;
	}
}

int main() {
	int i, inData;
	List L1 = createList(), L2 = createList();
	
	printf_s("L1:\n");
	for (i = 0; i < 4; i++) {
		scanf_s("%d", &inData);
		addElement(inData, L1);
	}

	printf_s("\nL2:\n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &inData);
		addElement(inData, L2);
	}

	printf_s("\nL1: ");
	display(L1);
	printf_s("\nL2: ");
	display(L2);

	printf_s("\nIntersection: ");
	Intersection(L1, L2);

	printf_s("\nUnion: ");
	Union(L1, L2);

	disposeList(L1);
	disposeList(L2);

	return 0;
}