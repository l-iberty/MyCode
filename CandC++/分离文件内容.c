#include <stdio.h>
#include <stdlib.h>
#define N 500

int main(int argc, char *argv[])
{
	int i, flag;
	char line[N];
	FILE *fp, *fp1, *fp2;

	if (argc != 4 || (fp = fopen(argv[1], "r")) == NULL || (fp1 = fopen(argv[2], "w")) == NULL
		|| (fp2 = fopen(argv[3], "w")) == NULL) {
		fprintf(stderr, "error");
		exit(1);
	}

	while (!feof(fp)) {
		fgets(line, N, fp);

		if (line[0] == 'Q')
			flag = 1;
		if (line[0] == 'A')
			flag = 2;

		if (flag == 1)
			fputs(line, fp1);
		else if (flag == 2)
			fputs(line, fp2);
	}

	return 0;
}
