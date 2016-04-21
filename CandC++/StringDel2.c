#include <stdio.h>
#include "user.h"

int main()
{
	int flag;
	char str1[] = "javascrip", str2[] = "java";
	char *p_str1, *p_str2;

	for (p_str1 = str1; *p_str1; p_str1++)
		for (flag = 1, p_str2 = str2;*p_str2 && flag;p_str2++)
			if (*p_str1 == *p_str2)
			{
				*p_str1 = '*';
				flag = 0;
			}

	printf("%s", strdel(str1, '*'));
	return 0;
}