#include <stdio.h>
#include <stdlib.h>
#define MINDATA -1

typedef int ElementType;
typedef int Index;
typedef struct HeapNode *PriorityQueue;

PriorityQueue initialiaze(int capacity);
void insert(ElementType key, PriorityQueue H);
void delete(ElementType key, PriorityQueue H);
Index findMin(PriorityQueue H);
Index find(ElementType key, PriorityQueue H);
void deleteMin(PriorityQueue H);
void delete(ElementType key, PriorityQueue H);
void decreaseKey(ElementType key, ElementType d, PriorityQueue H);
void increaseKey(ElementType key, ElementType d, PriorityQueue H);
void display(PriorityQueue H);
void makeEmpty(PriorityQueue H);
int isFull(PriorityQueue H);
int isEmpty(PriorityQueue H);

struct HeapNode {
	int capacity;
	int size;
	ElementType *Arrays;
};

PriorityQueue initialiaze(int capacity) {
	PriorityQueue H;

	H = (PriorityQueue)malloc(sizeof(struct HeapNode));
	if (H != NULL) {
		H->capacity = capacity;
		H->size = 0;

		H->Arrays = (ElementType *)malloc(sizeof(ElementType) * (capacity + 1));
		if (H->Arrays != NULL)
			H->Arrays[0] = MINDATA;
	}

	return H;
}

void insert(ElementType key, PriorityQueue H) {
	int i;

	if (isFull(H)) {
		printf_s("Priority queue is full");
		return;
	}

	/* 只要父节点大于key就要一直上滤，直到父节点小于或等于key
	才满足性质，才定位到了正确的插入位置 */
	for (i = ++H->size; H->Arrays[i / 2] > key; i /= 2)
		H->Arrays[i] = H->Arrays[i / 2];
	H->Arrays[i] = key;
}

Index findMin(PriorityQueue H) {
	if (!isEmpty(H))
		return 1;
	else
		return 0;
}

Index find(ElementType key, PriorityQueue H) {
	int i;

	for (i = 1;i <= H->size;i++) {
		if (H->Arrays[i] == key)
			return i;
	}
	return 0;
}

void deleteMin(PriorityQueue H) {
	int i, child;
	ElementType min, last;

	if (isEmpty(H)) {
		printf_s("Priority queue is empty");
		return;
	}
	min = H->Arrays[1];
	last = H->Arrays[H->size--];

	for (i = 1;i * 2 <= H->size;i = child) {
		/* Find smaller child */
		child = i * 2;
		if (child <= H->size && H->Arrays[child + 1] < H->Arrays[child])
			child++;

		if (child <= H->size && last > H->Arrays[child])
			H->Arrays[i] = H->Arrays[child]; /* 用子节点替换父节点 */
		else
			break;
		/* 循环结束后要用last替换i处的节点，如果i的父节点大于last将不满足条件
		因此在用子节点替换父节点时须保证last大于子节点，这样，当i指向其
		子节点并退出循环后，该位置被last替换，从而确保了i节点（其值等于last）
		大于等于其父节点 */
	}
	H->Arrays[i] = last;
}

void delete(ElementType key, PriorityQueue H) {
	Index index;
	ElementType last;
	int i, child;

	index = find(key, H);
	if (index != 0) {
		last = H->Arrays[H->size--];

		for (i = index;i * 2 <= H->size;i = child) {
			child = i * 2;
			if (child <= H->size && H->Arrays[child + 1] < H->Arrays[child])
				child++;

			if (child <= H->size && last >= H->Arrays[child])
				H->Arrays[i] = H->Arrays[child];
			else
				break;
		}
		H->Arrays[i] = last;
	}
}

void decreaseKey(ElementType key, ElementType d, PriorityQueue H) {
	Index index;
	int i, temp;

	index = find(key, H);
	if (index != 0) {
		H->Arrays[index] -= d;

		for (i = index;i >= 1;i /= 2) {
			if (H->Arrays[i / 2] > H->Arrays[i]) {
				temp = H->Arrays[i / 2];
				H->Arrays[i / 2] = H->Arrays[i];
				H->Arrays[i] = temp;
			}
		}
	}
}

void increaseKey(ElementType key, ElementType d, PriorityQueue H) {
	Index index, child;
	int i, temp;

	index = find(key, H);
	if (index != 0) {
		H->Arrays[index] += d;

		for (i = index;i * 2 <= H->size;i = child) {
			child = i * 2;
			/* Find the smaller child */
			if (child <= H->size && H->Arrays[child + 1] < H->Arrays[child])
				child++;

			if (H->Arrays[i] > H->Arrays[child]) {
				temp = H->Arrays[i];
				H->Arrays[i] = H->Arrays[child];
				H->Arrays[child] = temp;
			}
		}
	}
}

void display(PriorityQueue H) {
	int i;
	if (!isEmpty(H)) {
		for (i = 1;i <= H->size;i++)
			printf_s("%d ", H->Arrays[i]);
	}
}

void makeEmpty(PriorityQueue H) {
	if (!isEmpty(H)) {
		free(H->Arrays);
		free(H);
	}
}

int isFull(PriorityQueue H) {
	return H->capacity == H->size;
}

int isEmpty(PriorityQueue H) {
	return H->size == 0;
}

int main() {
	PriorityQueue H;
	int i, capacity;

	capacity = 10;
	int inData[10] = { 13,14,16,19,21,19,68,65,26,32 };
	H = initialiaze(capacity);
	for (i = 0;i < capacity;i++) {
		//printf_s("#%d: ", i + 1);
		//scanf_s("%d", &inData);
		insert(inData[i], H);
	}
	printf_s("\n");
	display(H);
	
	printf_s("\n");
	//delete(14, H);
	decreaseKey(26, 15, H);
	//increaseKey(14, 6, H);
	display(H);

	makeEmpty(H);
	return 0;
}