#include <iostream>
using namespace std;

int main()
{
	int *p;
	p = new int;/* 在堆空间分配int大小的内存,引用p指向它 */
	if (p == NULL)
		cout << "Memory allocation error!" << endl;
	else
		*p = 10;
		/* 也可在声明时初始化: p = new int(10) */
		/* 若"*p = 10.333",小数部分被丢弃 */

	cout << "*p= " << *p << endl;
	delete p;

	return 0;
}