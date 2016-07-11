#include <stdio.h>
#include <stdlib.h>

typedef struct demo *List;
typedef int ElementType;

List createList();
int isEmpty(List L);
void addElement(ElementType inData, List L);
List findPrevious(List L, ElementType inData);
void delFirst(List L);
void delOthers(List L, ElementType inData);
void display(List L);
void disposeList(List L);
void insert(List L, ElementType inData, ElementType newData);
/* 将newData插入到inData位置，并将inData后移 */

struct demo {
	ElementType data;
	struct demo *next;
};

List createList() {
	List L;

	L = (List)malloc(sizeof(struct demo));
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

void addElement(ElementType inData, List L) {
	List newNode, current;

	newNode = (List)malloc(sizeof(struct demo));
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

List findPrevious(List L, ElementType inData) {
	List position;
	position = L;

	while (position->next != NULL && position->next->data != inData)
		position = position->next;

	return position;
}

void delFirst(List L) {
	List tmp;
	if (!isEmpty(L)) {
		tmp = L->next;
		L->next = L->next->next;
		free(tmp);
	}
}

void delOthers(List L, ElementType inData) {
	List prev, current;

	prev = findPrevious(L, inData);
	if (prev->next == NULL)
		printf_s("Element not Found");
	else {
		current = prev->next;
		prev->next = current->next;
		free(current);
	}
}

void display(List L) {
	List current;
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
	List current;

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

void insert(List L, ElementType inData, ElementType newData) {
	List newNode, prev, current;

	newNode = (List)malloc(sizeof(struct demo));
	if (newNode == NULL)
		printf_s("Error");
	else {
		prev = findPrevious(L, inData);
		current = prev->next;
		prev->next = newNode;
		newNode->data = newData;
		newNode->next = current;
	}
}

int main() {
	List L;
	int i;

	L = createList();
	if (L == NULL) {
		printf_s("Error");
		return 1;
	}

	printf_s("First, is List Empty? %d\n", isEmpty(L));
	for (i = 0; i < 5; i++)
		addElement(i + 1, L);
	display(L);

	printf_s("\nInsert(L, 1, 0): ");
	insert(L, 1, 0);
	display(L);

	printf_s("\nInsert(L, 3, 10): ");
	insert(L, 3, 10);
	display(L);

	printf_s("\nInsert(L, 5, 6): ");
	insert(L, 5, 6);
	display(L);

	printf_s("\nDelete the first: ");
	delFirst(L);
	display(L);

	printf_s("\nDelOthers(L,10): ");
	delOthers(L, 10);
	display(L);

	printf_s("\nDelOthers(L,5): ");
	delOthers(L, 5);
	display(L);

	printf_s("\nDelOthers(L,1): ");
	delOthers(L, 1);
	display(L);

	printf_s("\nDelOthers(L,0): ");
	delOthers(L, 0);
	display(L);

	disposeList(L);
}