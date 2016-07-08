#include<iostream>
using namespace std;

int minSubsequenceSum(int a[], int length) {
	int i, tmpSum = 0, minSum = 0;

	for (i = 0; i < length; i++) {
		tmpSum += a[i];
		if (tmpSum < minSum)
			minSum = tmpSum;
		else if (tmpSum > 0)
			tmpSum = 0;
	}

	/* 最小子序列和问题规定：若所有整数均为正数，
	则最小子序列和为0.因此，对于正负混合的序列，
	若a[i]为正，则它不会是所求序列的起点，该算法
	保证对序列的求和一定开始于负数. */

	return minSum;
}

int main() {
	int a[] = { -2,-11,10,-13,-5,2 };
	int length = 6;

	cout << minSubsequenceSum(a, length) << endl;

	return 0;
}