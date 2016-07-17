#include <stdio.h>
#include <stdlib.h>

typedef struct SplayTreeNode *SplayTree;
typedef int ElementType;
static SplayTree NULLNode = NULL;

void makeEmpty(SplayTree T);
SplayTree initializeNULLNode(void);
SplayTree singleRotateWithRight(SplayTree K2);
SplayTree singleRotateWithLeft(SplayTree K2);
SplayTree splay(ElementType Item, SplayTree T);
SplayTree find(ElementType Item, SplayTree T);
SplayTree insertWithSplay(ElementType Item, SplayTree T);
SplayTree insertWithoutSplay(ElementType Item, SplayTree T);
SplayTree delete(ElementType Item, SplayTree T);
void display(SplayTree T);

struct SplayTreeNode {
	ElementType data;
	SplayTree Left;
	SplayTree Right;
};

void makeEmpty(SplayTree T) {
	if (T != NULLNode) {
		makeEmpty(T->Left);
		makeEmpty(T->Right);
		free(T);
	}
}

SplayTree initializeNULLNode(void) {
	if (NULLNode == NULL) {
		NULLNode = (SplayTree)malloc(sizeof(struct SplayTreeNode));
		if (NULLNode != NULL)
			NULLNode->Left = NULLNode->Right = NULLNode;
	}
	return NULLNode;
}

SplayTree singleRotateWithRight(SplayTree K2) {
	SplayTree K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	return K1;
}

SplayTree singleRotateWithLeft(SplayTree K2) {
	SplayTree K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	return K1;
}

SplayTree splay(ElementType Item, SplayTree T) {
	static struct SplayTreeNode Header;
	SplayTree LeftTreeMax, RightTreeMin;

	Header.Left = Header.Right = NULLNode;
	LeftTreeMax = RightTreeMin = &Header;
	NULLNode->data = Item;

	while (Item != T->data) {
		if (Item < T->data) {
			if (Item < T->Left->data)
				T = singleRotateWithLeft(T);
			if (T->Left == NULLNode)
				break;

			RightTreeMin->Left = T;
			RightTreeMin = T;
			T = T->Left;
		}
		else {
			if (Item > T->Right -> data)
				T = singleRotateWithRight(T);
			if (T->Right == NULLNode)
				break;

			LeftTreeMax->Right = T;
			LeftTreeMax = T;
			T = T->Right;
		}
	}

	LeftTreeMax->Right = T->Left;
	RightTreeMin->Left = T->Right;
	T->Left = Header.Right;
	T->Right = Header.Left;

	return T;
}

SplayTree find(ElementType Item, SplayTree T) {
	return splay(Item, T);
}

SplayTree insertWithSplay(ElementType Item, SplayTree T) {
	static SplayTree NewNode = NULL;

	if (NewNode == NULL) {
		NewNode = (SplayTree)malloc(sizeof(struct SplayTreeNode));
		if (NewNode != NULL)
			NewNode->data = Item;
	}

	if (T == NULLNode) {
		NewNode->Left = NewNode->Right = NULLNode;
		T = NewNode;
	}
	else {
		T = splay(Item, T);
		if (Item < T->data) {
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = NULLNode;
			T = NewNode;
		}
		else if (Item > T->data) {
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = NULLNode;
			T = NewNode;
		}
		else /* Item is already in the tree */
			return T;
	}

	NewNode = NULL;
	return T;
}

SplayTree insertWithoutSplay(ElementType Item, SplayTree T) {
	if (T == NULLNode) {
		T = (SplayTree)malloc(sizeof(struct SplayTreeNode));
		if (T != NULL) {
			T->Left = T->Right = NULLNode;
			T->data = Item;
		}
	}
	else if (Item < T->data)
		T->Left = insertWithoutSplay(Item, T->Left);
	else if (Item > T->data)
		T->Right = insertWithoutSplay(Item, T->Right);

	return T;
}

SplayTree delete(ElementType Item, SplayTree T) {
	SplayTree NewRoot = NULLNode;

	if (T != NULLNode) {
		T = splay(Item, T);
		if (Item == T->data) {
			if (T->Left == NULLNode)
				NewRoot = T->Right;
			else {
				NewRoot = T->Left;
				NewRoot = splay(Item, NewRoot);
				NewRoot->Right = T->Right;
			}
			free(T);
			T = NewRoot;
		}
	}

	return T;
}

void display(SplayTree T) {
	if (T != NULLNode) {
		display(T->Left);
		printf_s("%d ", T->data);
		display(T->Right);
	}
}

int main() {
	SplayTree T;
	int i;
	int inData[] = { 12,5,25,20,30,15,24,13,18,16 };

	NULLNode = initializeNULLNode();
	T = NULLNode;
	for (i = 0; i < 10; i++)
		T = insertWithoutSplay(inData[i], T);
	// T = insertWithoutSplay(inData[i], T);
	// 不同的插入方式

	printf_s("Tree: ");
	display(T);
	printf_s("\nRoot: %d\n", T->data);

	printf_s("\nFind 19...");
	T = find(19, T);
	printf_s("\nRoot: %d\n", T->data);

	printf_s("\nDelete 18...");
	T = delete(18, T);
	printf_s("\nRoot: %d\n", T->data);
	display(T);

	makeEmpty(T);
	return 0;
}