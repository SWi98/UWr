#pragma once
#include <iostream>
using namespace std;

class point {
private:
	double x;
	double y;
public:
	point(double a, double b);
	point();
	void move_by_vector(double a, double b);
	void write();
	double get_x();
	double get_y();
	void rotate(point p, double angle);
};

double get_distance(point a, point b);