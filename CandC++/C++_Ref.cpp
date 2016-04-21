#include <iostream>
using namespace std;

void swapRef(int &refx, int &refy);
void swapPoi(int *px, int *py);
int main()
{
	int a = 5, b = 7;
	int m, n;
	int &refm = m;/* ������������ʱ����������ʱ��ʼ�� */
	int *pn;
	pn = &n; /* int *pn = &n; */
	m = 10;
	n = 15;

	/* ��ʾ���� */
	cout << "m = " << refm << endl;
	/* ����refm��m�ı���,���߹���һ���ڴ浥Ԫ,refm����m,��������� */
	cout << "n = " << *pn << endl;
	cout << "Address of refm: "<< &refm << endl;
	cout << "Address of m: " << &m << endl;
	cout << "Address of pn: " << &pn << endl;
	cout << "Address of *pn: " << &(*pn) << endl;
	cout << "Address of n: " << &n << endl << endl;

	/* ��ʾ���� */
	cout << "Before swap, a = " << a << ", b = " << b << endl;
	swapPoi(&a, &b);
	cout << "After swap, a = " << a << ", b = " << b << endl;
	swapRef(a, b);
	cout << "Swap again, a = " << a << ", b = " << b << endl;

	return 0;
}

void swapRef(int &refx, int &refy)
{
	int tmp;
	tmp = refx;
	refx = refy;
	refy = tmp;
}

void swapPoi(int *px, int *py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}