#include <stdio.h>
#include <stdlib.h>
#define Infinity 10000
#define MaxTrees 4 // 二项队列中二项树的棵数

typedef int ElementType;
typedef struct BinNode *BinTree;
typedef struct TreeSet *BinQueue;

BinQueue initializeBinQueue();
int isEmpty(BinQueue H);
BinTree combineTrees(BinTree T1, BinTree T2);
BinQueue merge(BinQueue H1, BinQueue H2);
BinQueue insert(ElementType key, BinQueue H);
void deleteMin(BinQueue H);
void display(BinQueue H);
void display1(BinTree T);
void makeEmpty(BinQueue H);
void makeEmpty1(BinTree T);

struct BinNode {
	ElementType key;
	BinTree LeftChild;
	BinTree NextSibling;
};

struct TreeSet {
	int MaxNodes; // 二项队列中二项树的节点总数
	BinTree Forest[MaxTrees]; // 指针数组，每个元素指向二项树的根节点
};

BinQueue initializeBinQueue() {
	BinQueue H;
	int i;

	H = (BinQueue)malloc(sizeof(struct TreeSet));
	if (H != NULL) {
		H->MaxNodes = 0;
		for (i = 0;i < MaxTrees;i++)
			H->Forest[i] = NULL;
	}

	return H;
}

int isEmpty(BinQueue H) {
	return H->MaxNodes == 0;
}

BinTree combineTrees(BinTree T1, BinTree T2) {
	if (T1->key > T2->key)
		return combineTrees(T2, T1);
	else {
		T2->NextSibling = T1->LeftChild;
		T1->LeftChild = T2;
		return T1;
	}
}

BinQueue merge(BinQueue H1, BinQueue H2) {
	BinTree T1, T2, Carry = NULL;
	int i;

	H1->MaxNodes += H2->MaxNodes;
	for (i = 0;i < MaxTrees;i++) {
		T1 = H1->Forest[i], T2 = H2->Forest[i];

		switch (!!T1 + 2 * !!T2 + 4 * !!Carry) {
		case 0: /* No trees */
		case 1: /* Only H1 */
			break;
		case 2: /* Only H2 */
			H1->Forest[i] = T2;
			H2->Forest[i] = NULL;
			break;
		case 4: /* Only Carray */
			H1->Forest[i] = Carry;
			Carry = NULL;
			break;
		case 3: /* H1 and H2 */
			Carry = combineTrees(T1, T2);
			H1->Forest[i] = H2->Forest[i] = NULL;
			break;
		case 5: /* H1 and Carry */
			Carry = combineTrees(T1, Carry);
			H1->Forest[i] = NULL;
			break;
		case 6: /* H2 and Carry */
			Carry = combineTrees(T2, Carry);
			H2->Forest[i] = NULL;
			break;
		case 7: /* All trees */
			H1->Forest[i] = Carry;
			Carry = combineTrees(T1, T2);
			H2->Forest[i] = NULL;
			break;
		}
	}
	return H1;
}

BinQueue insert(ElementType key, BinQueue H) {
	BinQueue newQueue = initializeBinQueue();
	BinTree newTree = (BinTree)malloc(sizeof(struct BinNode));

	if (newQueue && newTree) {
		newTree->key = key;
		newTree->LeftChild = newTree->NextSibling = NULL;

		newQueue->Forest[0] = newTree;
		newQueue->MaxNodes = 1;
	}

	return merge(H, newQueue);
}

void deleteMin(BinQueue H) {
	int i;
	int minTree;
	BinQueue deletedQueue;
	BinTree deletedTree, prevTree;
	ElementType minItem;

	if (isEmpty(H))
		return;

	minItem = Infinity;
	for (i = 0;i < MaxTrees;i++) {
		if (H->Forest[i] && H->Forest[i]->key < minItem) {
			minItem = H->Forest[i]->key;
			minTree = i;
		}
	}

	deletedTree = H->Forest[minTree];
	prevTree = deletedTree;
	deletedTree = deletedTree->LeftChild;
	free(prevTree);

	deletedQueue = initializeBinQueue();
	deletedQueue->MaxNodes = (1 << minTree) - 1;
	for (i = minTree - 1;i >= 0;i--) {
		deletedQueue->Forest[i] = deletedTree;
		deletedTree = deletedTree->NextSibling;
		deletedQueue->Forest[i]->NextSibling = NULL;
	}
	/* 循环条件为i: minTree - 1 to 0，不是0 to MaxTrees - 1 */
	/* 目的是让相应高度的二项树落在正确的地方.比如Forest[2]
	处的树的高度应为2，否则在合并时会出错 */

	/*printf_s("\ndeletedQueue\n");
	display(deletedQueue);*/

	H->Forest[minTree] = NULL;
	// minTree除去根节点后被转换为二项队列deletedQueue
	// 因此合并前要将H的minTree位置清空
	H->MaxNodes = (H->MaxNodes) - (deletedQueue->MaxNodes) - 1;
	merge(H, deletedQueue);
}

void display(BinQueue H) {
	BinTree T;
	int i;

	for (i = 0;i < MaxTrees;i++) {
		T = H->Forest[i];
		display1(T);
		printf_s("\n");
	}
}

void display1(BinTree T) {
	if (T != NULL) {
		printf_s("%d ", T->key);
		display1(T->NextSibling);
		display1(T->LeftChild);
	}
}

void makeEmpty(BinQueue H) {
	BinTree T;
	int i;

	for (i = 0;i < MaxTrees;i++) {
		T = H->Forest[i];
		makeEmpty1(T);
	}
}

void makeEmpty1(BinTree T) {
	if (T != NULL) {
		makeEmpty1(T->NextSibling);
		makeEmpty1(T->LeftChild);
		free(T);
	}
}

int main() {
	BinQueue H1, H2, H;
	int i;
	int key1[6] = { 16,18,12,21,24,65 };
	int key2[7] = { 13,14,26,23,51,24,65 };

	H1 = initializeBinQueue();
	H2 = initializeBinQueue();
	H = initializeBinQueue();
	for (i = 0;i < 6;i++)
		H1 = insert(key1[i], H1);
	for (i = 0;i < 7;i++)
		H2 = insert(key2[i], H2);

	printf_s("H1: MaxNodes=%d\n", H1->MaxNodes);
	display(H1);
	printf_s("\nH2: MaxNodes=%d\n", H2->MaxNodes);
	display(H2);

	H = merge(H1, H2);
	printf_s("\nMerge: MaxNodes=%d\n", H->MaxNodes);
	display(H);

	deleteMin(H);
	printf_s("\nH(deleteMin): MaxNodes=%d\n", H->MaxNodes);
	display(H);

	makeEmpty(H1);
	makeEmpty(H2);
	return 0;
}