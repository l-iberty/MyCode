#include<iostream>
using namespace std;

int minSubsequenceSum(int a[], int length) {
	int i, minSum, tmpSum = 0;
	bool flag = true;

	for (i = 0; i < length; i++) {
		if (a[i] > 0 && flag) {
			minSum = a[i];
			flag = false;
		}
		/* ��minSum��ʼ��Ϊ���еĵ�һ������ */
		if (a[i] > 0)
			tmpSum += a[i];
		/* ֻ�������ۼ���� */
		if (a[i + 1] < 0) {
			tmpSum = 0;
			flag = true;
		}
		/* ���ۼӹ��������a[i]������ָ���������ֹ�ۼӹ��̣�
		������minSum�����¿�ʼ�ۼ� */
		if (!flag) {
			if (tmpSum < minSum)
				minSum = tmpSum;
		}
 	}

	return minSum;
}

int main() {
	int a[] = { -2,-11,10,13,-5,2 };
	int length = 6;

	cout << minSubsequenceSum(a, length) << endl;

	return 0;
}