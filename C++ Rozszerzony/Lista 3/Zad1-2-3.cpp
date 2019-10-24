#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <tgmath.h>
#include <ratio>
#include <vector>

using namespace std;

void zad1(){
    cout << numeric_limits<long long int>::max() << endl;
    cout << numeric_limits<long long int>::min() << endl;
    cout << numeric_limits<long long int>::digits10 << endl; 
    cout << numeric_limits<long long int>::digits << endl;
}

void zad2(){
    cout << "Najmniejszy double: " << numeric_limits<double>::min() << endl;
    cout << "Największy ujemny double: " << -numeric_limits<double>::min() << endl;
    cout << "Największy double: " << numeric_limits<double>::max() << endl;
    cout << 1.0 - numeric_limits<double>::min() << "\n\n";

    cout << "Najmniejszy float: " << numeric_limits<float>::min() << endl;
    cout << "Największy ujemny float: " << -numeric_limits<float>::min() << endl;
    cout << "Największy float: " <<numeric_limits<float>::max() << endl;
    cout << (float)1.0 - numeric_limits<float>::min() << endl;
}

void zad3(){
    typedef ratio<1, 1> first; 
    typedef ratio_add<first, ratio<1, 2>> second; 
    typedef ratio_add<second, ratio<1, 3>> third;
    typedef ratio_add<third, ratio<1, 4>> fourth; 
    cout << first::num << " / " << first::den << endl;
    cout << second::num << " / " << second::den << endl;
    cout << third::num << " / " << third::den << endl;
    cout << fourth::num << " / " << fourth::den << endl;
}


int main(){
    zad1();
    cout << endl;
    zad2();
    cout << endl;
    zad3();
}