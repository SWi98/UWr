#pragma once
#include <iostream>
#include "point.h"

using namespace std;

class triangle {
private:
	point a;
	point b;
	point c;
public:
	triangle(point x, point y, point z);
	triangle(const triangle &T);
	void move_by_vector(double x, double y);
	void rotate(point p, double angle);
	double get_perimeter();
	double get_area();
	point get_middle_point();
	double sign(point p1, point p2, point p3);
	bool is_point_in(point p1);
	bool notDifferent();
	bool collinear();
};

//bool if_contains(triangle bigger, triangle smaller);
//bool if_separable(triangle t1, triangle t2);
