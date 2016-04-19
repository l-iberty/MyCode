#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char ch;
	char name[20];

	cout << "get input..." << endl;
	/* endl,换行并刷新输出流 */

	cout << "int,a=? ";
	a = cin.get();/* get()返回读取的字符 */
	cout << "a(char) = " << (char)a << endl;
	cout << "a(int) = " << a << endl;

	cout << endl << "int,b=? ";
	cin >> b;
	cout << "b= (dec) " << dec << b << endl;
	cout << "b= (hex) " << hex << b << endl;
	cout << "b= (oct) " << oct << b << endl;

	cout << endl << "char,ch=? ";
	cin >> ch;
	cout << "ch= " << ch << endl;
	cout << endl << "b+ch= " << b + ch << endl;
	/* C++支持int和char的隐式转换 */

	cout << endl << "char[],name=? ";
	//cin >> name; /* 遇到空格就终止读取 */
	cin.get(); 
	/* 之前的读取操作使输入流队列中遗留了'\n',若
	 *  想让以后的cin.get()如期运行必须清理'\n'.
	 */
	cin.get(name, 11, '#');
	cout << "name = " << name << endl;

	return 0;
}