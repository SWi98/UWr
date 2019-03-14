#include <iostream>
#include <cstdlib>
#include <math.h>
#include "point.h"
#include "segment.h"
#include "triangle.h"
int main() {
	point q(5, 10);
	point test(0, 0);
	cout << "pkt o wspolrzednych: ";
	q.write();
	cout << "po przesunieciu o wektor (3, -2): ";
	q.move_by_vector(3, -2);
	q.write();
	point p1(8, 8); point p2(9, 9);
	segment S(p1, p2);
	cout << "Odcinek: ";
	S.write();
	S.rotate(test, 90.0);
	cout << "Po obroceniu o 90 stopni wokol (0, 0): ";
	S.write();
	
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
	cout << "pole: " << p << ", obw: " << obw << ", pkt srodkowy: ";
	X.get_middle_point().write();
	point d(0.1, 0.1);
	cout << "Punkt o wspolrzednych: ";
	d.write();
	cout << "Czy znajduje sie w trojkacie? ";
	cout << X.is_point_in(d) << endl;
	triangle H(point(0, 0), point(0, 0), point(0, 0));
	
	getchar();
}