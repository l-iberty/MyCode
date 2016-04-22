/* �����C��C++,������ּ����ʾdestructor */

#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
	char *str;
	int length;

public:
	String() {
		str = NULL;
		length = 0;
	}

	String(const char *msg) {
		length = strlen(msg);
		str = new char[length+1];/* length������ĩβ���ַ� */
		if (str == NULL)
			cout << "Allocation Error" << endl;

		strcpy(str, msg);/* ����ʱ�������ַ� */
	}

	~String() {
		if (str != NULL) {
			delete []str;
			str = NULL;
			length = 0;

			cout << "Calling destructor..." << endl;
		}
	}

	int getLength() {
		return length;
	}

	char *getStr() {
		return str;
	}
};

int main() {
	String s("ABCD");
	cout << s.getStr() << endl;
	cout << s.getLength() << endl;

	return 0;
}
