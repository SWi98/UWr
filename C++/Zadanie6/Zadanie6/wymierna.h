#pragma once
#include<iostream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<math.h>
#include<string>
#include<map>
using namespace std;

namespace obliczenia {
	class wymierna {

	private:
		int licz, mian;
	public:
		wymierna(int l, int m);
		wymierna(int l) :wymierna(l, 1) {};
		int get_licz();
		int get_mian();
		wymierna(const wymierna &W);
		wymierna& operator = (const wymierna &W);
		friend wymierna operator + (const wymierna &W1, const wymierna &W2);
		friend wymierna operator - (const wymierna &W1, const wymierna &W2);
		friend wymierna operator * (const wymierna &W1, const wymierna &W2);
		friend wymierna operator / (const wymierna &W1, const wymierna &W2);
		friend wymierna operator - (const wymierna &W1);
		friend wymierna operator ! (const wymierna &W1);
		operator double() const;
		operator int() const;
		string get_whole();
		friend ostream& operator <<(ostream &wyj, const wymierna &W);
		//~wymierna();
	};
	
}
