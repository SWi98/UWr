#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int y;
    cin >> y;
    for(int i = y+1; true; i++){
        int a, b, c, d, i2 = i;
        a = i2 % 10;
        i2 /= 10;
        b = i2 % 10;
        i2 /= 10;
        c = i2 % 10;
        i2 /= 10;
        d = i2 % 10;
        if(!(a == b || a == c || a == d || b == c || b == d || c == d)){
            cout << i;
            return 0;
        }
    }
}