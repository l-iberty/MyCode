#include <stdio.h>

int main() {
	int numList[100];
	int i, j;

	for (i = 0;i < 100;i++)
		numList[i] = 1;

	for (j = 2; j <= sqrt(100); j++) {
		for (i = j; i*j < 100; i++)
			numList[i*j] = 0;
	}

	for (i = 2; i < 100; i++)
		if (numList[i] == 1)
			printf_s("%d ", i);

	return 0;
}