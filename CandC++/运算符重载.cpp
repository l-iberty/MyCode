#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double image;

public:
	Complex(double real, double image) {
		this->real = real;
		this->image = image;
	}

	void display() {
		cout << "(" << real << "," << image << ")" << endl;
	}
	/* �����������������ʽ������Ϊ��ĳ�Ա��������ķǳ�Ա������
	�ǳ�Ա����ͨ������Ԫ. �����Ҫ����Ϊ�����Ԫ��������Ϊ������
	�����ɷ�������κ����ݳ�Ա. */
	friend Complex operator + (Complex A, Complex B); // ����+Ϊ��Ԫ����
	friend Complex operator + (Complex A, int a);
	friend Complex operator - (Complex A, Complex B); // ����-Ϊ��Ԫ����
	friend Complex operator - (Complex &A); // ȡ��
	friend Complex operator ++ (Complex &A); // ǰ��++
	friend Complex operator ++ (Complex &A, int); // ����++
};

Complex operator + (Complex A, Complex B) {
	return Complex(A.real + B.real, A.image + B.image);
}

Complex operator + (Complex A, int a) {
	return Complex(A.real + a, A.image);
}

Complex operator - (Complex A, Complex B) {
	return Complex(A.real - B.real, A.image - B.image);
}

Complex operator - (Complex &A) {
	return Complex(-A.real, -A.image);
}

Complex operator ++ (Complex &A) { // ǰ��++
	return Complex(A.real++, A.image);
}

Complex operator ++ (Complex &A, int) { // ����++
	return Complex(++A.real, A.image);
}

int main() {
	Complex A(10, 20), B(4, 8);
	Complex C = A + B; // "A + B"������Ϊ"operator + (A,B)"�ĺ�������
	cout << "A = ";
	A.display();
	cout << "B = ";
	B.display();
	cout << "C = A + B = ";
	C.display();

	C = A - B;
	cout << "C = A - B = ";
	C.display();

	A++;
	cout << "A++ = ";
	A.display();

	++B;
	cout << "++B = ";
	B.display();
	
	A = A + 100;
	cout << "A = A + 100 = ";
	A.display();

	return 0;
}