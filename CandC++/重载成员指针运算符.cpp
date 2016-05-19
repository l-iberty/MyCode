#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double image;

public:
	Complex(double real = 0, double image = 0) {
		this->real = real;
		this->image = image;
	}

	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
	
};

class PComplex {
private:
	Complex *pc;
public:
	PComplex(Complex *pc = NULL) {
		this->pc = pc;
	}

	Complex *operator ->() {
		static Complex NullComplex(0, 0);
		if (!pc)
			return &NullComplex;
		else
			return pc;
	}
};

int main() {
	PComplex pc1;
	pc1->display();
	/* pc�������� PComplex��������Ƕ���ָ�룬����䱻����������Ϊ"(pc1.operator -> ()) -> display()" */
	Complex C1(10, -6);
	pc1 = &C1;
	/* ��������ִ�У���Ϊ��û���ʺϵ�=�����ʱ����������Ѱ���ʺϵ���ʽ����ת��.
	����䱻����Ϊ"pc1 = PComplex(&C1);". */
	/* �ؼ���explicit��������ֹ��Ӧ������ľ���ת�����캯�����е���ʽת���ķ���.
	����Ϊexplicit�Ĺ��캯����������ʽת����ʹ��. ������캯������ explicit������
	���޷�ͨ������. */
	pc1->display();

	Complex C2(20, -30);
	PComplex pc2(&C2);
	pc2->display();

	return 0;
}