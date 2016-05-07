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

	void setData(Demo *p) {
		data = p->data;
	}
};

int main() {
	Demo d1 = Demo(3);
	Demo *p1_Demo = &d1; // 声明对象指针
	cout << "d1.data = " << p1_Demo->getData() << endl;

	Demo d2(5);
	p1_Demo->setData(&d2);
	cout << "d1.data = " << p1_Demo->getData() << endl;

	return 0;
}