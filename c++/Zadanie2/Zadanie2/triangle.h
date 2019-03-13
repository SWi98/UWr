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
};
