#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char ch;
	char name[20];

	cout << "get input..." << endl;
	/* endl,���в�ˢ������� */

	cout << "int,a=? ";
	a = cin.get();/* get()���ض�ȡ���ַ� */
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
	/* C++֧��int��char����ʽת�� */

	cout << endl << "char[],name=? ";
	//cin >> name; /* �����ո����ֹ��ȡ */
	cin.get(); 
	/* ֮ǰ�Ķ�ȡ����ʹ������������������'\n',��
	 *  �����Ժ��cin.get()�������б�������'\n'.
	 */
	cin.get(name, 11, '#');
	cout << "name = " << name << endl;

	return 0;
}