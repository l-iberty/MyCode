#ifndef TEST_H
#define TEST_H

class Shape {
public:
	void display();
	virtual void draw();
	virtual void drag();
	virtual void hello();
};

class Line :public Shape {
public:
	void display();
	void draw() override;
	void drag() override;
	void hello() override;
};

class Circle :public Shape {
public:
	void display();
	void draw() override;
	void drag() override;
	void hello() override;
};

#endif