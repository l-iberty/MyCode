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
		// �ڲ�do-whileȡ����λ��
		i = 0;
		do{
			a[i++] = n % 10;
			n /= 10;
		}while(n);
		
		// for�����λ��
		for(i--,j = 0,k = 0; j < N; j++,i--)
		{
			s[j] = 2 * a[i];
			tmp[j] = f(s[j]); // �״�㣺û��tmp[]��ʱ������һ����a[]��2��������,ֱ����a[] 
			k = k * 10 + tmp[j];
		}
		n = k; // �״�㣺��©����� 
		printf("%d ", k);
	}while(k != m);
	
	return 0;
}

int f(int t) // �����Ǿ���2������� 
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
