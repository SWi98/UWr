#include <iostream>
#include <list> 
#include <iterator>
#include <string>
#include "queue.h"
using namespace std;

// Destructor
queue::~queue() {
	delete[] qArray;
}

// Default constructor
queue::queue() {
	this->pojemnosc = 1; 
	this->qArray = new string[pojemnosc];
	ile = 0;
}

queue::queue(int pojemnosc) : queue() {
	this->pojemnosc = pojemnosc;
	qArray = new string[pojemnosc];
}

// Copying constructor
queue::queue(const queue &Q) {
	this->qArray = Q.qArray;
	this->pojemnosc = Q.pojemnosc;
	this->ile = Q.ile;
	this->pocz = Q.pocz;
}

// Constructor with list of strings 
queue::queue(initializer_list<string> InitList) {
	this->pojemnosc = InitList.size();
	this->ile = InitList.size();
	this->pocz = 0;
	this->qArray = new string[pojemnosc];

	int iter = 0;
	for (string value : InitList) {
		this->qArray[iter] = value;
		iter++;
	}
}

// Copy assignment operator
queue queue::operator=(const queue &otherQ) {
	this->qArray = otherQ.qArray;
	this->pojemnosc = otherQ.pojemnosc;
	this->ile = otherQ.ile;
	this->pocz = otherQ.pocz;
	return *this;
}

// Move assignment operator
queue& queue::operator=(queue&& otherQ) {
	if (this != &otherQ) {
		delete[] this->qArray;

		this->qArray = otherQ.qArray;
		this->pojemnosc = otherQ.pojemnosc;
		this->ile = otherQ.ile;
		this->pocz = otherQ.pocz;

		otherQ.qArray = nullptr;
		otherQ.pojemnosc = 0;
		otherQ.ile = 0;
		otherQ.pocz = 0;
	}
	return *this;
}

string queue::get() {
	if (ile == 0)
		throw invalid_argument("Empty queue");

	string res = qArray[pocz];
	ile--;
	pocz = (pocz + 1) % pojemnosc;
	return res;
}

void queue::put(string arg) {
	if (ile == pojemnosc)
		throw invalid_argument("Queue is full");
	qArray[(pocz + ile) % pojemnosc] = arg;
	ile++;
}

void queue::write() {
	for (int i = 0; i < pojemnosc; i++)
		cout << i <<". " << qArray[i] << endl;
}


