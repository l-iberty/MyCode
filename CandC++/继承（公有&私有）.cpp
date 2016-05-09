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
	// move()�̳���Point���ڸ������ǹ��е�
	// ���м̳��£�move()���������ǹ��е�
	// ˽�м̳��£�move()����������˽�еģ�main()���޷����ʣ���������Խ���ͬ������
	circle.showCircle();
	cout << "Area = " << circle.area() << endl;

	return 0;
}

/*���з�ʽ�̳е��ص㣺  
1.����Ĺ��г�Ա������������ȻΪ���г�Ա��
2.�����˽�г�Ա���������У�������������ĳ�Ա����������Ķ����޷�ֱ�ӷ��ʡ�
3.����ı�����Ա�������������Ǳ�����Ա��
*/
/*˽�з�ʽ�̳е��ص㣺  
1.����Ĺ��г�Ա�ͱ�����Ա���̳к���Ϊ�������˽�г�Ա�� 
2.�����˽�г�Ա���������в��ܱ�ֱ�ӷ��ʡ�
3.����˽�м̳�֮�����л���ĳ�Ա����Ϊ���������˽�г�Ա�򲻿ɷ��ʵĳ�Ա��
   �����һ�������������ȫ����Ա���޷����µ��������б����ʡ�
*/