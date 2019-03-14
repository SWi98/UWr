#include <iostream>
#include <algorithm>
#include "segment.h"
#include "point.h"
using namespace std;


bool if_parallel(segment f, segment g) {
	if (f.getCoefficientA() * g.getCoefficientB() == g.getCoefficientA() * f.getCoefficientB())
		return true;
	else
		return false;
}

bool if_perp(segment f, segment g) {
	if (f.getCoefficientA() * g.getCoefficientA() == 
		-1 * f.getCoefficientB() * g.getCoefficientB()) {
		return true;
	}
	else
		return false;
}

point intersection_point(segment f, segment g) {

	if (if_parallel(f, g))
		throw ("Parallel lines");
	
	double a = f.getCoefficientA();
	double c = f.getCoefficientB();
	double b = g.getCoefficientA();
	double d = g.getCoefficientB();
	double X = (d - c) / (a - b);
	double Y = (a*d - b * c) / (a - b);
	point K(X, Y);

	if (!(f.point_in_segment(K) and g.point_in_segment(K)))
		throw ("No such point exists");
	else
		return K;
}

double segment::getCoefficientA() {
	return coefficientA;
}

double segment::getCoefficientB() {
	return coefficientB;
}

//segment::segment() = default;

segment::segment(point x, point y){
	if (x.get_x() == y.get_x() && x.get_y() == y.get_y())
		throw invalid_argument("Points are identical");
	a = x;
	b = y;
	line_formula();
}

segment::segment(const segment &s) {
	a = s.a;
	b = s.b;
	line_formula();
}

void segment::rotate(point p, double angle) {
	a.rotate(p, angle);
	b.rotate(p, angle);
}

void segment::write() {
	cout << "(" << a.get_x() << ", " << a.get_y() << "); " << "(" << b.get_x()
		<< ", " << b.get_y() << ")" << endl;
}

void segment::line_formula() {
	double a_x, a_y, b_x, b_y;

	point A = a;	point B = b;
	a_x = A.get_x();	a_y = A.get_y();
	b_x = B.get_x();	b_y = B.get_y();
	double coA;
	double coB;
	if (a_y == b_y)
		coA = 0;
	else
		coA = (b_y - a_y) / (b_x - a_x);
	if (a_x == b_x) {
		coA = 0;
		coB = 0;
	}
	else
		coB = a_y - coA * a_x;

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

point segment::get_middle() {
	double x = (a.get_x() + b.get_x()) / 2;
	double y = (a.get_y() + b.get_y()) / 2;
	point k(x, y);
	return k;	
}