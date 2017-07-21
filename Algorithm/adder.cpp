// �������ӷ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFSIZE 100

int main() {
	char s1[BUFSIZE];
	char s2[BUFSIZE];
	int len1, len2;
	char *sum = NULL;
	int maxlen;

	printf("num1=? ");
	scanf("%s", s1);
	printf("num2=? ");
	scanf("%s", s2);

	len1 = strlen(s1);
	len2 = strlen(s2);
	maxlen = (len1 > len2) ? len1 : len2;
	sum = (char *)malloc((maxlen + 1 + 1) * sizeof(char)); // �ַ���ĩβ '\0' һ���ַ�; ���� n λ���ĺ���� n+1 λ��
	if (sum == NULL)
		return 1;

	char *p = (len1 > len2) ? s2 : s1; // p ָ��϶̵��ַ���
	char *s_dump = (char *)malloc((maxlen + 1) * sizeof(char));
	if (s_dump == NULL)
		return 1;
	memset(s_dump, '0', maxlen + 1);
	memcpy(s_dump + abs(len1 - len2), p, strlen(p) + 1); // �ѽ϶��ַ���ת���� s_dump

	char *p1, *p2;
	char *s_maxlen = (len1 > len2) ? s1 : s2;
	int num1, num2, temp;
	int i;
	int carry = 0; // ��λ
	p1 = s_maxlen + maxlen - 1; // p1 ָ��ϳ��ַ�����ĩβ
	p2 = s_dump + maxlen - 1; // p2 ָ�� s_dump ĩβ
	sum[maxlen + 1] = '\0';
	for (i = maxlen; i >= 0 && p1 >= s_maxlen && p2 >= s_dump; p1--, p2--) {
		num1 = *p1 - '0';
		num2 = *p2 - '0';
		temp = ((num1 + num2) % 10 + carry) % 10;
		sum[i--] = temp + '0';
		carry = (num1 + num2 + carry) / 10;
	}
	sum[i] = (carry == 1) ? '1' : ' ';

	printf("\n%s + %s = %s\n", s1, s2, sum);
	free(sum);
	free(s_dump);
}