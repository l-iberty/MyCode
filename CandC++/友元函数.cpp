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
		// ��Ԫ��������������,���������ⶨ��
		// �����ⶨ��ʱǰ�治�ܼ��� "classname::",��Ԫ����������ĳ�Ա
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
