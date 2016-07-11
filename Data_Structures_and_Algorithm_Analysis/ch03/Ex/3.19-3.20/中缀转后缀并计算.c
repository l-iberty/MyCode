#include <stdio.h>
#include <stdlib.h>

typedef struct demo* Stack;

Stack createStack(void);
int isEmpty(Stack S);
void pushChar(char inCh, Stack S);
void pushInt(int inInte, Stack S);
void pop(Stack S);
char topChar(Stack S);
int topInt(Stack S);
void disposeStack(Stack S);
int pricmp(char c1, char c2);
int isSymbol(char c);

struct demo {
	char ch;
	int inte;
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

void pushChar(char inCh, Stack S) {
	Stack newElement, tmp;
	tmp = S;
	newElement = (Stack)malloc(sizeof(struct demo));

	if (newElement == NULL) {
		printf_s("Error\n");
		return;
	}
	newElement->ch = inCh;
	newElement->next = S->next;
	S->next = newElement;
}

void pushInt(int inInte, Stack S) {
	Stack newElement, tmp;
	tmp = S;
	newElement = (Stack)malloc(sizeof(struct demo));

	if (newElement == NULL) {
		printf_s("Error\n");
		return;
	}
	newElement->inte = inInte;
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

char topChar(Stack S) {
	if (!isEmpty(S))
		return S->next->ch;
	else {
		printf_s("\n(Top failed: Empty Stack!\n");
	}
	return 0;
}

int topInt(Stack S) {
	if (!isEmpty(S))
		return S->next->inte;
	else {
		printf_s("\n(Top failed: Empty Stack!\n");
	}
	return 0;
}

void disposeStack(Stack S) {
	if (isEmpty(S)) {
		free(S);
		printf("\nStack Disposed\n");
	}
	else
		printf("\nNot Empty Stack\n");
}

int pricmp(char c1, char c2) {
	if (c1 == '(')
		return 1;
	else if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/'))
		return -1;
	else if ((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-'))
		return 1;
	else if (c2 == '(')
		return 1;
	else
		return 0;
}

int isSymbol(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '(' || c == ')')
		return 1;
	else
		return 0;
}

int main()
{
	int i, j, len, a, b;
	char *src = "6*(5+(2+3)*8+3)";
	char des[255];
	Stack S;

	S = createStack();
	if (S == NULL) {
		printf_s("Error\n");
		return 1;
	}

	i = len = 0;
	while (src[i++] != '\0')
		len++;

	/* 将中缀转换为后缀 */
	for (i = j = 0; i < len; i++) {
		if (isSymbol(src[i])) {
			if (src[i] != ')') {
				if (isEmpty(S))
					pushChar(src[i], S);
				else if (pricmp(src[i], topChar(S)) > 0)
					pushChar(src[i], S);                      
				else {
					while (!isEmpty(S) && pricmp(src[i], topChar(S)) <= 0) {
						des[j++] = topChar(S);
						pop(S);
					}
					pushChar(src[i], S);
				}
			}
			else if (src[i] == ')') {
				while (topChar(S) != '(' && !isEmpty(S)) {
					des[j++] = topChar(S);
					pop(S);
				}
				pop(S);
			}
		}
		else {
			des[j++] = src[i];
		}
	}
	/* 将栈里的剩余符号弹出 */
	while (!isEmpty(S)) {
		des[j++] = topChar(S);
		pop(S);
	}
	des[j--] = '\0';
	printf("%s\n", des);
	/* 转换结束 */
	
	/* 用后缀表达式完成计算 */
	i = len = 0;
	while (des[i++] != '\0')
		len++;

	for (i = 0; i < len; i++) {
		if (!isSymbol(des[i]))
			pushInt(des[i] - 48, S);
		else {
			a = topInt(S);
			pop(S);
			b = topInt(S);
			pop(S);
			//printf_s("\na=%d, b=%d\n", a, b);
			switch (des[i]) {
			case '+':
				pushInt(a + b, S);
				break;
			case '-':
				pushInt(a - b, S);
				break;
			case '*':
				pushInt(a*b, S);
				break;
			case '/':
				pushInt(a / b, S);
				break;
			}
		}
	}
	printf_s("Result=%d\n", topInt(S));
	return 0;
}