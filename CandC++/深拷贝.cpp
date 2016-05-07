#include <iostream>
using namespace std;

class String {
private:
	char *str;

	char* strcpy(char *dest, const char *source) {
		char *ch = dest;
		while ((*(dest++) = *(source++)) != '\0');
		return ch;
	}

	int strlen(char *msg) {
		int count = 0;
		char *ch = msg;

		while (*ch++)
			count++;

		return count;
	}

public:
	String() {
		str = NULL;
	}

	String(char *msg) {
		str = new char[strlen(msg) + 1];
		if (str == NULL) {
			cout << "Allocation Error" << endl;
		}
		strcpy(str, msg);
	}

	String(String &s) {
		str = new char[strlen(s.str) + 1];
		if (str == NULL) {
			cout << "Allocation Error" << endl;
		}
		strcpy(str, s.str);
	}
	/* 实现了深拷贝,为新的对象的指针型数据成员单独分配了内存 */

	~String() {
		if (str != NULL) {
			delete[]str;
			str = NULL;

			cout << "Destructor called..." << endl;
		}
	}

	char* getStr() {
		return str;
	}
};

int main() {
	String s1("abcd");
	cout << s1.getStr() << endl;

	String s2 = s1;
	cout << s2.getStr() << endl;

	return 0;
}