#include <iostream>
using namespace std;
long long Fibonacci(int n);

int main() {
	int index;
	cin >> index;
	cout << Fibonacci(index) << endl;
	return 0;
}

long long Fibonacci(int n) {
	long long prev1 = 1, prev2 = 1, result = 0;
	// prev2:��ǰ���ǰһ��; prev1:prev2��ǰһ��.

	if (n == 1 || n == 2)
		return 1;
	else {
		for (int k = 2;k < n;k++) {
			result = prev1 + prev2;
			prev2 = prev1;
			prev1 = result;
		}
	}

	return result;
}