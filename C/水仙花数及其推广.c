# include <stdio.h>
# define N 3

int main(void){
	long i,j,tmp,n,s,temp,a,b,c[N];
	
	// 确定范围 
	a = 1;
	for(i = 0; i < N-1; i++)
		a *= 10;
		
	b = a * 10;
	
	// 获取各个位数
	for(n = a; n < b; n++){
		tmp = n;
		i = 0;
		
		do{
			c[i++] = tmp % 10;
			tmp /= 10;
		}while(tmp);
	
		// 外层循环遍历数组元素 
		
		//temp = 1;
		//s = 0;
		// 放在循环外面会出错
		 
		for(i = 0; i < N; i++){
			// 内层循环对每个元素进行幂运算 
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
