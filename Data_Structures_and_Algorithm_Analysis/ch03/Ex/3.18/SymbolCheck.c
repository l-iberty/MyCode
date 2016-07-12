#include <stdio.h>
#include <stdlib.h>

typedef struct demo* Stack;

Stack createStack(void);
int isEmpty(Stack S);
void push(char inData, Stack S);
void pop(Stack S);
char top(Stack S);
void display(Stack S);

int isOpen(char ch);
int isClosed(char ch);
int isCorrosponding(char ch1, char ch2);

struct demo {
	char data;
	struct demo *next;
};

int isOpen(char ch) {
	if (ch == '(' || ch == '[' || ch == '{')
		return 1;
	else
		return 0;
}

int isClosed(char ch) {
	if (ch == ')' || ch == ']' || ch == '}')
		return 1;
	else
		return 0;
}

int isCorrosponding(char ch1, char ch2) {
	if ((ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']')
		|| (ch1 == '{' && ch2 == '}'))
		return 1;
	else
		return 0;
}

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

void push(char inData, Stack S) {
	Stack newElement, tmp;
	tmp = S;
	newElement = (Stack)malloc(sizeof(struct demo));

	if (newElement == NULL) {
		printf_s("Push Error\n");
		return;
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

char top(Stack S) {
	if (!isEmpty(S))
		return S->next->data;
	else {
		printf_s("\n(Top failed: Empty Stack!\n");
	}
	return 0;
}

void display(Stack S) {
	if (!isEmpty(S)) {
		Stack current = S->next;
		while (current != NULL) {
			printf_s("%c ", current->data);
			current = current->next;
		}
	}
	else
		printf_s("Empty Stack\n");
}

int main() {
	Stack S = createStack();
	char *msg = "a{b[c[def(ghijkl)m]]n};";
	char sym;

	while (*msg != '\0') {
		if (isOpen(*msg))
			push(*msg, S);
		else if (isClosed(*msg)) {
			if (isEmpty(S))
				printf_s("Error-1\n");
			else {
				sym = top(S);
				pop(S);
				if (!isCorrosponding(sym,*msg))
					printf_s("Error-2\n");
			}
		}
		msg++;
	}

	if (!isEmpty(S))
		printf_s("Error-3\n");
	else
		printf_s("Correct\n");

	display(S);
	return 0;
}
