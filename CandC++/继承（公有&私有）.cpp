#include <iostream>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double inX = 0, double inY = 0) {
		this->x = inX;
		this->y = inY;
	}
	void move(double offX, double offY) {
		x += offX;
		y += offY;
	}
	void showXY() {
		cout << "(" << x << "," << y << ")";
	}
};

class Circle :public Point {
private:
	double radius;
	const double PI = 3.1415;
public:
	Circle(double r, double inX, double inY) :Point(inX, inY) {
		this->radius = r;
	}
	double area() {
		return radius*radius*PI;
	}
	void showCircle() {
		cout << "center: ";
		showXY();
		cout << "radius: " << radius << endl;
	}
	/* void move(int offX, int offY) {
		Point::move(offX, offY);
	} */
};

int main() {
	Circle circle = Circle(5.3, 3.4, 9.88);
	circle.showCircle();
	cout << "Area = " << circle.area() << endl;

	circle.move(12.09, 2);
	// move()继承自Point，在父类中是公有的
	// 公有继承下，move()在子类中是公有的
	// 私有继承下，move()在子类中是私有的，main()中无法访问，但子类可以进行同名覆盖
	circle.showCircle();
	cout << "Area = " << circle.area() << endl;

	return 0;
}

/*公有方式继承的特点：  
1.基类的公有成员在派生类中仍然为公有成员。
2.基类的私有成员在派生类中，无论是派生类的成员还是派生类的对象都无法直接访问。
3.基类的保护成员在派生类中仍是保护成员。
*/
/*私有方式继承的特点：  
1.基类的公有成员和保护成员被继承后作为派生类的私有成员。 
2.基类的私有成员在派生类中不能被直接访问。
3.经过私有继承之后，所有基类的成员都成为了派生类的私有成员或不可访问的成员。
   如果进一步派生，基类的全部成员将无法在新的派生类中被访问。
*/