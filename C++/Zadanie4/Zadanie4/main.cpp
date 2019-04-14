#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "wielomian.h"
using namespace std;
int main() {
	for (int i = 0; i <= 10000000; i++) {
		wielomian test1 = wielomian(initializer_list<double>{1, 1});
		wielomian test2 = wielomian(initializer_list<double>{3, 4, 5, 6});
		wielomian test3, test4;
		test3 = test1;
		test3 = test2 + test1;
	}
	cout
	_CrtDumpMemoryLeaks();
		/*cout << "test1 = wielomian(initializer_list<double>{1, 1}) -> " << test1 <<
			"test2 = wielomian(initializer_list<double>{3, 4, 5, 6}) -> " << test2 <<
			"wielomian test3; -> " << test3;
		test3 = test2 + test1;
		test4 = test2;
		test4 += test1;
		cout << "test3 = test2 + test1 -> " << test3 << "test4 = test2; test4 += test1 -> " << test4;
		test4 = (test4 - test3);
		cout << "test4 = (test4 - test3) -> " << test4;
		wielomian test5 = (test4 * test2);
		cout << "wielomian test5 = (test4 * test2) -> " << test5;
		cout << endl;
		wielomian w = wielomian(initializer_list<double>{4.0, 2.0});
		wielomian y = wielomian(initializer_list<double>{-10.0, 4.0, -2.0});
		wielomian ww;
		ww = w * y;
		cout << "(2x^1 4x^0) * (-2x^2 4x^1 -10x^0) -> " << ww;
		cout << "Wpisz stopien wielomianu, a nastepnie jego wspolczynniki: \n";
		wielomian test6;
	}
		cin >> test6;
		cout << test6;
		cout << "pomnozony przez 20 = ";
		test6 *= 20;
		cout << test6;
		cout << test6(1) << endl;
		cout << test6[2] << endl; */
	
	system("pause");
}