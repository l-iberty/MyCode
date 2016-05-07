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
	Demo &r1_Demo = d1; // ������������
	/* ���ñ���������Ϊ���������򷵻�ֵ,����ʱ�����ʼ�� */
	cout << "d1.data = " << d1.getData() << endl;
	cout << "d1.data = " << r1_Demo.getData() << endl;

	Demo d2 = Demo(9);
	Demo &r2_Demo = d2;
	r1_Demo.setData(r2_Demo);
	cout << "d1.data = " << d1.getData() << endl;

	return 0;
}