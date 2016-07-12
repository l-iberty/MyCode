#include <stdio.h>
#include <stdlib.h>

typedef struct Demo *List;
typedef int ElementType;

List createList(int size);
void addElement(ElementType inData, List L);
int find(ElementType x, List L);
void display(List L);
void disposeList(List L);

struct Demo {
	ElementType Data;
	int Capacity;
	int Size;
	int Front;
	ElementType *Array;
};

List createList(int size) {
	List L;

	L = (List)malloc(sizeof(struct Demo));
	if (L == NULL) {
		printf_s("Error");
		return NULL;
	}

	L->Array = (ElementType*)malloc(sizeof(ElementType) * size);
	if (L->Array == NULL) {
		printf_s("Error");
		return NULL;
	}

	L->Capacity = size;
	L->Size = 0;
	L->Front = -1;
	return L;
}

void addElement(ElementType inData, List L) {
	L->Array[++L->Front] = inData;
	L->Size++;
}

int find(ElementType x, List L) {
	ElementType tmp;
	int pos, i;

	for (i = 0; i < L->Size; i++) {
		if (L->Array[i] == x) {
			tmp = L->Array[i];
			pos = i;
			break;
		}
	}

	if (i == L -> Size)
		return 0; /* Not Found */
	else {
		for (i = pos; i < L->Size - 1; i++)
			L->Array[i] = L->Array[i + 1];
		/* 循环结束后，i = L->Size，指向Front */
		L->Array[i] = tmp;
		return 1;
	}
}

void display(List L) {
	int i;
	for (i = L->Front; i >= 0; i--)
		printf_s("%d ", L->Array[i]);
}

void disposeList(List L) {
	free(L->Array);
	free(L);
}

int main() {
	List L = createList(5);
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