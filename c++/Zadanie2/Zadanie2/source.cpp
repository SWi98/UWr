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
	point b(0, 0);
	point c(10, 2);
	point d(4, 2);
	segment A(a, b);
	segment B(c, d);
	A.write_line_formula();
	cout << "asdasdasd";
	cout << c.get_x() << " " << c.get_y() << " " << d.get_x() << " " << d.get_y() << endl;
	B.write_line_formula();
	//cout << if_perp(A, B);
	
	getchar();
}