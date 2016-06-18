#include <iostream>
using namespace std;
void H(int n, char a, char b, char c);

int main() {
	int n;
	cout << "n=? ";
	cin >> n;
	H(n, 'A', 'B', 'C');
	return 0;
}

void H(int n, char a, char b, char c) {
	if (n == 1)
		cout << a << " --> " << c << endl;
	else {
		H(n - 1, a, c, b);
		cout << a << " --> " << c << endl;
		H(n - 1, b, a, c);
		/* 将a盘上的n-1个盘子借助c盘移动到b盘 */
		/* 将a盘剩下的一个盘子直接移动到c盘 */
		/* 最后将b盘上的n-1个盘子借助a盘移动到c盘 */
	}
}