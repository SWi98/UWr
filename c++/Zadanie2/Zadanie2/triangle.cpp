#include <iostream>
#include  "triangle.h"
#include "point.h"
using namespace std;

triangle::triangle(point x, point y, point z)
	: a(x)
	, b(y)
	, c(z) {}

void triangle::move_by_vector(double x, double y) {
	a.move_by_vector(x, y);
	b.move_by_vector(x, y);
	c.move_by_vector(x, y);
}

void triangle::rotate(point p, double angle) {
	a.rotate(p, angle);
	b.rotate(p, angle);
	c.rotate(p, angle);
}

double triangle::get_perimeter() {
	return get_distance(a, b) + get_distance(b, c) + get_distance(c, a);
}

double triangle::get_area() {
	double x, y, z, p, res;
	x = get_distance(a, b);
	y = get_distance(b, c);
	z = get_distance(c, a);
	p = (x + y + z) / 2;
	res = sqrt(p *(p - x)*(p - y)*(p - z));
	return res;
}

point triangle::get_middle_point() {
	double X, Y;
	X = (a.get_x() + b.get_x() + c.get_x()) / 3;
	Y = (a.get_y() + b.get_y() + c.get_y()) / 3;
	point k(X, Y);
	return k;
}

bool triangle::if_point_inside(point p) {
	triangle M(a, p, b);
	triangle N(b, p, c);
	triangle O(c, p, a);
	if (M.get_area() + N.get_area() + O.get_area() == this->get_area())
		return true;
	else
		return false;

}