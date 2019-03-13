#include <iostream>
#include <algorithm>
#include "segment.h"
#include "point.h"
using namespace std;

segment::segment(point x, point y)
	:a(x)
	, b(y) {
	line_formula();
}

void segment::line_formula() {
	double a_x, a_y, b_x, b_y;

	point A = get_a();	point B = get_b();
	a_x = A.get_x();	a_y = A.get_y();
	b_x = B.get_x();	b_y = B.get_y();

	double coA = (b_y - a_y) / (b_x - a_x);
	double coB = a_y - coA * a_x;

	coefficientA = coA;
	coefficientB = coB;
}

double segment::get_length() {
	return get_distance(a, b);
}

point segment::get_a() {
	return a;
}

point segment::get_b() {
	return b;
}

void segment::move_by_vector(double x, double y) {
	a.move_by_vector(x, y);
	b.move_by_vector(x, y);
}

void segment::write_line_formula() {
	cout << "y = " << coefficientA << "*x + " << coefficientB << "\n";
}

bool segment::point_in_segment(point p) {
	double p_x = p.get_x();
	double p_y = p.get_y();

	if (p_y != coefficientA * p_x + coefficientB)
		return false;
	
	bool good_x = false, good_y = false;
	if (p_x <= max(a.get_x(), b.get_x()) && p_x >= min(a.get_x(), b.get_x()))
		good_x = true;
	if (p_y <= max(a.get_y(), b.get_y()) && p_y >= min(a.get_y(), b.get_y()))
		good_y = true;

	if (good_x && good_y)
		return true;
	else
		return false;
}