# include<stdio.h>
int main(void)
{
	int m, n, r, a, b;
	scanf("%d %d", &m, &n);
	a = m;
	b = n;
	
	do{
		r = m % n;
		m = n;
		n = r;
	}while(r);
	
	printf("\n%d\t%d", m, a*b/m);
	
	return 0;
}
