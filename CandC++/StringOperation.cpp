#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1("hello");
	string str2("world");
	string str3("hell");
	string str4 = ("rgABfbCDaagEFGahbHIJrgaKLMN");
	int len1 = str1.length();
	int cmp = str1.compare(str3);/* 和strcmp()一样 */
	cout << "str1: " << str1 << endl;
	cout << "length of str1: " << len1 << endl;
	cout << "compare str1 and str3: " << cmp << endl;
	cout << "str3: " << str3 << endl;
	str3.append("o");
	cout << "str3(append): " << str3 << endl;
	cout << "str2: " << str2 << endl;
	str2.assign(str1, 1, 3);
	/* 将str1从第1位到底3位间的子串赋给str2 */
	/* 从运行结果看,str2指向一个新的string对象 */
	cout << "str2(assign): " << str2 << endl << endl;

	/* interator */
	string::iterator ite1;
	string::reverse_iterator ite2;/* 反向迭代 */
	cout << "interator:" << endl;
	for (ite1 = str4.begin();ite1 != str4.end();ite1++)
		if (!(*ite1 >= 97 && *ite1 <= 122))
			cout << *ite1;

	cout << endl << "reverse_iterator:" << endl;
	for (ite2 = str4.rbegin();ite2 != str4.rend();ite2++)
		if (!(*ite2 >= 97 && *ite2 <= 122))
			cout << *ite2;

	return 0;
}