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
	Demo *Dp = new Demo; // ��������ָ�벢��newΪ���ڶ��ж�̬�����ڴ�. ���ù��캯��#1
	//Demo *Dp = new Demo();
	cout << Dp->data << endl;
	delete Dp; // ��̬�����Ķ���ֻ����delete�ͷŲŻ������������

	Dp = new Demo(5); // ���ù��캯��#2
	cout << Dp->data << endl;
	delete Dp;

	cout << "--------------------------" << endl;
	Demo *dp = new Demo[5]; // ���ù��캯��#1, 5��
	for (i = 0;i < 5;i++) {
		dp[i].setData(i);
	}
	for (i = 0;i < 5;i++) {
		cout << dp[i].data << endl;
	}
	delete[]dp;

	return 0;
}