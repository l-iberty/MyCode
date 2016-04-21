#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *in, *out;
	int ch, count;
	char filename[] = "data.txt";

	if ((in = fopen(filename, "r")) == NULL ||
		(out = fopen("tmp.txt","w")) == NULL ) {
		fprintf(stderr, "error");
		exit(1);
	}

	while (!feof(in)) {
		count = 0;
		while((ch = fgetc(in)) == '\n')
			count++;
			
		if(count > 0)
			fputc('\n', out);
			
		fputc(ch, out);
	}
	
	fclose(in);
	fclose(out);

	return 0;
}
