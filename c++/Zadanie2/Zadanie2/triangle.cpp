#include <iostream>
#include  "triangle.h"
#include "point.h"
using namespace std;

triangle::triangle(point x, point y, point z) 
	: a(x)
	, b(y)
	, c(z){}

void triangle::move_by_vector(double x, double y) {
	a.move_by_vector(x, y);
	b.move_by_vector(x, y);
	c.move_by_vector(x, y);
}
