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
	/* 运算符重载有两种形式：重载为类的成员函数和类的非成员函数，
	非成员函数通常是友元. 运算符要重载为类的友元函数，因为这样可
	以自由访问类的任何数据成员. */
	friend Complex operator + (Complex A, Complex B); // 重载+为友元函数
	friend Complex operator + (Complex A, int a);
	friend Complex operator - (Complex A, Complex B); // 重载-为友元函数
	friend Complex operator - (Complex &A); // 取负
	friend Complex operator ++ (Complex &A); // 前置++
	friend Complex operator ++ (Complex &A, int); // 后置++
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

Complex operator ++ (Complex &A) { // 前置++
	return Complex(A.real++, A.image);
}

Complex operator ++ (Complex &A, int) { // 后置++
	return Complex(++A.real, A.image);
}

int main() {
	Complex A(10, 20), B(4, 8);
	Complex C = A + B; // "A + B"被解释为"operator + (A,B)"的函数调用
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