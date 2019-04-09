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
	cout << "--------------------------\n";
	point a(0, 0);
	point b(0, 1);
	point c(1, 0);
	triangle X(a, b, c);
	double p = X.get_area();
	double obw = X.get_perimeter();
	cout << "pole: " << p << ", obw: " << obw << ", pkt srodkowy: ";
	X.get_middle_point().write();
	point d(0.1, 0.1);
	cout << "Punkt o wspolrzednych: ";
	d.write();
	cout << "Czy znajduje sie w trojkacie? ";
	cout << X.is_point_in(d) << "\n\n";
	triangle H(point(0, 0), point(0, 0.2), point(0.2, 0));
	cout << "Czy znajduje sie w trojkacie stworzonym wczesniej? " << if_contains(X, H) << endl;
	cout << "----------------------------\n";
	point k(0, 0);
	point l(1, 1);
	segment OX(k, l);
	cout << "Prosta z punktami: \n";
	k.write();
	l.write();
	cout << "wsp. a = " << OX.getCoefficientA() << ", wsp. b = " << OX.getCoefficientB();
	point k2(-1, 0);
	point l2(0, 1);
	segment OX2(k2, l2);
	cout << "\n\nProsta z punktami: \n";
	k2.write();
	l2.write();
	cout << "wsp. a = " << OX2.getCoefficientA() << ", wsp. b = " << OX2.getCoefficientB();
	cout << "\n\nCzy sa rownolegle? " << if_parallel(OX2, OX);
	cout << "\nCzy sa prostopadle? " << if_perp(OX2, OX) << endl;

	point z1(0, 0), z2(0, 0), z3(500, 1);
	//triangle Z(z1, z2, z3);

	point O(101, 101);
	O.rotate(point(100, 100), 90);
	O.write();
	getchar();
}