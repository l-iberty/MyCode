# include <stdio.h>

void main()
{
	int a,b,i,k;
	scanf("%d%d", &a, &b);
	
	k = 1;
	for(i = 2; i <= a && i <= b; i++)
	{
		while(a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
			k = k * i;
		}
	}
	
	printf("%d\t%d", k, k*a*b);
}
