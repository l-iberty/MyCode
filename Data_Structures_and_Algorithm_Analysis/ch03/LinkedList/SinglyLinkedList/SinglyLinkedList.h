#ifndef _SINGLYLINKEDLIST_H
#define _SINGLYLINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ListTbl *List;
typedef struct ListTbl *Position;
typedef int ElementType;

List createList();
int isEmpty(List L);
void addElement(ElementType inData, List L);
Position findPrevious(List L, ElementType inData);
void delFirst(List L);
void delOthers(List L, ElementType inData);
void display(List L);
void disposeList(List L);
void insert(List L, ElementType inData, ElementType newData);
/* 将newData插入到inData位置，并将inData后移 */

struct ListTbl {
	ElementType data;
	struct ListTbl *next;
};

List createList() {
	List L;

	L = (List)malloc(sizeof(struct ListTbl));
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
	List newNode;
	Position current;

	newNode = (List)malloc(sizeof(struct ListTbl));
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

Position findPrevious(List L, ElementType inData) {
	Position position;
	position = L;

	while (position->next != NULL && position->next->data != inData)
		position = position->next;

	return position;
}

void delFirst(List L) {
	Position tmp;
	if (!isEmpty(L)) {
		tmp = L->next;
		L->next = L->next->next;
		free(tmp);
	}
}

void delOthers(List L, ElementType inData) {
	Position prev, current;

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

void insert(List L, ElementType inData, ElementType newData) {
	List newNode;
	Position prev, current;

	newNode = (List)malloc(sizeof(struct ListTbl));
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

#endif // _SINGLYLINKEDLIST_H