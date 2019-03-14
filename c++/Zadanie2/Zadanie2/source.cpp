#include <iostream>
#include <cstdlib>
#include <math.h>
#include "point.h"
#include "segment.h"
#include "triangle.h"
int main() {
	/*point x(1, 1);
	point z(0, 0);
	point y(2, 2);
	point y2(0.5, 0.5);
	segment seg(x, z);
	seg.write_line_formula();
	cout << seg.point_in_segment(y);
	cout << seg.point_in_segment(y2) << endl;*/
	point a(0, 0);
	point b(0, 1);
	point c(1, 0);
	triangle X(a, b, c);
	cout << "Trojkat o punktach w:" << endl;
	a.write();
	b.write();
	c.write();
	double p = X.get_area();
	double obw = X.get_perimeter();
	cout << "p: " << p << ", obw: " << obw;
	
	getchar();
}