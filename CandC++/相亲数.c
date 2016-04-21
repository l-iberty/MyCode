# include <stdio.h>
# define N 30000

int main(void){
	int i,j,k,s[N];
	
	for(i = 2; i < N; i++){
		for(j = 1, s[i] = 0; j < i; j++){
			if(i % j == 0)
				s[i] += j; // 每个下标对应一个数的因子之和,检索更容易实现 
		}
	}
	
	for(i = 2; i < N; i++){
		// 对于每一个i,都要在j中做一次扫描,以遍历全体j 
		for(j = i+1; j < N; j++){ //若取为 j = i,将同时获得完数 
			if(i == s[j] && j == s[i]){
				printf("%d: ", i);
				for(k = 1; k < i; k++)
					if(i % k == 0)
						printf("%d ", k);
				printf("\n");
				
				printf("%d: ", j);
				for(k = 1; k < j; k++)
					if(j % k == 0)
						printf("%d ", k);
				printf("\n");
				
				printf("\n\n");
			}
		}
	}
}
