#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ElementType int
typedef struct StackDemo *Stack;

struct StackDemo
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack createStack(int size);
int isEmpty(Stack S);
int isFull(Stack S);
void push(ElementType x, Stack S);
void pop(Stack S);
ElementType top(Stack S);
void display(Stack S);
void disposeStack(Stack S);

Stack createStack(int size) {
	Stack S;

	S = (Stack)malloc(sizeof(struct StackDemo));
	if (S == NULL) {
		printf_s("Error");
		return NULL;
	}

	S->Array = (ElementType*)malloc(sizeof(ElementType) * size);
	if (S->Array == NULL) {
		printf_s("Error");
		return NULL;
	}
	S->Capacity = size;
	S->TopOfStack = -1;

	return S;
}

int isEmpty(Stack S) {
	return S->TopOfStack == -1;
}

int isFull(Stack S) {
	return S->Capacity == S->TopOfStack + 1;
}

void push(ElementType x, Stack S) {
	if (isFull(S)) {
		printf_s("Full Stack");
		return;
	}
	S->Array[++S->TopOfStack] = x;
}

void pop(Stack S) {
	if (isEmpty(S)) {
		printf_s("Empty Stack");
		return;
	}
	S->TopOfStack--;
}

ElementType top(Stack S) {
	if (isEmpty(S)) {
		printf_s("Empty Stack");
		return -1;
	}
	return S->Array[S->TopOfStack];
}

void display(Stack S) {
	ElementType index;
	index = S->TopOfStack;

	while (index != -1)
		printf("%d ", S->Array[index--]);
}

void disposeStack(Stack S) {
	if (S != NULL) {
		free(S->Array);
		free(S);
		printf_s("Stack Disposed");
	}
}

int main()
{
	int i, inData;
	Stack S;
	S = createStack(5);

	if (S == NULL) {
		printf_s("Error\n");
		return 1;
	}
	if (isEmpty(S))
		printf_s("Empty Stack\n");

	for (i = 0; i < 5; i++) {
		printf_s("\ninData=");
		scanf_s("%d", &inData);
		push(inData, S);
		display(S);
		printf_s(" Top=%d", top(S));
	}

	printf_s("\n\n");
	for (i = 0; i < 6; i++) {
		display(S);
		printf_s(" Top=%d", top(S));

		printf_s("\nPress any key to pop...\n");
		_getch();
		pop(S);
	}

	printf_s("\n%p\n", S);
	disposeStack(S);
	/* 函数只是获得了S的副本，S指向的内存区确实被释放了，
	但S指向的内存地址没变 */
	printf_s("\n%p\n", S);
	return 0;
}
