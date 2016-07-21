#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct HeapNode *SkewHeap;

SkewHeap initialize(void);
SkewHeap merge(SkewHeap H1, SkewHeap H2);
SkewHeap merge1(SkewHeap H1, SkewHeap H2);
SkewHeap insert(ElementType key, SkewHeap H);
SkewHeap deleteMin(SkewHeap H);
void swapChildren(SkewHeap H);
int isEmpty(SkewHeap H);
void display(SkewHeap H);
void makeEmpty(SkewHeap H);

struct HeapNode {
	ElementType key;
	SkewHeap Left;
	SkewHeap Right;
};

SkewHeap initialize(void) {
	return NULL;
}

SkewHeap merge(SkewHeap H1, SkewHeap H2) {
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->key < H2->key)
		return merge1(H1, H2);
	else
		return merge1(H2, H1);
}

SkewHeap merge1(SkewHeap H1, SkewHeap H2) {
	H1->Right = merge(H1->Right, H2);
	swapChildren(H1);

	return H1;
}

SkewHeap insert(ElementType key, SkewHeap H) {
	SkewHeap NewNode;

	NewNode = (SkewHeap)malloc(sizeof(struct HeapNode));
	if (NewNode != NULL) {
		NewNode->key = key;
		NewNode->Left = NewNode->Right = NULL;

		return merge(NewNode, H);
	}
	return NULL;
}

SkewHeap deleteMin(SkewHeap H) {
	SkewHeap LeftHeap, RightHeap;

	if (!isEmpty(H)) {
		LeftHeap = H->Left;
		RightHeap = H->Right;

		free(H);
		return merge(LeftHeap, RightHeap);
	}
	return NULL;
}

void swapChildren(SkewHeap H) {
	SkewHeap TempNode;
	if (H != NULL) {
		TempNode = H->Left;
		H->Left = H->Right;
		H->Right = TempNode;
	}
}

int isEmpty(SkewHeap H) {
	return H == NULL;
}

void display(SkewHeap H) {
	if (H != NULL) {
		printf_s("%d ", H->key);
		display(H->Left);
		display(H->Right);
	}
}

void makeEmpty(SkewHeap H) {
	if (H != NULL) {
		makeEmpty(H->Left);
		makeEmpty(H->Right);
		free(H);
	}
}

int main() {
	SkewHeap H1, H2, H;
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

	printf_s("\nMerge H1 and H2:\n");
	H = merge(H1, H2);
	display(H);

	makeEmpty(H);
	return H;
}