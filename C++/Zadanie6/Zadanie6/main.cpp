#include "wymierna.h"
int main() {
	wymierna test1(2, 5);
	wymierna test2(2);
	cout << test1.get_licz() << " " << test1.get_mian() << " " << test2.get_licz() << " " << test2.get_mian() << endl;
	system("pause");
}