#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


vector<bool> is_prime;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    long long int N = a*b*c + 1;
    is_prime.resize(N, true);
    vector<int> d(N, 0);
    for (int i = 1; i < N; i++){
        for (int j = i; j < N; j += i){
            d[j]++;
        }
    }
    long long int sum = 0;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++){
                sum += d[i*j*k] % 1073741824;
            }
        }
    }
    cout << sum << endl;
}