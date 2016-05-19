#include <iostream>
using namespace std;

long gcd_recursion(long m, long n);
long gcd_loop(long m, long n);

int main() {
	long m, n;
	cin >> m >> n;
	cout << gcd_recursion(m, n) << endl;
	cout << gcd_loop(m, n) << endl;

	return 0;
}

long gcd_recursion(long m, long n) {
	long tmp;
	if (m < n) {
		tmp = m;
		m = n;
		n = tmp;
	}
	if (n == 0)
		return m;
	else
		return gcd_recursion(n, m%n);
}

long gcd_loop(long m, long n) {
	long r;
	do {
		r = m%n;
		m = n;
		n = r;
	} while (r != 0);
	return m;
}