#include <iostream>
using namespace std;

int main()
{
	int *p;
	p = new int;/* �ڶѿռ����int��С���ڴ�,����pָ���� */
	if (p == NULL)
		cout << "Memory allocation error!" << endl;
	else
		*p = 10;
		/* Ҳ��������ʱ��ʼ��: p = new int(10) */
		/* ��"*p = 10.333",С�����ֱ����� */

	cout << "*p= " << *p << endl;
	delete p;

	return 0;
}