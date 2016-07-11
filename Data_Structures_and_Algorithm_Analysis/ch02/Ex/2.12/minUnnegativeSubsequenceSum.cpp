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
		/* 将minSum初始化为序列的第一个正数 */
		if (a[i] > 0)
			tmpSum += a[i];
		/* 只对正数累加求和 */
		if (a[i + 1] < 0) {
			tmpSum = 0;
			flag = true;
		}
		/* 在累加过程中如果a[i]后面出现负数，须终止累加过程，
		并更新minSum，重新开始累加 */
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