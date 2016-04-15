#include <stdio.h>
#include <stdlib.h>

int main()
{
	int up[26] = { 0 }, low[26] = { 0 }, letter, sum = 0, other = 0;
	int i;
	char filename[] = "data.txt";
	int ch;
	FILE *fp;

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "error");
		exit(0);
	}

	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch >= 'a'&&ch <= 'z')
			low[ch - 'a']++;
		else if (ch >= 'A'&&ch <= 'Z')
			up[ch - 'A']++;
		else
			other++;

		sum++;
	}
	fclose(fp);
	letter = sum - other;

	for (i = 0;i < 26;i++) {
		printf("%c--%d ",i+97,low[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\n\n");
	for (i = 0;i < 26;i++) {
		printf("%c--%d ", i + 65, up[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	printf("\n\nOther--%d", other-1);
	printf("\nSum--%d\n", sum-1);
	/* 文本文件有一个结束符EOF,要除去之 */

	return 0;
}
