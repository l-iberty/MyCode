#include <iostream>
using namespace std;

class Demo {
public:
	int data;

	Demo() {
		data = 0;
		cout << "Constructor #1" << endl;
	}

	Demo(int inData) {
		data = inData;
		cout << "Constructor #2" << endl;
	}

	void setData(int inData) {
		data = inData;
	}

	~Demo() {
		cout << "Destructor" << endl;
	}
};

int main() {
	int i;
	Demo *Dp = new Demo; // 声明对象指针并用new为其在堆中动态分配内存. 调用构造函数#1
	//Demo *Dp = new Demo();
	cout << Dp->data << endl;
	delete Dp; // 动态建立的对象只有用delete释放才会调用析构函数

	Dp = new Demo(5); // 调用构造函数#2
	cout << Dp->data << endl;
	delete Dp;

	cout << "--------------------------" << endl;
	Demo *dp = new Demo[5]; // 调用构造函数#1, 5次
	for (i = 0;i < 5;i++) {
		dp[i].setData(i);
	}
	for (i = 0;i < 5;i++) {
		cout << dp[i].data << endl;
	}
	delete[]dp;

	return 0;
}