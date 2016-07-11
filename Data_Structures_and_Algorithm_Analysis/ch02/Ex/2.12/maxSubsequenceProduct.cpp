#include<iostream>
using namespace std;

int maxSubsequenceProduct(int a[], int length) {
	int i, tmpProduct = 1, maxProduct = 1;

	for (i = 0; i < length; i++) {
		tmpProduct *= a[i];
		if (tmpProduct > maxProduct)
			maxProduct = tmpProduct;
		else if (tmpProduct < 0)
			tmpProduct = 1;
	}

	return maxProduct;
}

int main() {
	int a[] = { -2,-11,10,-13,5,6 };
	int length = 6;

	cout << maxSubsequenceProduct(a, length) << endl;

	return 0;
}