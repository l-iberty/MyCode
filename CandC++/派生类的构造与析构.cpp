#include <iostream>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double inX, double inY) {
		this->x = inX;
		this->y = inY;
		cout << "Constructing point (" << x << "," << y << ")" << endl;
	}
	~Point() {
		cout << "Destructing point (" << x << "," << y << ")" << endl;
	}
};

class Circle :protected Point {
private:
	double r;
public:
	Circle(double inR, double inX, double inY) :Point(inX, inY) {
		this->r = inR;
		cout << "Constructing circle, R = " << r << endl;
	}
	~Circle() {
		cout << "Destructing circle, R = " << r << endl;
	}
};

class Tube :protected Circle {
private:
	double h;
	Circle inCircle;
public:
	Tube(double inH, double inR1, double inR2, double inX, double inY) :inCircle(inR1, inX, inY) , Circle(inR2, inX, inY) {
		this->h = inH;
		cout << "Constructing tube, H = " << h << endl;
	}
	~Tube() {
		cout << "Destructing tube, H = " << h << endl;
	}
};

int main() {
	Tube tube(100, 20, 25, 8, 9);
	return 0;
}