# include <stdio.h>
# define N 3

int main(void){
	long i,j,tmp,n,s,temp,a,b,c[N];
	
	// ȷ����Χ 
	a = 1;
	for(i = 0; i < N-1; i++)
		a *= 10;
		
	b = a * 10;
	
	// ��ȡ����λ��
	for(n = a; n < b; n++){
		tmp = n;
		i = 0;
		
		do{
			c[i++] = tmp % 10;
			tmp /= 10;
		}while(tmp);
	
		// ���ѭ����������Ԫ�� 
		
		//temp = 1;
		//s = 0;
		// ����ѭ����������
		 
		for(i = 0; i < N; i++){
			// �ڲ�ѭ����ÿ��Ԫ�ؽ��������� 
			for(j = 0; j < N; j++){
				temp *= c[i];
			}
			s += temp;
		}
		
		if(n == s)
			printf("%ld ", n);
	}
	
	return 0;
}
