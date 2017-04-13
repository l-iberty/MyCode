#include "test.h"

void handleObject(Shape *shape)
{
	shape->display();
	shape->hello();
}

void main()
{
	Shape *myShape = new Line;
	handleObject(myShape);

	delete myShape;
}