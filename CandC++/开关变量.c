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
	}while(flag); // 开关变量的使用避免了break破环程序结构的弊端 
	
	return 0;
}
