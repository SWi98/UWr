#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    a = 6 - max(a, b) + 1;
    b = 6;
    int i = 0;
    while(true){
        if(a % 2 == 0 && b % 2 == 0){
            a /= 2;
            b /= 2;
        }
        else if(a % 3 == 0 && b % 3 == 0){
            a /= 3;
            b /= 3;
        }
        else{
            break;
        }
    }
    cout << a << "/" << b << endl;
}