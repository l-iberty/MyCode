#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* 进行栈操作时只有栈顶元素可见 */

typedef struct demo* Stack;

Stack createStack(void);
int isEmpty(Stack S);
void push(int inData, Stack S);
void pop(Stack S);
int top(Stack S);
void display(Stack S);

struct demo {
	int data;
	struct demo *next;
};

Stack createStack(void) {
	Stack S = NULL;
	S = (Stack)malloc(sizeof(struct demo));
	if (S == NULL) {
		printf_s("Error");
		return S;
	}
	S->next = NULL;
	return S;
}

int isEmpty(Stack S) {
	return S->next == NULL;
}

void push(int inData, Stack S) {
	Stack newElement, tmp;
	tmp = S;
	newElement = (Stack)malloc(sizeof(struct demo));

	if (newElement == NULL) {
		printf_s("Error\n");
		return NULL;
	}
	newElement->data = inData;
	newElement->next = S->next;
	S->next = newElement;
}

void pop(Stack S) {
	Stack tmp;

	if (!isEmpty(S)) {
		tmp = S->next;
		S->next = S->next->next;
		free(tmp);
	}
	else
		printf_s("\n(Pop failed: Empty Stack!\n");
}

int top(Stack S) {
	if (!isEmpty(S))
		return S->next->data;
	else {
		printf_s("\n(Top failed: Empty Stack!\n");
	}
		return 0;
}

void display(Stack S) {
	Stack current = S->next;
	while (current != NULL) {
		printf_s("%d ", current->data);
		current = current->next;
	}
}

int main()
{
	int i, inData;
	Stack S;
	S = createStack();

	if (S == NULL) {
		printf_s("Error\n");
		return 1;
	}
	if (S->next == NULL)
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

	printf_s("\nEventually,is S == NULL? %d", S == NULL);
	printf_s("\nS->next == NULL? %d\n", S->next == NULL);
	return 0;
}
