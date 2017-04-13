#include "test.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
void Shape::display()
{
	cout << "Display shape" << endl;
}

void Shape::draw()
{
	cout << "Drawing shape..." << endl;
}

void Shape::drag()
{
	cout << "Draging shape..." << endl;
}

void Shape::hello()
{
	cout << "Hello, Shape" << endl;
}

///////////////////////////////////////////////////////////////////////
void Line::display()
{
	cout << "Display line" << endl;
}

void Line::draw()
{
	cout << "Drawing line..." << endl;
}

void Line::drag()
{
	cout << "Draging line..." << endl;
}

void Line::hello()
{
	cout << "Hello, Line" << endl;
}

///////////////////////////////////////////////////////////////////////
void Circle::display()
{
	cout << "Display circle" << endl;
}

void Circle::draw()
{
	cout << "Drawing circle..." << endl;
}

void Circle::drag()
{
	cout << "Draging circle..." << endl;
}

void Circle::hello()
{
	cout << "Hello, Circle" << endl;
}