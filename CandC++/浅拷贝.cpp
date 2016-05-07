#include <iostream>
using namespace std;

class String {
private:
	char *str;
	char* strcpy(char *dest, const char *source)
	{
		char *ch = dest;
		while ((*(dest++) = *(source++)) != '\0');
		return ch;
	}

public:
	String() {
		str = NULL;
	}
	String(const char *msg) {
		str = new char[strlen(msg) + 1];
		if (str == NULL) {
			cout << "Allocation Error" << endl;
		}
		strcpy(str, msg);
	}
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

	/* s1��s2�е����ݳ�Աstrָ��ͬһ�ڴ�����,main������,s2��
	s1�����������ν���,s2����,�ͷ�strָ����ڴ�,Ȼ��s1����,
	����s1��s2�����ݳ�Աstrָ��ͬһ�ڴ�����,����ͬһ�ڴ�����
	��ô�ܱ��ͷ����Σ���������޷�������ֹ. */

	/* Ĭ�ϵĿ������캯��ʵ�ֵ�ֻ����ǳ��������ֱ�ӽ�ԭ����
	�����ݳ�Աֵ���ο������¶����ж�Ӧ�����ݳ�Ա,��û��Ϊ��
	������������ڴ���Դ.�����������������ݳ�Ա��ָ�룬��
	��ָ��ʵ����ָ�����ͬһ���ڴ�ռ�.*/

	return 0;
}