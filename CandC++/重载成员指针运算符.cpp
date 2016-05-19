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
	/* pc本质上是 PComplex对象而不是对象指针，该语句被编译器解释为"(pc1.operator -> ()) -> display()" */
	Complex C1(10, -6);
	pc1 = &C1;
	/* 该语句可以执行，因为在没有适合的=运算符时，编译器会寻找适合的隐式类型转换.
	该语句被解释为"pc1 = PComplex(&C1);". */
	/* 关键字explicit，可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生.
	声明为explicit的构造函数不能在隐式转换中使用. 如果构造函数加上 explicit，该语
	句无法通过编译. */
	pc1->display();

	Complex C2(20, -30);
	PComplex pc2(&C2);
	pc2->display();

	return 0;
}