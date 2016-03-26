#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intTrans(long m, int k, char *msg);
char* doubleTrans(double m, int k, char *msg);

int main()
{
	double a;
	int b;
	char *msg = (char *)malloc(100*sizeof(char));
	printf("十进制数:");
	scanf("%lf", &a);
	printf("进制基数:");
	scanf("%d", &b);

	printf("转换结果:");
	doubleTrans(a, b, msg);
	printf("%s", msg);

	free(msg);
	return 0;
}

char* intTrans(long m, int k, char *msg)
{
	/* <1> 使用该函数要包含string.h和stdilb.h头文件 */
	/* <2> 参数含义:m--十进制整数;n--进制基数;msg--转换结果,传递前要分配内存空间 */
	/* <3> 返回类型:返回msg */
	
	int t, i, j, n, tmp;
	char base[] = "0123456789ABCDEF";
	char result[50];

	i = 0;
	do {
		t = m % k;
		result[i++] = base[t];
		m = m / k;
	} while (m);

	for (j = 0, n = i--;j <= i / 2;j++, i--)
	{
		tmp = result[i];
		result[i] = result[j];
		result[j] = tmp;
	}

	result[n] = '\0';
	
	/* return result;会出错原因是,result是函数内定义的
	   局部指针变量,函数调用完毕后它将从堆栈中被销毁,
	   使得主调函数main()无法获得result指向的内容,因为
	   这些内容已经不复存在.*/
	
	strcpy(msg, result);
	return msg;
}

char* doubleTrans(double m, int k, char *msg)
{
	int t, i;
	int r = 10; // 保留5位小数
	long intPart = (long)m;
	double floatPart = m - intPart;
	intTrans(intPart, k, msg);
	char base[] = "0123456789ABCDEF";
	char result[50];
	
	i = 0;
	do {
		t = (int)(floatPart * k);
		result[i++] = base[t];
		floatPart = floatPart * k - t;
	} while (i < r);
	
	result[r] = '\0';
	strcat(msg, ".");
	strcat(msg, result);
	return msg;
}
