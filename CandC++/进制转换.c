# include <stdio.h>

int main(void){
	char base[] = "0123456789ABCDEF";
	int tmp[50];
	int m, n, b;
	int i = 0, j;
	
	puts("����ʮ��������:");
	scanf("%d", &m);
	puts("������ƻ���:");
	scanf("%d", &b);
	
	while(m != 0){
		tmp[i++] = m % b;
		m /= b;
	}
	
	puts("ת�����:");
	for(i--; i >= 0; i--){
		j = tmp[i];
		printf("%c", base[j]);
	}
	
	return 0;
} 
