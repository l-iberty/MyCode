/*1.���������������������Ϊ�麯�����������������������
      �����Ƿ�ʹ��virtual�ؼ��ֽ��������������麯����
   2.������������Ϊ�麯���󣬳�������ʱ���ö�̬���࣬���
	  ����ȷ��ʹ�û������͵�ָ����ܹ��Զ������ʵ���������
	  ���Բ�ͬ���������������
   3.��ʹ��delete�����ɾ��һ������ʱ�������Ŷ�����������
	  һ�ε��ã������������Ϊ�麯������������ò��ö�̬��
	  �࣬��֤������������ȷִ�С� 
*/

#include <iostream>
using namespace std;

class Base {
	int *pB;
public:
	Base() {
		pB = new int[10];
	}
	virtual ~Base() {
		delete[] pB;
		cout << "des B" << endl;
	}
};
class Derived : public Base {
	double *pD;
public:
	Derived() {
		pD = new double[10];
	}
	~Derived() {
		delete[] pD;
		cout << "des D" << endl;
	}
};
int main() {
	Base *pBase = new Derived;
	delete pBase;
	return 0;
}
