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
    // p���������κι������������
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
	// ���������ĵ�ַ���Ա���������ָ�룬���мǣ����ǻ�������ָ�룬ֻ�ܷ��ʻ���ĳ�Ա

	Point &r_Point = P; // ����һ����ʼ���Ͳ��ܱ��޸�
	r_Point.showXY();
	r_Point = Cir; // ������ʾ������䲻��������r_Point����Cir��������Cir�Ļ��ࣨPoint������P���ⲻ��ָ�룬�мǣ�����
	r_Point.showXY();
	r_Point = Cy;
	r_Point.showXY();
    // �����������Ա������������

	// ע�⣺�������ֵ����ͼ���ֻ�ܷ����ڹ��м̳���
	cout << "===================" << endl;
	displayCentre(P); // ����P��Cy�Ļ��า����
	displayCentre(Cir);
	displayCentre(Cy);

	return 0;
}