# include <stdio.h>
int main(void)
{
	int n, flag = 1;
	n = 2;
	do{
		if(n % 8 == 2 && n % 9 == 3 && n % 10 == 4){
			printf("%d", n);
			flag = 0;	
		}else
			n += 2;
	}while(flag); // ���ر�����ʹ�ñ�����break�ƻ�����ṹ�ı׶� 
	
	return 0;
}
