#include <iostream>
#include <set>
#include<math.h>

using namespace std;

void Zad1(){
    cout << "??=" << endl;  
}

void Zad2(){
    cout <<"\n-----------------------------\n\n";
    cout << " \?\?\"))))))\"\"\"(\" "<< endl;
}

void Zad3(){
    cout <<"\n-----------------------------\n\n";
    using custom = set <string>;
    custom my_set {"jeden", "dwa", "trzy"};
  //  for (auto iter = my_set.begin(); iter != my_set.end(); iter++){
   //     cout << iter << endl;     CZEMU NIE DZIAŁA?
   // }

    for (auto iter : my_set){
        cout << iter << endl;
    }
}

enum class Names : uint16_t {Szymon, Igor, Dawid}; 

void Zad4(string name, Names n){
    cout <<"\n-----------------------------\n\n";

    switch(n){
        case Names::Szymon:
        cout << "Szymon: " << name << endl;
        break;
        case Names::Igor:
        cout << "Igor: " << name << endl;
        break;
        case Names::Dawid:
        cout << "Dawid: " << name << endl;
        break;
    }
}

auto Zad5(int n){
    if(n == 0)
        return 2;
    
    else if(n == 1)
        return 1;
    
    else
        return Zad5(n-1) + Zad5(n-2);
}


void Zad6(double a, double b, double c){
    if(auto delta = b * b - 4 * a * c; delta >= 0){
        if(delta == 0){
            cout << -b / (2 * a) << endl;
        }
        else{
            cout << (-b + sqrt(delta))/(2*a) << ",   " << (-b - sqrt(delta))/(2*a) << endl; 
        }
    }
    else{
        cout << "Brak" << endl;
    }
}

int main(){  
    Zad1();
    Zad2();
    Zad3();
    Zad4("abc", Names::Szymon);
    cout <<"\n-----------------------------\n\n";
    cout << "Liczby Lucasa: 5, 0 i 40: \n";
    cout << Zad5(5) << " " << Zad5(10) << " " << Zad5(40) << endl;
    //cout << typeid(Zad5(5)).name() << " " << typeid(Zad5(100)).name() << endl;
    cout <<"\n-----------------------------\n\n";
    cout << "x^2:  ";
    Zad6(1, 0, 0);
    cout << "x^2 - 4x + 3:  ";
    Zad6(1, -4, 3);
    cout << "5x^2 + 100:  ";
    Zad6(5, 0, 100);
}