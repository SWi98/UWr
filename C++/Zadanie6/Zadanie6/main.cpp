#include "wymierna.h"
using namespace obliczenia;

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
	for (int i = 0; i < 1; i++) {
		wymierna test1(3, 5);
		wymierna test2(10, 5);
		wymierna test1plus2 = test1 + test2;
		wymierna test1minus2 = test1 - test2;
		wymierna test1razy2 = test1 * test2;
		wymierna test1przez2 = test1 / test2;
		cout << test1.get_whole() << " +  " << test2.get_whole() << " = " << test1plus2.get_whole() << endl;
		cout << test1.get_whole() << " -  " << test2.get_whole() << " = " << test1minus2.get_whole() << endl;
		cout << test1.get_whole() << " *  " << test2.get_whole() << " = " << test1razy2.get_whole() << endl;
		cout << test1.get_whole() << " /  " << test2.get_whole() << " = " << test1przez2.get_whole() << endl;
		cout << "!" << test1minus2.get_whole() << " = ";
		test1minus2 = !test1minus2;
		cout << test1minus2.get_whole() << endl;
		cout << "-1 * " << test1minus2.get_whole() << " = ";
		test1minus2 = -test1minus2;
		cout << test1minus2.get_whole() << endl;
		cout << test1minus2 << endl;
		int * n = new int(5);
		cout << n << endl;
		cout << *n << endl;
		cout << &n << endl << endl;
		int &x = *n; 
		*n = 2;
		cout << n << endl;
		cout << x << endl;
	}
	system("pause");
}