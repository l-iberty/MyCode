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
	demo d = demo(5); // ���캯����ʽ����
	demo d1(12); // ��ʽ����
	// Java��ֻ����ʽ����: demo d = new demo(12);
	d.showData();
	d1.showData();

	return 0;
}