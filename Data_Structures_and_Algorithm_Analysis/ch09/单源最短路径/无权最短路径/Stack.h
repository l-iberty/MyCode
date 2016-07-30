#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
typedef Vertex ElementType;
typedef struct StackDemo *Stack;

Stack createStack();
void push(ElementType inData, Stack S);
void pop(Stack S);
ElementType top(Stack S);
void disposeStack(Stack S);
int isStackEmpty(Stack S);

struct StackDemo {
	ElementType data;
	struct StackDemo *next;
};


Stack createStack() {
	Stack S = NULL;
	S = (Stack)malloc(sizeof(struct StackDemo));
	if (S == NULL) {
		printf_s("Error");
		return S;
	}
	S->next = NULL;
	return S;
}

void push(ElementType inData, Stack S) {
	Stack newElement, tmp;
	tmp = S;
	newElement = (Stack)malloc(sizeof(struct StackDemo));

	if (newElement == NULL) {
		printf_s("Error\n");
		return;
	}
	newElement->data = inData;
	newElement->next = S->next;
	S->next = newElement;
}

void pop(Stack S) {
	Stack tmp;

	if (!isStackEmpty(S)) {
		tmp = S->next;
		S->next = S->next->next;
		free(tmp);
	}
}

ElementType top(Stack S) {
	if (!isStackEmpty(S))
		return S->next->data;
	else
		return 0;
}

void disposeStack(Stack S) {
	Stack P, AfterP;

	P = S;
	while (P != NULL) {
		AfterP = P->next;
		free(P);
		P = AfterP;
	}
}

int isStackEmpty(Stack S) {
	return S->next == NULL;
}