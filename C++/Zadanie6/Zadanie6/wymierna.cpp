#include "wymierna.h"
using namespace std;

int gcd(int a, int b) {
	if(b > a)
		swap(a, b);
	if (b == 0)
		return a;
	a %= b;
	return gcd(b, a);
}

wymierna::wymierna(int l, int m) {
	if (m == 0)
		throw(invalid_argument("m = 0"));
	if (m < 0) {
		m = -1 * m;
		l = -1 * l;
	}
	int g = gcd(abs(l), abs(m));
	this->licz = l / g;
	this->mian = m / g;
}



int wymierna::get_licz() {
	return this->licz;
}
int wymierna::get_mian() {
	return this->mian;
}