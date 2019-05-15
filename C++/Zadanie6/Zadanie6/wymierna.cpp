#include "wymierna.h"
using namespace std;

/*int gcd(int a, int b) {
	if(b > a)
		swap(a, b);
	if (b == 0)
		return a;
	a %= b;
	return gcd(b, a);
}*/

wymierna::wymierna(int l, int m) {
	if (m == 0)
		throw(invalid_argument("m = 0"));
	if (m < 0) {
		m = -1 * m;
		l = -1 * l;
	}
	int g = gcd(l, m);
	this->licz = l / g;
	this->mian = m / g;
}

int wymierna::get_licz() {
	return this->licz;
}

int wymierna::get_mian() {
	return this->mian;
}

wymierna::wymierna(const wymierna &W) {
	this->licz = W.licz;
	this->mian = W.mian;
}

wymierna& wymierna::operator = (const wymierna &W) {
	this->licz = W.licz;
	this->mian = W.mian;
	return *this;
}

wymierna operator + (const wymierna &W1, const wymierna &W2) {
	long long int new_licz = W1.licz * W2.mian + W2.licz * W1.mian;
	long long int new_mian = W1.mian * W2.mian;
	long long int new_gcd = gcd(new_licz, new_mian);
	new_licz /= new_gcd;
	new_mian /= new_gcd;
	if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
		throw(invalid_argument("Numbers too large"));
	return wymierna((int)new_licz, (int)new_mian);
}

wymierna operator - (const wymierna &W1, const wymierna &W2) {
	long long int new_licz = W1.licz * W2.mian - W2.licz * W1.mian;
	long long int new_mian = W1.mian * W2.mian;
	long long int new_gcd = gcd(new_licz, new_mian);
	new_licz /= new_gcd;
	new_mian /= new_gcd;
	if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
		throw(invalid_argument("Numbers too large"));
	return wymierna((int)new_licz, (int)new_mian);
}

wymierna operator * (const wymierna &W1, const wymierna &W2) {
	long long int new_licz = W1.licz * W2.licz;
	long long int new_mian = W1.mian * W2.mian;
	long long int new_gcd = gcd(new_licz, new_mian);
	new_licz /= new_gcd;
	new_mian /= new_gcd;
	if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
		throw(invalid_argument("Numbers too large"));
	return wymierna((int)new_licz, (int)new_mian);
}

wymierna operator / (const wymierna &W1, const wymierna &W2) {
	long long int new_licz = W1.licz * W2.mian;
	long long int new_mian = W1.mian * W2.licz;
	long long int new_gcd = gcd(new_licz, new_mian);
	new_licz /= new_gcd;
	new_mian /= new_gcd;
	if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
		throw(invalid_argument("Numbers too large"));
	return wymierna((int)new_licz, (int)new_mian);
}

wymierna operator - (const wymierna &W1) {
	int new_licz = -1 * W1.licz;
	return wymierna(new_licz, W1.mian);
}

wymierna operator !(const wymierna &W1) {
	return wymierna(W1.mian, W1.licz);
}

wymierna::operator double() const {
	return (double)this->licz / (double)this->mian;
}

wymierna::operator int() const {
	return this->licz / this->mian;
}

/*ostream& operator<<(ostream &wyj, const wymierna &W) {

}
/*wymierna::~wymierna() {
	delete &this->licz;
	delete &this->mian;
}*/

