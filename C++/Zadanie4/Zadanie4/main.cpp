#include<iostream>
#include "wielomian.h"
using namespace std;
int main() {
	wielomian test1 = wielomian(initializer_list<double>{1, 1});
	wielomian test2 = wielomian(initializer_list<double>{3, 4, 5, 6});
	wielomian test3, test4;
	//test3 = test1;
	//test3 += test2;
	cout << test1 << test2 << test3;
	test3 = test2 + test1; 
	test4 = test2;
	test4 += test1;
	test3.wypisz();
	test4.wypisz();
	test4 = (test4 - test3) + 10.0 * test1;
	cout << test4;
	//cin >> test3;
	//cout << test3;
	cout << endl;
	wielomian w = wielomian(initializer_list<double>{4.0, 2.0});
	wielomian ww;
	ww = w * w;
	cout << ww;
	system("pause");
}