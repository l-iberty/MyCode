#include<iostream>
using namespace std;

int reminder(int x, int n, int m) {
	int b[32] = { 0 }, i, thisPow, currentPow;
	for (i = 31; i >= 0; i--)
		b[i] = (n >> i) & 0x01;

	thisPow = x, currentPow = 1;
	for (i = 0; i < 32; i++) {
		if (b[i] == 1)
			currentPow = currentPow*thisPow%m;
		thisPow = thisPow*thisPow%m;
	}

	return currentPow;
}

int main() {
	int x, n, m;
	cout << "x=";
	cin >> x;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	cout << reminder(x, n, m) << endl;
	return 0;
}