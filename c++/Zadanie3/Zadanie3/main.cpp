#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "queue.h"
using namespace std;

int main() {
	queue *q = new queue(initializer_list<string>{"jeden", "dwa", "trzy"});
	q->write();
	queue *newQ = new queue(4);
	newQ->put("1234");
	newQ->write();
	newQ = q;
	newQ->write();
	//delete q;
	bool test = true;
	string param, choose;
	while (test) {
		cout << "1. Create new queue. Enter parameter (int)" << endl
			<< "2. Add element. Enter parameter (string)" << endl
			<< "3. Take one element." << endl
			<< "4. Show first element." << endl
			<< "5. Exit" << endl;
		cin >> choose;
		switch (stoi(choose)) {
			case 1:
				delete q;
				cin >> param;
				try {
					q = new queue(stoi(param));
				}
				catch(exception &e){
					queue *q = new queue();
					clog << e.what() << endl << "Default queue created" << endl;
				}
				break;
			case 2:
				cin >> param;
				try {
					q->put(param);
				}
				catch (exception &e) {
					clog << e.what() << endl;
				}
				break;
			case 3:
				try {
					string elem = q->get();
					cout << "Taken element: " << elem << endl;
				}
				catch (exception &e) {
					clog << e.what() << endl;
				}
				break;
			case 4:
				try {
					q->write();
				}
				catch (exception &e) {
					clog << e.what() << endl;
				}
				break;
			case 5:
				test = false;
				break;
		}

	}
}