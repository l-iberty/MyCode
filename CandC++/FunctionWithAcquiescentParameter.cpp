#include <iostream>
using namespace std;


int add(int a = 10, int b = 20);
/* Ĭ���β�ֵֻ���ں���ԭ���д���������� */
int main()
{
	int val;

	val = add(2);
	cout << "val= " << val << endl;
	val = add();
	cout << "val= " << val << endl;
	val = add(2,3);
	cout << "val= " << val << endl;

	return 0;
}

int add(int a, int b)
{
	return a + b;
}