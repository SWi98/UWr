#include "wymierna.h"
using namespace obliczenia;



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
		cout << test1minus2.get_whole() << " = ";
		cout << test1minus2 << endl;
		double x = (double)test1;
		int y = (int)test2;
		wymierna test_okres(3, 70);
		cout << "3/70 = " << test_okres << endl;
	}
	system("pause");
}