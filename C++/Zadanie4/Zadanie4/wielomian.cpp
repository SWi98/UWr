#include <iostream>
#include <algorithm>
#include "wielomian.h"

using namespace std;

wielomian::wielomian() {
	this->n = 0;
	this->a = new double[1];
	this->a[0] = 1.0;
}

wielomian::wielomian(int st, const double wsp[]) {
	if(st < 0)
		throw(invalid_argument("st lower than 0"));
	this->n = st;
	this->a = new double[n+1];
	if (wsp[n] == 0 && st!=0)
		throw(invalid_argument("Leading coefficient equals 0"));
	for (int i = 0; i < n+1; i++) {
		this->a[i] = wsp[i];
	}
}

wielomian::wielomian(initializer_list<double> wsp) {
	if (wsp.size() == 0)
		throw(invalid_argument("Empty list of arguments"));
	this->n = wsp.size() - 1;
	this->a = new double[n+1];
	int i = 0;
	for (double x : wsp) {
		if (i == n && x == 0 && this->n != 0)
			throw(invalid_argument("Leading coefficient equals 0"));
		this->a[i] = x;
		i++;
	}
}

wielomian::wielomian(const wielomian &W) {
	this->n = W.n;
	this->a = new double[n+1];
	//for (int i = 0; i <= n; i++)
	//	this->a[i] = W.a[i];
	copy(W.a, W.a + n + 1, this->a);
}

wielomian::wielomian(wielomian &&W) {
	this->n = W.n;
	this->a = W.a;
	W.a = nullptr; 
	W.n = 0;
}

wielomian& wielomian::operator = (const wielomian &W) {
	this->n = W.n;
	delete[] this->a;
	this->a = new double[n + 1];
	copy(W.a, W.a + n + 1, this->a);
	return *this;
}

wielomian& wielomian::operator = (wielomian &&W) {
	if (this == &W) {
		throw(invalid_argument("W is the same object"));
	}
	else {
		delete[] this->a;

		this->a = W.a;
		this->n = W.n;

		W.a = nullptr;
		W.n = 0;
	}
	return *this;
}

wielomian::~wielomian() {
	delete[] a;
	a = nullptr;
}

double wielomian::oblicz(double val) {
	double b = this->a[n];
	for (int i = n-1; i >= 0; i--) {
		b = this->a[i] + b * val;
	}
	return b;
}

double wielomian::operator () (double val) {
	double b = this->a[n];
	for (int i = n - 1; i >= 0; i--) {
		b = this->a[i] + b * val;
	}
	return b;
}

double wielomian::operator [] (int i) {
	if (i < 0 || i > this->n)
		throw(invalid_argument("Wrong index"));
	return this->a[i];
}

wielomian operator + (const wielomian& A, const wielomian& B) {
	int n = max(A.n, B.n);
	double *wsp = new double[n + 1];

	for (int i = 0; i < n + 1; i++)
		wsp[i] = 0;
	for (int i = 0; i <= A.n; i++)
		wsp[i] += A.a[i];
	for (int i = 0; i <= B.n; i++)
		wsp[i] += B.a[i];

	int iter = n;
	bool changed = false;
	while (!changed && iter >= 0) {
		if (wsp[iter] != 0) {
			n = iter;
			changed = true;
		}
		iter--;
	}
	if (!changed) {
		n = 0;
	}
	double *updatedWsp = new double[n];
	for (int i = 0; i <= n; i++)
		updatedWsp[i] = wsp[i];
	delete[] wsp;
	return wielomian(n, updatedWsp);
}

wielomian operator - (const wielomian &A, const wielomian &B) {
	int n = max(A.n, B.n);
	double *wsp = new double[n + 1];

	for (int i = 0; i < n + 1; i++)
		wsp[i] = 0;
	for (int i = 0; i <= A.n; i++)
		wsp[i] += A.a[i];
	for (int i = 0; i <= B.n; i++)
		wsp[i] -= B.a[i];

	int iter = n;
	bool changed = false;
	while (!changed && iter >= 0) {
		if (wsp[iter] != 0) {
			n = iter;
			changed = true;
		}
		iter--;
	}
	if (!changed) {
		n = 0;
	}
	double *updatedWsp = new double[n];
	for (int i = 0; i <= n; i++)
		updatedWsp[i] = wsp[i];
	delete[] wsp;
	return wielomian(n, updatedWsp);
}

wielomian operator * (const wielomian &u, const wielomian &v) {
	int n = u.n + v.n;
	double * wsp = new double[n + 1];
	for (int i = 0; i <= n; i++)
		wsp[i] = 0;

	for (int i = 0; i <= u.n; i++) {
		for (int j = 0; j <= v.n; j++) {
			wsp[i + j] += u.a[i] * v.a[j];
		}
	}
	int iter = n;
	bool changed = false;
	while (!changed && iter >= 0) {
		if (wsp[iter] != 0) {
			n = iter;
			changed = true;
		}
		iter--;
	}
	if (!changed) {
		n = 0;
	}
	double *updatedWsp = new double[n];
	for (int i = 0; i <= n; i++)
		updatedWsp[i] = wsp[i];
	delete[] wsp;
	return wielomian(n, updatedWsp);
}

wielomian operator * (const double c, const wielomian&B) {
	double *wsp = new double[B.n + 1];
	for (int i = 0; i < B.n + 1; i++)
		wsp[i] = B.a[i] * c;
	return wielomian(B.n, wsp);
}

wielomian& wielomian::operator += (const wielomian &v) {
	//wielomian *temporary = this;
	*this = *this + v;
	//cout << temporary << " " << this << endl;
	return *this;
}

wielomian& wielomian::operator -=(const wielomian &v) {
	//wielomian *temporary = this;
	//cout << this->a << endl;
	*this = *this - v;
	//cout << this->a;
	//delete temporary;
	return *this;
}

wielomian& wielomian::operator *=(const wielomian &v) {
	//wielomian *temporary = this;
	*this = *this * v;
	//delete temporary;
	return *this;
}

wielomian& wielomian::operator *=(double c) {
	//wielomian *temporary = this;
	*this = c * *this;
	//delete temporary;
	return *this;
}

istream& operator >> (istream &we, wielomian &w) {
	we >> w.n;
	w.a = new double[w.n + 1];
	for (int i = 0; i <= w.n; i++) {
		double x; 
		we >> x;  
		w.a[i] = x;
	}
	return we;
}

ostream& operator << (ostream &wy, const wielomian &w) {
	for (int i = w.n; i >= 0; i--) {
		wy << w.a[i] << "x^" << i << " ";
	}
	wy << endl;
	return wy;
}

void wielomian::wypisz() {
	cout << "stopien: " << this->n << endl;
	cout << "  " << this->a[2] << "     " << endl;
	for (int i = this->n; i >= 0; i--) {
		cout << this->a[i] << "x^" << i << " ";
	}
	cout << endl;
}

