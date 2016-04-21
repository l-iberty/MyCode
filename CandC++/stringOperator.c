# include <stdio.h>
int main(void)
{
	char s1[] = "java";
	char s2[] = "python";
	int i = 0;
	int j = 0;
	
	while(s1[i] != '\0') i++;
	printf("%d", i);
	
	return 0;
}
