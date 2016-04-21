#include <stdio.h>
#include "user.h"

int main()
{
	int i, j;
	char line[] = "abcdeccfgc";
	char ch = 'c';
	
	printf("%s\n", strdel(line, ch));

	return 0;
}