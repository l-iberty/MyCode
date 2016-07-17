#include <stdio.h>
#include <stdlib.h>

typedef struct SearchTree *TreeNode;
typedef int ElementType;

void makeEmpty(TreeNode T);
TreeNode insert(ElementType x, TreeNode T);
void display(TreeNode T);
int countNodes(TreeNode T);
int countLeaves(TreeNode T);
int countFullNodes(TreeNode T);

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

int countNodes(TreeNode T) {
	int Nodes = 0;
	
	if (T != NULL) {
		Nodes++;
		Nodes += countNodes(T->Left) + countNodes(T->Right);
	}
	return Nodes;
}

int countLeaves(TreeNode T) {
	int Leaves = 0;

	if (T != NULL) {
		if (T->Left == NULL && T->Right == NULL)
			Leaves++;

		if (T->Left != NULL)
			Leaves += countLeaves(T->Left);
		if (T->Right != NULL)
			Leaves += countLeaves(T->Right);
	}
	return Leaves;
}

int countFullNodes(TreeNode T) {
	int FullNodes = 0;

	if (T != NULL) {
		if (T->Left != NULL && T->Right != NULL)
			FullNodes++;

		FullNodes += countFullNodes(T->Left) + countFullNodes(T->Right);
	}
	return FullNodes;
}

int main() {
	TreeNode T = NULL;
	int i, inData;

	printf_s("Elements:\n");
	for (i = 0; i < 7; i++) {
		printf_s("#%d: ", i + 1);
		scanf_s("%d", &inData);
		T = insert(inData, T);
		//T = insert(i + 1, T);
	}

	printf_s("\nTree:\n");
	display(T);
	printf_s("\nNodes: %d", countNodes(T));
	printf_s("\nLeaves: %d", countLeaves(T));
	printf_s("\nFullNodes: %d\n", countFullNodes(T));

	makeEmpty(T);
	return 0;
}