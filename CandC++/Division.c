#include <stdio.h>
int main()
{
	int m, n, k, mod, t;
	int i;

	printf("m=?");
	scanf_s("%d", &m);
	printf("n=?");
	scanf_s("%d", &n);
	printf("k=?");
	scanf_s("%d", &k);

	printf("\n(%d) / (%d) = ", m, n);

	if (m * n < 0)
	{
		if (m < 0) m = -m;
		if (n < 0) n = -n;

		printf("-");
	}

	for (i = 0;i < k;i++)
	{
		t = m / n;
		mod = m % n;
		m = mod * 10;
		printf("%d", t);
		if (!i)
			printf(".");
	}

	return 0;
}