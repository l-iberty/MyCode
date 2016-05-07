#include <iostream>
using namespace std;

class demo {
private:
	int data;
public:
	demo(int inData) {
		data = inData;
	}

	void showData() {
		cout << "data = " << data << endl;
	}
};

int main() {
	demo d = demo(5); // 构造函数显式调用
	demo d1(12); // 隐式调用
	// Java中只有显式调用: demo d = new demo(12);
	d.showData();
	d1.showData();

	return 0;
}