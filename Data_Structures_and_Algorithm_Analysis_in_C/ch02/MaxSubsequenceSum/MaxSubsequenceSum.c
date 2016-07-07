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

	for (i = 0; i < length; i++) { // i标记序列的左边界
		for (j = i; j < length; j++) { //j标记序列的有边界
			tmpSum = 0;
			for (k = i; k <= j; k++) //迭代求和
				tmpSum += a[k];
			if (tmpSum > maxSum)
				maxSum = tmpSum;
		}
	}

	/* 第1层循环大小：N */
	/* 第2层循环大小：N-i，取N  */
	/* 第3层循环大小：j-i+1，取N */
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

	/* 最大子序列和问题规定：若所有整数均为负数，
	则最大子序列和为0.因此，对于正负混合的序列，
	若a[i]为负，则它不会是所求序列的起点，该算法
	保证对序列的求和一定开始于整数. */

	return maxSum;
}