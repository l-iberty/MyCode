#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct HeapNode *LeftistHeap;

LeftistHeap initialize(void);
LeftistHeap merge(LeftistHeap H1, LeftistHeap H2);
LeftistHeap merge1(LeftistHeap H1, LeftistHeap H2);
LeftistHeap insert(ElementType key, LeftistHeap H);
LeftistHeap deleteMin(LeftistHeap H);
void swapChildren(LeftistHeap H);
int isEmpty(LeftistHeap H);
void display(LeftistHeap H);
void makeEmpty(LeftistHeap H);

struct HeapNode {
	ElementType key;
	LeftistHeap Left;
	LeftistHeap Right;
	int Npl;
};

LeftistHeap initialize(void) {
	return NULL;
}

LeftistHeap merge(LeftistHeap H1, LeftistHeap H2) {
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->key < H2->key)
		return merge1(H1, H2);
	else
		return merge1(H2, H1);
}

LeftistHeap merge1(LeftistHeap H1, LeftistHeap H2) {
	if (H1->Left == NULL)
		H1->Left = H2;
	else {
		H1->Right = merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			swapChildren(H1);

		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

LeftistHeap insert(ElementType key, LeftistHeap H) {
	LeftistHeap NewNode;

	NewNode = (LeftistHeap)malloc(sizeof(struct HeapNode));
	if (NewNode != NULL) {
		NewNode->key = key;
		NewNode->Left = NewNode->Right = NULL;
		NewNode->Npl = 0;

		return merge(NewNode, H);
	}
	return NULL;
}

LeftistHeap deleteMin(LeftistHeap H) {
	LeftistHeap LeftHeap, RightHeap;

	if (!isEmpty(H)) {
		LeftHeap = H->Left;
		RightHeap = H->Right;

		free(H);
		return merge(LeftHeap, RightHeap);
	}
	return NULL;
}

void swapChildren(LeftistHeap H) {
	LeftistHeap TempNode;
	if (H != NULL) {
		TempNode = H->Left;
		H->Left = H->Right;
		H->Right = TempNode;
	}
}

int isEmpty(LeftistHeap H) {
	return H == NULL;
}

void display(LeftistHeap H) {
	if (H != NULL) {
		printf_s("Key: %d\tNpl: %d\n", H->key, H->Npl);
		display(H->Left);
		display(H->Right);
	}
}

void makeEmpty(LeftistHeap H) {
	if (H != NULL) {
		makeEmpty(H->Left);
		makeEmpty(H->Right);
		free(H);
	}
}

int main() {
	LeftistHeap H1, H2, H;
	int i, key;
	int h1[] = { 3,10,8,21,14,17,23,26 },
		h2[] = { 6,12,7,18,24,37,18,33 };

	H1 = H2 = H = initialize();
	printf_s("H1:\n");
	for (i = 0;i < 8;i++)
		H1 = insert(h1[i], H1);
	display(H1);

	printf_s("\nH2:\n");
	for (i = 0;i < 8;i++)
		H2 = insert(h2[i], H2);
	display(H2);

	//printf_s("\nMerge H1 and H2:\n");
	//H = merge(H1, H2);
	//display(H);

	makeEmpty(H1);
	makeEmpty(H2);
	return H;
}