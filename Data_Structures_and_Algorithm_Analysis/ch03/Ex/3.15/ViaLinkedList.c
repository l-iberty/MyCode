#include <stdio.h>
#include <stdlib.h>

typedef struct Demo *List;
typedef struct Demo *Position;
typedef int ElementType;

List createList();
void addElement(ElementType inData, List L);
int find(ElementType x, List L);
void display(List L);
void disposeList(List L);

struct Demo {
	ElementType data;
	struct Demo *next;
};

List createList() {
	List L;

	L = (List)malloc(sizeof(struct Demo));
	if (L == NULL) {
		printf_s("Error");
		return NULL;
	}
	L->next = NULL;

	return L;
}

void addElement(ElementType inData, List L) {
	List newNode;

	newNode = (List)malloc(sizeof(struct Demo));
	if (newNode == NULL)
		printf_s("Error");
	else {
		newNode->data = inData;
		newNode->next = L->next;
		L->next = newNode;
	}
}

int find(ElementType x, List L) {
	Position prev, current, head;

	prev = L;
	while (prev->next != NULL && prev->next->data != x)
		prev = prev->next;
	/* 如果循环结束后prev是最后一个节点，则Not Found */
	if (prev->next == NULL)
		return 0;
	else {
		current = prev->next;
		head = L->next;
		L->next = current;
		prev->next = current->next;
		current->next = head;

		return 1;
	}
}

void display(List L) {
	Position current;
	current = L->next;
	while (current != NULL) {
		printf_s("%d ", current->data);
		current = current->next;
	}
}

void disposeList(List L) {
	Position current;

	current = L;
	while (current != NULL) {
		L = L->next;
		free(current);
		current = L;
	}
}

int main() {
	List L = createList();
	int i;

	for (i = 0;i < 5;i++)
		addElement(i + 1, L);
	display(L);

	printf_s("\n");
	if (find(1, L))
		display(L);
	else
		printf_s("Element %d not found\n", 1);

	printf_s("\n");
	if (find(3, L))
		display(L);
	else
		printf_s("Element %d not found\n", 3);

	printf_s("\n");
	if (find(6, L))
		display(L);
	else
		printf_s("Element %d not found\n", 6);

	disposeList(L);
	return 0;
}