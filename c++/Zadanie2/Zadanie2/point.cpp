#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "point.h"
using namespace std;

double get_distance(point a, point b) {
	return sqrt((b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) +
		((b.get_y() - a.get_y()) * (b.get_y() - a.get_y())));
}

point::point() {

}

point::point(const point &p) {
	x = p.x;
	y = p.y;

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
	this->x = this->x * cos(angle * M_PI / 180.0) - this->y * sin(angle * M_PI / 180.0);
	this->y = old_x * sin(angle * M_PI / 180.0) + this->y * cos(angle * M_PI / 180.0);
	this->move_by_vector(p_x, p_y);
}

bool different(point a, point b){
	return (a.get_x() != b.get_x()) || (a.get_y() != b.get_y());
}
