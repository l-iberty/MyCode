#include <iostream>
using namespace std;

class Demo {
private:
	int data;
public:
	Demo(int inData) {
		data = inData;
	}
	Demo() {
		data = 0;
	}
	friend int getData(Demo &rDemo) {
		// 友元函数在类中声明,但可在类外定义
		// 在类外定义时前面不能加上 "classname::",友元函数不是类的成员
		return rDemo.data;
	}
};

/*int getData(Demo &rDemo) {
	return rDemo.data;
}*/

int main() {
	Demo demo(5);
	cout << "demo.data = " << getData(demo) << endl;

	return 0;
}
