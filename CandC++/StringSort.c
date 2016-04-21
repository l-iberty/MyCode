#include <stdio.h>
#define SIZE 20

void exchange(char *ch1, char *ch2);
int charcmp(const char ch1, const char ch2);

int main()
{
	int i, j;
	char str[SIZE], *p;
	printf("Enter a string: ");
	gets(str);

	for (i = 1;i < SIZE;i++)
		for (j = 0, p = &str[j];j < SIZE - i && *(p+1);j++,p++)
			/* 遇到'\0'就需停止了 */
			if (charcmp(*p, *(p+1)) > 0)
				exchange(p, p+1);

	puts(str);
	return 0;
}

int charcmp(const char ch1, const char ch2)
{
	if (ch1 > ch2)
		return 1;
	else if (ch1 < ch2)
		return -1;
	else
		return 0;
}

void exchange(char *ch1, char *ch2)
{
	/* 必须传地址 */
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}