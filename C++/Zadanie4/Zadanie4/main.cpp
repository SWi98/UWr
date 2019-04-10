#include<iostream>
#include "wielomian.h"
using namespace std;
int main() {
	wielomian test1 = wielomian(initializer_list<double>{1, 1});
	wielomian test2 = wielomian(initializer_list<double>{3, 4, 5, 6});
	wielomian test3;
	//test3 = test1;
	//test3 += test2;
	/*test1.wypisz();
	test2.wypisz();
	test3.wypisz();
	test3 = test2 + test1;
	test4 = test2;
	test4 += test1;
	test3.wypisz();
	test4.wypisz();*/
	cin >> test3;
	cout << test3;
	system("pause");
}