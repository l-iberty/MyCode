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
		/* ��a���ϵ�n-1�����ӽ���c���ƶ���b�� */
		/* ��a��ʣ�µ�һ������ֱ���ƶ���c�� */
		/* ���b���ϵ�n-1�����ӽ���a���ƶ���c�� */
	}
}