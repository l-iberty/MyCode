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

void swap(Position PrevP, List L);
/* PrevP is the cell before the two adjacent cells that are to be swapped */

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

void swap(Position PrevP, List L) {
	Position P, AfterP;

	P = PrevP->next;
	AfterP = P->next;
	PrevP->next = AfterP;
	P->next = AfterP->next;
	AfterP->next = P;
}

int main() {
	int i;
	List L = createList();
	Position PrevP;

	for (i = 0;i < 10; i++)
		addElement(i + 1, L);
	display(L);

	PrevP = findPrevious(L, 1);
	swap(PrevP, L);
	printf_s("\n");
	display(L);

	PrevP = findPrevious(L, 5);
	swap(PrevP, L);
	printf_s("\n");
	display(L);

	return 0;
}