#include <stdio.h>
int maxSubsequenceSum_1(int a[], int length); /* O(N^3) */
int maxSubsequenceSum_2(int a[], int length); /* O(N^2) */
int maxSubsequenceSum_4(int a[], int length); /* O(N) */

int main() {
	int a[] = { -2,11,-4,13,-5,-2 };
	int length = 6;

	printf_s("%d\n", maxSubsequenceSum_2(a, length));

	return 0;
}

int maxSubsequenceSum_1(int a[], int length) {
	int i, j, k, tmpSum, maxSum = 0;

	for (i = 0; i < length; i++) { // i������е���߽�
		for (j = i; j < length; j++) { //j������е��б߽�
			tmpSum = 0;
			for (k = i; k <= j; k++) //�������
				tmpSum += a[k];
			if (tmpSum > maxSum)
				maxSum = tmpSum;
		}
	}

	/* ��1��ѭ����С��N */
	/* ��2��ѭ����С��N-i��ȡN  */
	/* ��3��ѭ����С��j-i+1��ȡN */
	return maxSum;
}

int maxSubsequenceSum_2(int a[], int length) {
	int i, j, tmpSum, maxSum = 0;

	for (i = 0; i < length; i++) {
		for (j = i, tmpSum = 0; j < length; j++) {
			tmpSum += a[j];
			if (tmpSum > maxSum)
				maxSum = tmpSum;
		}
		
	}
	return maxSum;
}

int maxSubsequenceSum_4(int a[], int length) {
	int i, tmpSum = 0, maxSum = 0;
	
	for (i = 0; i < length; i++) {
		tmpSum += a[i];
		if (tmpSum > maxSum)
			maxSum = tmpSum;
		else if (tmpSum < 0)
			tmpSum = 0;
	}

	/* ��������к�����涨��������������Ϊ������
	����������к�Ϊ0.��ˣ�����������ϵ����У�
	��a[i]Ϊ���������������������е���㣬���㷨
	��֤�����е����һ����ʼ������. */

	return maxSum;
}