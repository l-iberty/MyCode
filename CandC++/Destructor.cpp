/**
* ��������:
* 1.ͨ����public��������ǰ��bitwise-NOT�����:~;
* 2.�������أ����������麯��;
* 3.�޲������޷�������;
* 4.�������������������ʱ(����������ڵĺ����ѵ������)��
*   ϵͳ�Զ�ִ����������.
**/

#include <iostream>
using namespace std;

class Clock {
	private:
		int hour, min, sec;

	public:
		Clock(int inHour, int inMin, int inSec) {
			hour = inHour;
			min = inMin;
			sec = inSec;

			cout << "Constructor: " << hour << ":" << min << ":" << sec << endl;
		}

		~Clock() {
			cout << "Destructor: " << hour << ":" << min << ":" << sec << endl;
		}
};

Clock C1(1, 0, 0);
Clock C2(2, 0, 0);

int main() {
	Clock C3(3, 0, 0);
	Clock C4(4, 0, 0);

	return 0;
}

/* �ѣ��Ƚ��ȳ� */
/* ջ���Ƚ���� */
/* ���������Ʋ⣬����λ��ջ�ռ� */
