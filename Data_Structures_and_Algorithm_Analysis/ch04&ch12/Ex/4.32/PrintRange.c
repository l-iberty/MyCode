#include <stdio.h>
#include <stdlib.h>

typedef struct SearchTree *TreeNode;
typedef int ElementType;

void makeEmpty(TreeNode T);
TreeNode insert(ElementType x, TreeNode T);
void display(TreeNode T);
void printRange(TreeNode T, ElementType k1, ElementType k2);

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

void display(TreeNode T) {
	if (T != NULL) {
		printf_s("%d ", T->data);
		display(T->Left);
		display(T->Right);
	}
}

void printRange(TreeNode T, ElementType k1, ElementType k2) {
	if (T != NULL) {
		if (T->data >= k1 && T->data <= k2)
			printf_s("%d ", T->data);
		printRange(T->Left, k1, k2);
		printRange(T->Right, k1, k2);
	}
}

int main() {
	TreeNode T = NULL;
	int i, inData;

	printf_s("Elements:\n");
	for (i = 0; i < 7; i++) {
		printf_s("#%d: ", i + 1);
		scanf_s("%d", &inData);
		T = insert(inData, T);
	}

	printf_s("\nTree:\n");
	display(T);
	
	printf_s("\nRange[1,5]: ");
	printRange(T, 1, 5);
	
	makeEmpty(T);
	return 0;
}