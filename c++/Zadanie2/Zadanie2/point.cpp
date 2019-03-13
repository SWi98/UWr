#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "point.h"
using namespace std;

double get_distance(point a, point b) {
	return 1;
}

point::point(double a, double b)
	: x(a)
	, y(b) {}

void point::move_by_vector(double a, double b) {
	x += a;
	y += b;
}

void point::write() {
	cout << "x = " << x << ", y = " << y << "\n";
}

double point::get_x() {
	return x;
}

double point::get_y() {
	return y;
}

void point::rotate(point p, double angle) {
	double p_x = p.get_x();
	double p_y = p.get_y();
	double old_x = x;
	x = x * cos(angle * M_PI / 180.0) - y * sin(angle * M_PI / 180.0);
	y = old_x * sin(angle * M_PI / 180.0) + y * cos(angle * M_PI / 180.0);
	this->move_by_vector(p_x, p_y);
}
