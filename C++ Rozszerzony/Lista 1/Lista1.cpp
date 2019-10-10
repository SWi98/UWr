#include <iostream>
#include <set>

using namespace std;

void Zad1(){
    cout << "??=" << endl;  
}

void Zad2(){
    cout <<"-----------------------------\n";
    cout << " \?\?\"))))))\"\"\"(\" "<< endl;
}

void Zad3(){
    cout <<"-----------------------------\n";
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
    cout <<"-----------------------------\n";

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

int main(){  
    Zad1();
    Zad2();
    Zad3();
    Zad4("abc", Names::Szymon);
    cout <<"-----------------------------\n";
    cout << Zad5(5) << " " << Zad5(10) << " " << Zad5(100) << endl;
    cout << typeid(Zad5(5)).name() << " " << typeid(Zad5(100)).name() << endl;
}