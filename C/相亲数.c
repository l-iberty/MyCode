# include <stdio.h>
# define N 30000

int main(void){
	int i,j,k,s[N];
	
	for(i = 2; i < N; i++){
		for(j = 1, s[i] = 0; j < i; j++){
			if(i % j == 0)
				s[i] += j; // ÿ���±��Ӧһ����������֮��,����������ʵ�� 
		}
	}
	
	for(i = 2; i < N; i++){
		// ����ÿһ��i,��Ҫ��j����һ��ɨ��,�Ա���ȫ��j 
		for(j = i+1; j < N; j++){ //��ȡΪ j = i,��ͬʱ������� 
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
