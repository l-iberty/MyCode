# include <stdio.h>

int main(void){
	int x, y, z;
	x = 13;
	y = 25;
	z = 0;
	x = x && y || z; // 优先级：&& > || 
	printf("%d\n", x);
	printf("%d\n", x || !y && z);  
	x = 013; // 前面加0表示这是八进制数 
	y = 025;
	z = 01;
	printf("(1)%d\n", x|y&z);
	printf("(2)%d\n", x|y&~z);
	printf("(3)%d\n", x^y&~z); // 优先级：& > ^ > | 
	x = 1;
	y = -1;
	x = x<<3;
	printf("%d\n", x);
	y <<= 3;
	printf("%d\n", y);
	return 0;
}
