/*1.当基类的析构函数被声明为虚函数，则派生类的析构函数，
      无论是否使用virtual关键字进行声明，都是虚函数。
   2.析构函数声明为虚函数后，程序运行时采用动态联编，因此
	  可以确保使用基类类型的指针就能够自动调用适当的析构函
	  数对不同对象进行清理工作。
   3.当使用delete运算符删除一个对象时，隐含着对析构函数的
	  一次调用，如果析构函数为虚函数，则这个调用采用动态联
	  编，保证析构函数被正确执行。 
*/

#include <iostream>
using namespace std;

class Base {
	int *pB;
public:
	Base() {
		pB = new int[10];
	}
	virtual ~Base() {
		delete[] pB;
		cout << "des B" << endl;
	}
};
class Derived : public Base {
	double *pD;
public:
	Derived() {
		pD = new double[10];
	}
	~Derived() {
		delete[] pD;
		cout << "des D" << endl;
	}
};
int main() {
	Base *pBase = new Derived;
	delete pBase;
	return 0;
}
