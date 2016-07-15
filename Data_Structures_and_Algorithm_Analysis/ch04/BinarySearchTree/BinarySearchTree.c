#include <stdio.h>
#include <stdlib.h>

typedef struct SearchTree *TreeNode;
typedef int ElementType;

void makeEmpty(TreeNode T);
TreeNode find(ElementType key, TreeNode T);
TreeNode findMin(TreeNode T);
TreeNode findMax(TreeNode T);
TreeNode insert(ElementType x, TreeNode T);
TreeNode delete(ElementType x, TreeNode T);
void display(TreeNode T);

struct SearchTree {
	ElementType data;
	TreeNode Left;
	TreeNode Right;
};

void makeEmpty(TreeNode T) {
	if (T != NULL) {
		makeEmpty(T->Left);
		makeEmpty(T->Right);
		free(T);
	}
}

TreeNode find(ElementType key, TreeNode T) {
	if (T == NULL)
		return NULL;
	else if (key < T->data)
		return find(key, T->Left);
	else if (key > T->data)
		return find(key, T->Right);
	else
		return T;
}

TreeNode findMin(TreeNode T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return findMin(T->Left);
}

TreeNode findMax(TreeNode T) {
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;

		return T;
}

TreeNode insert(ElementType x, TreeNode T) {
	if (T == NULL) {
		T = (TreeNode)malloc(sizeof(struct SearchTree));
		T->data = x;
		T->Left = T->Right = NULL;
	}
	else if (x < T->data)
		T->Left = insert(x, T->Left);
	else if (x > T->data)
		T->Right = insert(x, T->Right);
	/* Else x is in the tree already, so do nothing */

	return T;
}

TreeNode delete(ElementType x, TreeNode T) {
	TreeNode tmpNode;

	if (T == NULL)
		printf_s("Element Not Found\n");
	else if (x > T->data)
		T->Right = delete(x, T->Right);
	else if (x < T->data)
		T->Left = delete(x, T->Left);
	else if (T->Left && T->Right ) { /* Found element to be deleted */
		tmpNode = findMin(T->Right);
		T->data = tmpNode->data;
		T->Right = delete(T->data, T->Right);
	}
	else {
		tmpNode = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(tmpNode);
	}

	return T;
}

void display(TreeNode T) {
	if (T != NULL) {
		printf_s("%d ", T->data);
		display(T->Left);
		display(T->Right);
	}
}

int main() {
	TreeNode T = NULL;
	TreeNode minPos, maxPos;
	int i, inData;

	printf_s("Elements:\n");
	for (i = 0; i < 7; i++) {
		printf_s("#%d: ", i + 1);
		scanf_s("%d", &inData);
		T = insert(inData, T);
	}

	printf_s("\nTree:\n");
	display(T);

	minPos = findMin(T);
	printf_s("\nMin=%d", minPos->data);
	maxPos = findMax(T);
	printf_s("\nMax=%d", maxPos->data);

	printf_s("\nFind 6: ");
	if (find(6, T) != NULL)
		printf_s("Found");
	printf_s("\nFind 1: ");
	if (find(1, T) != NULL)
		printf_s("Found");

	printf_s("\nFind 9: ");
	if (find(9, T) != NULL)
		printf_s("Found");
	else
		printf_s("Not Found\n");

	printf_s("\nDelete 2: ");
	T = delete(2, T);
	display(T);

	makeEmpty(T);
	return 0;
}