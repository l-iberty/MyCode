#include<iostream>
#define N 4
using namespace std;

int src[] = { 2,3,5,7 };
int A[3], B[2];

void assignToA(int i, int  j, int k);
void assignToB(int i, int  j);
bool test(long val, int m);
int valueOf(int a[], int n);

int main() {
	long tmp1, tmp2, tmp3;
	int a, b, count = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				assignToA(i, j, k); // 穷举因子1
				for (int p = 0; p < N; p++)
					for (int q = 0; q < N; q++) {
						count++;
						assignToB(p, q); // 穷举因子2
						a = valueOf(A, 3);
						b = valueOf(B, 2);
						tmp1 = a*B[1]; // B[1]，个位数字
						tmp2 = a*B[0]; // B[0]，十位数字
						if ( test(tmp1, 4) )
							if ( test(tmp2, 4) ) {
								tmp2 *= 10;
								tmp3 = tmp1 + tmp2;
								if (test(tmp3, 5)) {
									cout << "          " << a << endl;
									cout << "         * " << b << endl;
									cout << "-----------------------" << endl;
									cout << "         " << tmp1 << endl;
									cout << "        " << tmp2/10 << endl;
									cout << "-----------------------" << endl;
									cout << "        " << tmp3 << endl;
								}
							}
					}
			}
	cout << count << endl;
	return 0;
}

void assignToA(int i, int  j,  int k) {
	A[0] = src[i];
	A[1] = src[j];
	A[2] = src[k];
}

void assignToB(int i, int  j) {
	B[0] = src[i];
	B[1] = src[j];
}

bool test(long val, int m) {
	int r, i = 1, count = 1;
	long  tmp, tmpVal = val;
	bool flag = true;

	do {
		tmp = tmpVal / 10;
		tmpVal /= 10;
		if (tmp == 0)
			flag = false;
		else
			count++;
	} while (flag); // 确定数字的位数

	if (count != m)
		return false; // 位数不符合要求
	
	do {
		r = val % 10;
		val /= 10;
		if (r == 2 || r == 3 || r == 5 || r == 7)
			i++;
		else
			return false;
	} while (i <= count);
	return true;
}

int valueOf(int a[], int n) {
	int sum = 0, i = 0;
	do {
		sum = sum*10 + a[i++];
	} while (i < n);

	return sum;
}