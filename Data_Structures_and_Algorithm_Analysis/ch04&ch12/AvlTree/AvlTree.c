#include <stdio.h>
#include <stdlib.h>

typedef struct AvlTree *TreeNode;
typedef int ElementType;

void makeEmpty(TreeNode T);
int height(TreeNode T);
TreeNode singleRotateWithRight(TreeNode K2);
TreeNode singleRotateWithLeft(TreeNode K2);
TreeNode doubleRotateWithRight(TreeNode K3);
TreeNode doubleRotateWithLeft(TreeNode K3);
TreeNode insert(ElementType x, TreeNode T);
void display(TreeNode T);

struct AvlTree {
	ElementType data;
	TreeNode Left;
	TreeNode Right;
	int Height;
};

void makeEmpty(TreeNode T) {
	if (T != NULL) {
		makeEmpty(T->Left);
		makeEmpty(T->Right);
		free(T);
	}
}

int height(TreeNode T) {
	if (T == NULL)
		return -1;
	else
		return T->Height;
}

TreeNode singleRotateWithRight(TreeNode K2) {
	TreeNode K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = max(height(K2->Right), height(K2->Left)) + 1;
	K1->Height = max(height(K1->Right), K2->Height) + 1;

	return K1;
}

TreeNode singleRotateWithLeft(TreeNode K2) {
	TreeNode K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = max(height(K2->Left), height(K2->Right)) + 1;
	K1->Height = max(height(K1->Left), K2->Height) + 1;

	return K1;
}

TreeNode doubleRotateWithRight(TreeNode K3) {
	K3->Right = singleRotateWithLeft(K3->Right);
	return singleRotateWithRight(K3);
}

TreeNode doubleRotateWithLeft(TreeNode K3) {
	K3->Left = singleRotateWithRight(K3->Left);
	return singleRotateWithLeft(K3);
}

TreeNode insert(ElementType x, TreeNode T) {
	if (T == NULL) {
		T = (TreeNode)malloc(sizeof(struct AvlTree));
		T->data = x;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (x > T->data) {
		T->Right = insert(x, T->Right);
		if (height(T->Right) - height(T->Left) == 2) {
			/* 插入完成后检测平衡条件 */
			if (x > T->Right->data) /* 右-右 */
				T = singleRotateWithRight(T);
			else /* 右-左 */
				T = doubleRotateWithRight(T);
		}
	}
	else if (x < T->data) {
		T->Left = insert(x, T->Left);
		if (height(T->Left) - height(T->Right) == 2) {
			if (x < T->Left->data) /* 左-左 */
				T = singleRotateWithLeft(T);
			else /* 左-右 */
				T = doubleRotateWithLeft(T);
		}
	}

	T->Height = max(height(T->Left), height(T->Right)) + 1;
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
	int i, inData;

	for (i = 0; i < 16; i++) {
		printf_s("#%d: ", i + 1);
		scanf_s("%d", &inData);
		T = insert(inData, T);
	}
	printf_s("\nAVL Tree: ");
	display(T);

	makeEmpty(T);
}