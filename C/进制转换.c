# include <stdio.h>

int main(void){
	char base[] = "0123456789ABCDEF";
	int tmp[50];
	int m, n, b;
	int i = 0, j;
	
	puts("输入十进制整数:");
	scanf("%d", &m);
	puts("输入进制基数:");
	scanf("%d", &b);
	
	while(m != 0){
		tmp[i++] = m % b;
		m /= b;
	}
	
	puts("转换结果:");
	for(i--; i >= 0; i--){
		j = tmp[i];
		printf("%c", base[j]);
	}
	
	return 0;
} 
