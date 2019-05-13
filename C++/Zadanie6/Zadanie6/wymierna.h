#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

class wymierna {

private:
	int licz, mian;
public:
	wymierna(int l, int m);
	wymierna(int l) :wymierna(l, 1) {};
	int get_licz();
	int get_mian();

};
