# include <stdio.h>

int main(void){
	unsigned int k;
	int i, j, count = 0;
	
	scanf("%u", &k);
	
	// 转换32位二进制数 
	for(i = 31; i >= 0; i--){
		j = ( k >> i ) & 1;
		printf("%d", j);
		
		count++;
		if(count % 4 == 0)
			printf(" ");
	}
	
	return 0;
}
