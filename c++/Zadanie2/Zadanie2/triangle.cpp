#include <iostream>
#include<math.h>
#include  "triangle.h"
#include "point.h"
using namespace std;

triangle::triangle(point x, point y, point z)
	: a(x)
	, b(y)
	, c(z) {
	if (this->notDifferent())
		throw invalid_argument("Points are the same");
}

triangle::triangle(const triangle &T) {
	a = T.a;
	b = T.b;
	c = T.c;
}

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



double triangle::sign(point p1, point p2, point p3) {
	return (p1.get_x() - p3.get_x()) * 
		(p2.get_y() - p3.get_y()) - (p2.get_x() - p3.get_x()) 
		* (p1.get_y() - p3.get_y());
}


bool triangle::is_point_in(point p) {
	double d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(p, this->a, this->b);
	d2 = sign(p, this->b, this->c);
	d3 = sign(p, this->c, this->a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);	
}

bool triangle::notDifferent(){
	return !different(a, b) && !different(b, c) && !different(c, a);
}

