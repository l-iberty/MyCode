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

	/* ��С�����к�����涨��������������Ϊ������
	����С�����к�Ϊ0.��ˣ�����������ϵ����У�
	��a[i]Ϊ���������������������е���㣬���㷨
	��֤�����е����һ����ʼ�ڸ���. */

	return minSum;
}

int main() {
	int a[] = { -2,-11,10,-13,-5,2 };
	int length = 6;

	cout << minSubsequenceSum(a, length) << endl;

	return 0;
}