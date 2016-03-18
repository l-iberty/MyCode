# include <stdio.h>
# define N 5

int f(int t);

int main(void)
{
	int i,j,k,a[N],s[N],tmp[N];
	long m,n;
	printf("n=? ");
	scanf("%ld", &n);
	m = n;
	
	do{
		// 内层do-while取出各位数
		i = 0;
		do{
			a[i++] = n % 10;
			n /= 10;
		}while(n);
		
		// for处理各位数
		for(i--,j = 0,k = 0; j < N; j++,i--)
		{
			s[j] = 2 * a[i];
			tmp[j] = f(s[j]); // 易错点：没用tmp[]临时储存上一步的a[]的2倍处理结果,直接用a[] 
			k = k * 10 + tmp[j];
		}
		n = k; // 易错点：遗漏该语句 
		printf("%d ", k);
	}while(k != m);
	
	return 0;
}

int f(int t) // 参数是经过2倍处理的 
{
	int i, b[2] = {0}; 
	i = 0;
	do{
		b[i++] = t % 10;
		t /= 10;
	}while(t);
	
	t = b[0] + b[1];
	return t;
}
