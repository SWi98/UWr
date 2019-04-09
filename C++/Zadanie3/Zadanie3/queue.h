#pragma once
#include <iostream>
#include <list> 
#include <iterator>
#include <string>
using namespace std;

class queue {
private:
	int pojemnosc, ile, pocz;
	string *qArray;
public:
	~queue();
	queue();
	queue(int capacity);
	queue(const queue &Q);
	queue(queue && otherQ);
	queue(initializer_list<string> InitList);
	queue& operator=(const queue &otherQ);
	queue& operator=(queue&& otherQ) noexcept;
	string get();
	void put(string arg);

	void write(); // for tests only

};