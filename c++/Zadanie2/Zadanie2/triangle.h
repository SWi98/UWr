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
	void move_by_vector(double x, double y);
	void rotate(point p, double angle);
	double get_perimeter();
	double get_area();
	point get_middle_point();
	bool if_point_inside(point k);
};

//bool if_contains(triangle bigger, triangle smaller);
//bool if_separable(triangle t1, triangle t2);
