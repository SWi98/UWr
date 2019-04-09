#include <iostream>
#include "wielomian.h"
using namespace std;

wielomian::wielomian() {
	this->n = 0;
	this->a = new double[1];
	this->a[0] = 1.0;
}

wielomian::wielomian(int st, const double wsp[]) {
	this->n = st;
	this->a = new double[n];
	for (int i = 0; i < n; i++) {
		this->a[i] = wsp[i];
	}
}

wielomian::wielomian(initializer_list<double> wsp) {
	this->n = wsp.size();
	this->a = new double[n];
	int i = 0;
	for (double x : wsp) {
		this->a[i] = x;
		i++;
	}
}

wielomian::wielomian(const wielomian &W) {
	this->n = W.n;
	this->a = new double[n];
	copy(W.a, W.a + n, this->a);
}

wielomian::wielomian(wielomian &&W) {
	this->n = W.n;
	this->a = W.a;
	W.a = nullptr; 
	W.n = 0;
}

wielomian& wielomian::operator = (const wielomian &W) = default;

wielomian& wielomian::operator = (wielomian &W) {
	if (this == &W) {
		throw(invalid_argument("W is the same object"));
	}
}

