#pragma once
#include<iostream>
#include "point.h"
using namespace std;

class segment {
private: 
	point a;
	point b;
	double coefficientA, coefficientB; 
	void line_formula();
public:
	void write();
	void rotate(point p, double angle);
	double getCoefficientA();
	double getCoefficientB();
	segment(point x, point y);
	segment(const segment &s);
	point get_a();
	point get_b();
	double get_length();
	void move_by_vector(double x, double y);
	void write_line_formula();
	bool point_in_segment(point p);
	point get_middle();
	point intersection_point(segment f, segment g);

};

bool if_parallel(segment f, segment g);
bool if_perp(segment f, segment g);