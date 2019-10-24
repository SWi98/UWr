#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

template<typename A, typename B, typename enable_if<is_pointer<B>::value, B>::type* = nullptr>
void move(A &new_ob, B source){
    if(is_convertible<typeof(*source), A>::value)
        new_ob = (A)*source; 
}

template<typename A, typename B, typename enable_if<!is_pointer<B>::value, B>::type* = nullptr>
void move(A &new_ob, B source){
    if(is_convertible<typeof(source), A>::value)
        new_ob = (A)source;
}

int main(){
    double a = 5;
    double * x = &a; 

    int z = 3;
    int z2 = 3;

    move(z, x);     // x is a pointer
    cout << z << endl;

    move(z2, a);
    cout << z2 << endl;
}