#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *attachstr(char **args, int num) {
	char *str;
	int i, offset, len;

	for (i = len = offset = 0, str = NULL;i < num;i++) {
		len = strlen(args[i]);
		str = (char *)realloc(str, len + offset + 1);
		*(str + offset) = 0x00;
		strcat(str, args[i]);
		offset += len;

		if ((i + 1) >= num)
			break;
		else
			str = (char *)realloc(str, strlen(args[i + 1]) + offset + 1);
	}

	return str;
}

void main() {
	char *args[] = { "Hello",",","World","!!!","Fuck you" };
	int num = 5;
	char *str = attachstr(args, num);

	printf("%s\n", str);
}