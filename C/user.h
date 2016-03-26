char *strdel(char *str, const char ch)
{
	int i, j;

	for (i = j = 0;str[i];i++)
		if (str[i] != ch)
			str[j++] = str[i];
	str[j] = '\0';

	return str;
}
