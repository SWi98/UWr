#include <iostream>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        long long int b, d;
        cin >> b >> d;
        long long int g = __gcd(b, d);
        cout << (b-1) / (d/g) << endl;
        //cout << floor(double((b-1)*1.0 / (d*1.0 / g*1.0))) << endl;
    }
}