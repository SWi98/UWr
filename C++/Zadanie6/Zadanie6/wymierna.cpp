#include "wymierna.h"
#include "wyjatek_wymierny.h"
using namespace std;
using namespace obliczenia;
using namespace wyjatek_wymierny;

namespace obliczenia {
	wymierna::wymierna(int l, int m) {
		if (m == 0)
			throw(dzielenie_przez_0());
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
			throw(przekroczenie_zakresu());
		return wymierna((int)new_licz, (int)new_mian);
	}

	wymierna operator - (const wymierna &W1, const wymierna &W2) {
		long long int new_licz = W1.licz * W2.mian - W2.licz * W1.mian;
		long long int new_mian = W1.mian * W2.mian;
		long long int new_gcd = gcd(new_licz, new_mian);
		new_licz /= new_gcd;
		new_mian /= new_gcd;
		if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
			throw(przekroczenie_zakresu());
		return wymierna((int)new_licz, (int)new_mian);
	}

	wymierna operator * (const wymierna &W1, const wymierna &W2) {
		long long int new_licz = W1.licz * W2.licz;
		long long int new_mian = W1.mian * W2.mian;
		long long int new_gcd = gcd(new_licz, new_mian);
		new_licz /= new_gcd;
		new_mian /= new_gcd;
		if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
			throw(przekroczenie_zakresu());
		return wymierna((int)new_licz, (int)new_mian);
	}

	wymierna operator / (const wymierna &W1, const wymierna &W2) {
		long long int new_licz = W1.licz * W2.mian;
		long long int new_mian = W1.mian * W2.licz;
		long long int new_gcd = gcd(new_licz, new_mian);
		new_licz /= new_gcd;
		new_mian /= new_gcd;
		if (abs(new_licz) > INT_MAX || abs(new_mian) > INT_MAX)
			throw(przekroczenie_zakresu());
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

	string wymierna::get_whole() {
		string res = "";
		res += to_string(this->licz) + "/" + to_string(this->mian);
		return res;
	}
	ostream& operator<<(ostream &wyj, const wymierna &W) {
		wyj << fraction(W.licz, W.mian);
		return wyj;
	}

	// geeksforgeeks
	string fraction(int num, int den) {
		string res = "";
		string start = to_string(num / den) + ",";
		// Create a map to store already seen remainders, remainder is used as key and its position in 
		// result is stored as value. 
		map<int, int> mp;
		mp.clear();
		int rem = num % den;
		while ((rem != 0) && (mp.find(rem) == mp.end())) {
			mp[rem] = res.length();
			rem = rem * 10;
			int res_part = rem / den;
			res += to_string(res_part);
			rem = rem % den; \
		}
		start += res;
		start.insert(start.size() - res.substr(mp[rem]).size(), "(");
		start += ")";
		return (rem == 0) ? "" : start; // res.substr(mp[rem]);
	}
}



/*wymierna::~wymierna() {
	delete &this->licz;
	delete &this->mian;
}*/

