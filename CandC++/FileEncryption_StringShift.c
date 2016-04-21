#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(const char *password, const char *filename);
void decrypt(const char *password, const char *filename);

int main()
{
	char password[] = "uestc";
	encrypt(password, "data.txt");
	decrypt(password, "EncryptedFile.txt");

	return 0;
}

void encrypt(const char *password, const char *filename)
{
	FILE *in, *out;
	int ch;
	int i = 0;
	int length = strlen(password);

	if ((in = fopen(filename, "rb")) == NULL ||
		(out = fopen("EncryptedFile.txt", "wb")) == NULL) {
		fprintf(stderr, "File operation error!\n");
		exit(0);
	}

	while (!feof(in)) {
		ch = fgetc(in);

		if (i > length - 1)
			i = 0;

		ch += password[i++];
		fputc(ch, out);
	}
	fclose(in);
	fclose(out);
}

void decrypt(const char *password, const char *filename)
{
	FILE *in, *out;
	int ch;
	int i = 0;
	int length = strlen(password);

	if ((in = fopen(filename, "rb")) == NULL ||
		(out = fopen("DecryptedFile.txt", "wb")) == NULL) {
		fprintf(stderr, "File operation error!\n");
		exit(0);
	}

	while (!feof(in)) {
		ch = fgetc(in);

		if (i > length - 1)
			i = 0;

		ch -= password[i++];
		fputc(ch, out);
	}
	fclose(in);
	fclose(out);
}
