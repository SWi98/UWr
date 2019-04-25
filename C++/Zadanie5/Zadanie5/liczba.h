#pragma once
#include "wyrazenie.h"
class liczba : wyrazenie {
public:
	double get();
	void set();
private:
	double val; 
};