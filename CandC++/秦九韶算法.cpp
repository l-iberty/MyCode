#include <iostream>
using namespace std;

int main()
{
	double x, v, a;
	int n, i;

	cout << "��ߴ���Ĵ���=? ";
	cin >> n;
	cout << "x=? ";
	cin >> x;

	cout << "����ߴ��ʼ���������Ӧϵ��" << endl;
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