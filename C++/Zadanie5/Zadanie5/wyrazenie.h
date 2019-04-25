#pragma once
#include <string>
#include <iostream>
using namespace std;

class wyrazenie {
public:
	virtual double oblicz();
	virtual string opis();
};