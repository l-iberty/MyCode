/**
 * char *strdel(char *str, const char ch);
 * int str_cmp(const char *str1, const char *str2);
 * char* strcpy(char *dest, const char *source);
 **/
 
char* strdel(char *str, const char ch)
{
	int i, j;

	for (i = j = 0;str[i];i++)
		if (str[i] != ch)
			str[j++] = str[i];
	str[j] = '\0';

	return str;
}

/* 与strcmp()功能相同 */
int str_cmp(const char *str1, const char *str2)
{
	char *ch1, *ch2;

	for (ch1 = str1, ch2 = str2;*ch1 || *ch2;ch1++, ch2++)
	{
		if (*ch1 > *ch2)
			return 1;
		else if (*ch1 < *ch2)
			return -1;
	}
	return 0;
}

/* 针对VS不准我用strcpy()这个问题,我自己实现它 */
char* strcpy(char *dest, const char *source)
{
	char *ch1, *ch2;
	ch1 = dest;
	ch2 = source;

	do{
		*ch1 = *ch2;
		ch1++;
		ch2++;
	} while (*ch2);
	/* 拷贝时包括'\0' */
	return dest;
}