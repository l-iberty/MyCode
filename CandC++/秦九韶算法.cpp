#include <iostream>
using namespace std;

int main()
{
	double x, v, a;
	int n, i;

	cout << "最高次项的次数=? ";
	cin >> n;
	cout << "x=? ";
	cin >> x;

	cout << "从最高次项开始依次输入对应系数" << endl;
	cout << "a" << n << "=? ";
	cin >> a;
	for (i = 0, v = a;i < n;i++) {
		cout << "a" << n - i - 1 << "=? ";
		cin >> a;
		v = v*x + a;
	}
	cout << endl << "v = " << v << endl;

	return 0;
}