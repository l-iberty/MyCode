#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ElementType;
typedef struct ListNode *List;
typedef struct HashTbl *HashTable;

int hash(ElementType key);
HashTable initializeTable(int tableSize);
List find(ElementType key, HashTable H);
void insert(ElementType inData, HashTable H);
void display(HashTable H);
void makeEmpty(HashTable H);
int nextPrime(int x);
int isPrime(int x);

struct ListNode {
	ElementType data;
	List next;
};

struct HashTbl {
	int tableSize;
	List *ListPtr;
};

int hash(ElementType key) {
	return key % 10;
}

HashTable initializeTable(int tableSize) {
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H != NULL) {
		H->tableSize = nextPrime(tableSize);
		
		H->ListPtr = (List *)malloc(sizeof(List) * H->tableSize);
		if (H->ListPtr != NULL)
			for (i = 0;i < H->tableSize;i++)
				H->ListPtr[i] = NULL;
	}
	
	return H;
}

List find(ElementType key, HashTable H) {
	List P;

	P = H->ListPtr[hash(key)];
	while (P != NULL && P->data != key)
		P = P->next;
	return P;
}

void insert(ElementType inData, HashTable H) {
	List NewNode, L;
	
	if (find(inData, H) == NULL) {
		NewNode = (List)malloc(sizeof(struct ListNode));
		
		if (NewNode != NULL) {
			L = H->ListPtr[hash(inData)];
			NewNode->data = inData;
			NewNode->next = L;
			H->ListPtr[hash(inData)] = NewNode;
		}
	}
}

void display(HashTable H) {
	List L;
	int i;

	if (H != NULL) {
		for (i = 0;i < H->tableSize;i++) {
			L = H->ListPtr[i];
			printf_s("#%d\t", i);
			while (L != NULL) {
				printf_s("%d ", L->data);
				L = L->next;
			}
			printf_s("\n");
		}
	}
}

void makeEmpty(HashTable H) {
	List L, PrevL;
	int i;

	if (H != NULL) {
		/* 清空链表 */
		for (i = 0;i < H->tableSize;i++) {
			L = PrevL = H->ListPtr[i];
			while (L != NULL) {
				L = L->next;
				free(PrevL);
				PrevL = L;
			}
		}
		/* 清空指针数组ListPtr */
		if (H->ListPtr != NULL)
			free(H->ListPtr);
		/* 清空结构体 */
		free(H);
	}
}

int nextPrime(int x) {
	while (1) {
		if (isPrime(x))
			return x;
		else
			x++;
	}
}

int isPrime(int x) {
	int i;

	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	HashTable H;
	int tableSize, i, inData;

	printf_s("tableSize=? ");
	scanf_s("%d", &tableSize);
	H = initializeTable(tableSize);

	for (i = 0;i < 10;i++) {
		printf_s("#%d inData=? ", i + 1);
		scanf_s("%d", &inData);
		insert(inData, H);
	}
	printf_s("\nHash Table:\n");
	display(H);
	makeEmpty(H);

	return 0;
}