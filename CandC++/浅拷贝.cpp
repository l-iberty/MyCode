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

	/* s1和s2中的数据成员str指向同一内存区域,main结束后,s2和
	s1的生命期依次结束,s2析构,释放str指向的内存,然后s1析构,
	可是s1和s2的数据成员str指向同一内存区域,所以同一内存区域
	怎么能被释放两次？结果程序无法正常终止. */

	/* 默认的拷贝构造函数实现的只能是浅拷贝，即直接将原对象
	的数据成员值依次拷贝给新对象中对应的数据成员,并没有为新
	对象另外分配内存资源.这样，如果对象的数据成员是指针，两
	个指针实际上指向的是同一块内存空间.*/

	return 0;
}