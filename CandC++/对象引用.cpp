#include <iostream>
using namespace std;

class Demo {
private:
	int data;
public:
	Demo(int inData) {
		data = inData;
	}

	int getData() {
		return data;
	}

	void setData(int inData) {
		data = inData;
	}

	void setData(Demo &p) {
		data = p.data;
	}
};

int main() {
	Demo d1 = Demo(3);
	Demo &r1_Demo = d1; // 声明对象引用
	/* 引用变量除了作为函数参数或返回值,声明时必须初始化 */
	cout << "d1.data = " << d1.getData() << endl;
	cout << "d1.data = " << r1_Demo.getData() << endl;

	Demo d2 = Demo(9);
	Demo &r2_Demo = d2;
	r1_Demo.setData(r2_Demo);
	cout << "d1.data = " << d1.getData() << endl;

	return 0;
}