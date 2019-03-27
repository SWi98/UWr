#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "queue.h"
using namespace std;

int main() {
	queue testQ = new queue(10);
	testQ.put("pierwszy");
	testQ.put("drugi");
	testQ.put("trzeci");
	testQ.write();
	string first = testQ.get();
	string snd = testQ.get();
	string third = testQ.get();
	cout << first << snd << third << endl;
	getchar();
}