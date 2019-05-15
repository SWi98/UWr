#pragma once
#include<iostream>
using namespace std;
namespace wyjatek_wymierny {
	class wyjatek_wymierny : exception {
	};
	class dzielenie_przez_0 : wyjatek_wymierny {
	public:
		const char * what() const throw() {
			return "Dzielenie przez 0";
		}
	};

	class przekroczenie_zakresu : wyjatek_wymierny {
	public:
		const char * what() const throw() {
			return "Przekroczenie zakresu";
		}
	};
}