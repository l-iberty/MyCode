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
	printf("ʮ������:");
	scanf("%lf", &a);
	printf("���ƻ���:");
	scanf("%d", &b);

	printf("ת�����:");
	doubleTrans(a, b, msg);
	printf("%s", msg);

	free(msg);
	return 0;
}

char* intTrans(long m, int k, char *msg)
{
	/* <1> ʹ�øú���Ҫ����string.h��stdilb.hͷ�ļ� */
	/* <2> ��������:m--ʮ��������;n--���ƻ���;msg--ת�����,����ǰҪ�����ڴ�ռ� */
	/* <3> ��������:����msg */
	
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
	
	/* return result;�����ԭ����,result�Ǻ����ڶ����
	   �ֲ�ָ�����,����������Ϻ������Ӷ�ջ�б�����,
	   ʹ����������main()�޷����resultָ�������,��Ϊ
	   ��Щ�����Ѿ���������.*/
	
	strcpy(msg, result);
	return msg;
}

char* doubleTrans(double m, int k, char *msg)
{
	int t, i;
	int r = 10; // ����5λС��
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
