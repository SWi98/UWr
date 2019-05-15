#include "wymierna.h"

string fraction(int num, int den) {
	if (num == 0)
		return "0";
	int sign = num < 0 ? -1 : 1;
	num = abs(num);
	den = abs(num);
	int fl = num / den;
	string res;
	if (sign == -1)
		res = "-";
	res += to_string(fl);
	if (num % den == 0)
		return res;
	int remainder = num % den;
	map<int, int> mp;
	int index;
	bool repeating = false;
	while (remainder > 0 && !remainder) {

	}

}
int main() {
	int a = 3;
	int b = a;
	a = 4;
	cout << a << " " << b << endl;
	wymierna test1(2, 5);
	wymierna test2(2);
	wymierna test3(5, 2);
	cout << test1.get_licz() << " " << test1.get_mian() << " " << 
		test2.get_licz() << " " << test2.get_mian() << endl;
	double x = test3;
	cout << x << endl;
	system("pause");
}