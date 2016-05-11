#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int inX = 0, int inY = 0) {
		x = inX;
		y = inY;
	}

	void showXY() {
		cout << "Point: (" << x << "," << y << ")" << endl;
	}
};

class Circle :public Point {
private:
	double r;
public:
	Circle(int inX , int inY, double inR) :Point(inX, inY) {
		r = inR;
	}

	void showCircle() {
		cout << "Circle: r = " << r << endl;
	}
};

class Cylinder :public Circle {
private:
	int h;
public:
	Cylinder(int inX, int inY, double inR, int inH) :Circle(inX, inY, inR) {
		h = inH;
	}

	void showCylinder() {
		cout << "Cylinder: h = " << h << endl;
	}
};

void displayCentre(Point p) {
    // p可以引用任何公有派生类对象
	p.showXY();
}

int main() {
	Point P(10, 15);
	Circle Cir(20, 35, 200);
	Cylinder Cy(30, 45, 200, 400);

	P.showXY();
	Cir.showXY();
	Cy.showXY();

	Point *p_Point;
	p_Point = &P;
	p_Point->showXY();
	p_Point = &Cir;
	p_Point->showXY();
	p_Point = &Cy;
	p_Point->showXY();
	// 派生类对象的地址可以被赋给基类指针，但切记：这是基类对象的指针，只能访问基类的成员

	Point &r_Point = P; // 引用一经初始化就不能被修改
	r_Point.showXY();
	r_Point = Cir; // 误区警示：该语句不是让引用r_Point引用Cir，而是用Cir的基类（Point）覆盖P，这不是指针，切记！！！
	r_Point.showXY();
	r_Point = Cy;
	r_Point.showXY();
    // 派生类对象可以被赋给基类对象

	// 注意：以上体现的类型兼容只能发生在公有继承中
	cout << "===================" << endl;
	displayCentre(P); // 最后的P被Cy的基类覆盖了
	displayCentre(Cir);
	displayCentre(Cy);

	return 0;
}