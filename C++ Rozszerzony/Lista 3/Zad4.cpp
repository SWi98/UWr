#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

template<typename A, typename B, typename enable_if<is_pointer<B>::value, void**>::type = nullptr>
void move(A &new_ob, B source, typename enable_if<is_convertible<decltype(*source), A>::value, void**>::type = nullptr){
    //if(is_convertible<decltype(*source), A>::value)
    new_ob = (A)*source; 
}

template<typename A, typename B, typename enable_if<is_convertible<A, B>::value>::type* = nullptr>//typename enable_if<!is_pointer<B>::value && is_convertible<A, B>::value>::type* = nullptr>
void move(A &new_ob, B source){
    if(is_convertible<decltype(source), A>::value)
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

    string str = "asdasd";
    //move(a, str);

}