#include<iostream>
using namespace std;

long long power1(int x, int n) {
	if (n == 0)
		return 1;
	else
		return power1(x, n - 1)*x;
	if (n % 2 == 0)
		return power1(x*x, n / 2);
	else
		return power1(x*x, n / 2)*x;
}

long long power2(int x, int n) {
	int b[32] = { 0 }, i, thisPow, currentPow;
	for (i = 31; i >= 0; i--)
		b[i] = (n >> i) & 0x01;

	thisPow = x, currentPow = 1;
	for (i = 0; i < 32; i++) {
		if (b[i] == 1)
			currentPow = currentPow*thisPow;
		thisPow *= thisPow;
	}

	return currentPow;
}

int main() {
	int x, n;
	cout << "x=";
	cin >> x;
	cout << "n=";
	cin >> n;

	cout << power2(x, n) << endl;
	cout << power1(x, n) << endl;
	return 0;
}