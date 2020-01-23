#include <iostream>
#include <vector>
using namespace std;

template<int n>
class Lucas {
public:
	static constexpr long long int val = Lucas<n - 1>().val + Lucas<n - 2>().val;
};

template<>
class Lucas<1> {
public:
	static constexpr long long int val = 1;
};

template<>
class Lucas<0> {
public:
	static constexpr long long int val = 2;
};


template<int n, int k>
class Binomial {
public:
	static constexpr int val = Binomial<n - 1, k>().val + Binomial<n - 1, k - 1>().val;
};

template<int n>
class Binomial<n, n> {
public:
	static constexpr int val = 1;
};

template<int n>
class Binomial<n, 1> {
public:
	static constexpr int val = n;
};

template<int a, int b>
class GCD {
public:
	static constexpr int val = GCD<b, a % b>().val;
};

template<int a>
class GCD<a, 0> {
public:
	static constexpr int val = a;
};

int main() {
	cout << Lucas<0>().val << endl;
	cout << Lucas<1>().val << endl;
	cout << Lucas<2>().val << endl;
	cout << Lucas<3>().val << endl;
	cout << Lucas<4>().val << endl;
	cout << Lucas<5>().val << endl;
	cout << Lucas<6>().val << endl;
	cout << endl;
	cout << "(5 4) = " << Binomial<5, 4>().val << endl;
	cout << "(10 1) = " << Binomial<10, 1>().val << endl;
	cout << "(12 10) = " << Binomial<12, 10>().val << endl;
	cout << "(4 2) = " << Binomial<4, 2>().val << endl;
	cout << endl;
	cout << "GCD(10, 4) = " << GCD<10, 4>().val << endl;
	cout << "GCD(25, 15) = " << GCD<25, 15>().val << endl;
	cout << "GCD(13, 7) = " << GCD<13, 7>().val << endl;
	cout << "GCD(84, 126) = " << GCD<84, 126>().val << endl;

}