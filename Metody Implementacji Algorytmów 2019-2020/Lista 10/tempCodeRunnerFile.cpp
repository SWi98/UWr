#include <iostream>
using namespace std;

int main(){
    int a, b, a2;
    cin >> a >> b;
    a2 = a;
    int x = a / b;
    int X = x + 1;
    int diff = a - (x * b);
    for(int i = 0; i < diff; i++){
        cout << x << " ";
        a2 -= x;
    }
    while(a2 > 0){
        cout << X << " ";
        a2 -= X;
    }
}