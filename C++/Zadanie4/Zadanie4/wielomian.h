#pragma once
#include <iostream>
using namespace std;

class wielomian {
	
private:
	int n; // stopien wielomianu
	double *a; // wspolczynniki wielomianu

public:
	wielomian();								// konstruktor bezargumentowy - tworzy jednomian
	wielomian(int st, const double wsp[]);		// konstruktor z podanym stopniem i wspolczynnikami
	wielomian(initializer_list<double> wsp);	// konstruktor z lista wspolczynnikow
	wielomian(const wielomian &W);				// konstruktor kopiujacy
	wielomian(wielomian &&W);					// konstruktor przenoszacy
	wielomian& operator = (const wielomian &W);	// przypisanie kopiujace
	wielomian& operator = (wielomian &&W);		// przypisanie przenoszace
	~wielomian();								// destruktor
	double oblicz(double val);					// Horner
	friend wielomian operator +(const wielomian &A, const wielomian &B);
	friend wielomian operator -(const wielomian &A, const wielomian &B);
	friend wielomian operator * (const wielomian &u, const wielomian &v);
	friend wielomian operator * (const double c, const wielomian&B);
	wielomian& operator += (const wielomian &v);
	wielomian& operator -= (const wielomian &v);
	wielomian& operator *= (const wielomian &v);
	wielomian& operator *= (double c);
	friend istream& operator >> (istream &we, wielomian &w);
	friend ostream& operator << (ostream &wy, const wielomian &w);
	
	void wypisz();
};




