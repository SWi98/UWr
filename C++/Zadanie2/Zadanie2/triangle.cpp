#include <iostream>
#include<math.h>
#include  "triangle.h"
#include "point.h"
using namespace std;

point triangle::get_a() {
	return this->a;
}

point triangle::get_b() {
	return this->b;
}

point triangle::get_c() {
	return this->c;
}

bool triangle::tr_cond(double x, double y, double z) {
	return !((x + y > z) && (x + z > y) && (y + z > x));
}


triangle::triangle(point x, point y, point z)
	: a(x)
	, b(y)
	, c(z) {
	cout << "Trojkat z punktow: " << endl;
	x.write();
	y.write();
	z.write();
	if (!this->Different())
		throw invalid_argument("Points are the same");
	/*else if (this->tr_cond(get_distance(x, y), get_distance(y, z), get_distance(z, x))) 
		throw invalid_argument("Wrong distances between points");*/
	
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

bool triangle::Different(){
	return (different(a, b) && different(b, c) && different(c, a));
}

bool if_contains(triangle bigger, triangle smaller) {
	return (bigger.is_point_in(smaller.get_a()) && bigger.is_point_in(smaller.get_b())
		&& bigger.is_point_in(smaller.get_c()));
}

bool if_separable(triangle one, triangle two) {
	return (one.is_point_in(two.get_a()) || one.is_point_in(two.get_b()) ||
		one.is_point_in(two.get_c()) || two.is_point_in(one.get_a()) ||
		two.is_point_in(one.get_b()) || two.is_point_in(one.get_c()));
}

