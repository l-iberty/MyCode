#include <iostream>
using namespace std;

class Demo {
public:
	int data;

	Demo() {
		data = 0;
	}

	Demo(int inData) {
		data = inData;
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
	Demo *Dp = new Demo; // ��������ָ�벢��newΪ���ڶ��ж�̬�����ڴ�
	//Demo *Dp = new Demo();
	cout << Dp->data << endl;
	delete Dp; // ��̬�����Ķ���ֻ����delete�ͷŲŻ������������

	Dp = new Demo(5);
	cout << Dp->data << endl;
	delete Dp;

	cout << "--------------------------" << endl;
	Demo *dp = new Demo[5];
	for (i = 0;i < 5;i++) {
		dp[i].setData(i);
	}
	for (i = 0;i < 5;i++) {
		cout << dp[i].data << endl;
	}
	delete[]dp;

	return 0;
}