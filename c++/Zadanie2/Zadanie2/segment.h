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
	segment(point x, point y);
	point get_a();
	point get_b();
	double get_length();
	void move_by_vector(double x, double y);
	void write_line_formula();
	bool point_in_segment(point p);
};