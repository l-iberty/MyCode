/*虚函数（virtual function）允许函数调用与函数体之间的联系在运行时才建立，是实现动态联编的基础。
虚函数经过派生之后，可以在类族中实现运行时的多态。
动态联编在程序运行的过程中，根据指针与引用实际指向的目标调用对应的函数，也就是在程序运行时才决定如何动作。
*/
#include <iostream>
#include <string>
using namespace std;

class A {
public:
	virtual string toString() {
		return "Class A";
	}
};

class B :public A {
public:
	string toString() {
		return "Class B";
	}
};

class C :public B {
public:
	string toString() {
		return "Class C";
	}
};

void displayObject(A *p) {
	cout << p->toString() << endl;
}

void displayObject(A &p) {
	cout << p.toString() << endl;
}
/*void displayObject(A p) {
cout << p.toString() << endl;
}*/

int main() {
	A a;
	B b;
	C c;
	displayObject(a); // Class A
	displayObject(b); // Class B
	displayObject(c); // Class C
	/*若采用37行的函数都将输出Class A*/

	displayObject(&a); // Class A
	displayObject(&b); // Class B
	displayObject(&c); // Class C
	/*通过虚函数实现动态联编需要满足三个条件：
       1.应满足类型兼容规则（公有继承）
       2.在基类中定义虚函数，并且在派生类中重新定义虚函数
       3.要通过指针、引用访问虚函数
    */

	return 0;
}

/*Tips:
在B，C的toString()前加不加virtual都一样，反正基类A的toString()要声明为vitual
因为基类的虚函数被子类继承后还是虚函数，子类只是在重写虚函数，如果子类不重
写基类的虚函数，将无法实现动态联编*/