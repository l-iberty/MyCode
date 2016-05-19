#include <iostream>
using namespace std;

class String {
private:
	char *str;
	int len;

	char *strcpy(char *des, const char *src) {
		char *ch = des;
		while ((*des++ = *src++) != '\0');
		return ch;
	}

	int strlen(const char *src) {
		int i = 0;
		while (*src++)
			i++;
		return i;
	}
public:
	String(const char *src) {
		if (src) {
			len = strlen(src);
			str = new char[len + 1];
			strcpy(str, src);
		}
		else {
			len = 0;
			str = NULL;
		}
	}
	~String() {
		len = 0;
		if (str) {
			delete []str;
			str = NULL;
		}
	}
	
	/*char operator [](int index) {
		return str[index];
	}*/
	char &operator [](int index) {
		return str[index];
	}

	const char &operator [](int index) const{
		return str[index];
	}
};

int main() {
	String s1("ABCDEFGHIJK");
	cout << s1[4] << endl;
	s1[4] = 'K';
	/*被解释为 s1.operator[](4) 的函数调用，所以=的左边是一个引用，能够
	给它所引用的变量赋值. 若采用41~43行的重载方式则该语句无法通过编译
	因为=的左边是一个char常量（函数的返回值），"即不可修改的左值". */
	/*若将s1定义为const，则调用的函数是48行的那个，返回const char的引
	用，因其只读属性无法被赋值. */
	return 0;
}