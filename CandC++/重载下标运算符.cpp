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
	/*������Ϊ s1.operator[](4) �ĺ������ã�����=�������һ�����ã��ܹ�
	���������õı�����ֵ. ������41~43�е����ط�ʽ�������޷�ͨ������
	��Ϊ=�������һ��char�����������ķ���ֵ����"�������޸ĵ���ֵ". */
	/*����s1����Ϊconst������õĺ�����48�е��Ǹ�������const char����
	�ã�����ֻ�������޷�����ֵ. */
	return 0;
}