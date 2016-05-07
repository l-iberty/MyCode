char *strdel(char *str, const char ch);
int strcmp(const char *str1, const char *str2);
char* strcpy(char *dest, const char *source);
int equals(const char *str1, const char *str2);
void select_sort(int A[], int n);

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
int strcmp(const char *str1, const char *str2)
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

/* 没有考虑内存重叠问题 */
char* strcpy(char *dest, const char *source)
{
	char *ch = dest;
	while((*(dest++) = *(source++)) != '\0');
	/* 拷贝时包括'\0' */
	/** 说明:
	 * dest和source是实参的拷贝,与实参指向同一位置,自增进行时实参没有任何变化,
	 * 自增操作是对实参的读操作,"*source = 'a'"对实参进行写操作,这是不允许的.
	 * 另外在处理返回值时,系统创建临时变量,ch被复制到那儿,注意ch指向形参dest最
	 * 初所指,所以返回的ch是有效的;但若ch指向函数内定义的某个局部变量,返回值就
	 * 无效了.
	 **/
	return ch;
}

/* 实现类似Java中String类的equals()方法的功能 */
int equals(const char *str1, const char *str2)
{	
	while(*str1 == *str2 && *str1 && *str2){
		str1++;
		str2++;
	}
	if(!(*str1) && !(*str2)) // 同时到达行尾字符
		return 1;
	else
		return 0;
}

void select_sort(int A[], int n) {
	int i, j, min, tmp;

	for (i = 0;i < n - 1;i++) {
		min = i;
		/* 找最小值 */
		for (j = i + 1;j < n;j++)
			if (A[j] < A[min])
				min = j;

		if (min != i) {
			tmp = A[min];
			A[min] = A[i];
			A[i] = tmp;
		}
	}
}
