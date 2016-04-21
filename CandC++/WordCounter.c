#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	long offset = 0;
	char filename[] = "data.txt";
	char word[] = " the ";
	int len = strlen(word);
	int count = 0;
	char *buff;

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "error");
		exit(1);
	}

	while (!feof(fp)) {
		buff = (char *)malloc(sizeof(word) - 1);

		fseek(fp, offset++, SEEK_SET);
		fgets(buff, len, fp); // fgets()读取的字符数包括\0, 故"len+1"

		if (!strcmp(word, buff))
			count++;

		free(buff);
	}

	printf("count--%d\n", count);
	return 0;
}
