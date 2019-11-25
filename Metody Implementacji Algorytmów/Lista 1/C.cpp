#include <iostream>
using namespace std;


long long int multiply_modulo(long long int a, long long int b, long long int m){
    long long int current = a % m;
    long long int res = 0;
    while(b > 0){
        if(b & 1){
            res = (res + current) % m; 
        }
        current = current * 2 % m; 
        b >>= 1;
    } 
    return res;  
} 

long long int exp_modulo(long long int a, long long int b, long long int m){
    long long int res = 1;
    a %= m;
    while(b > 0){
        if(b & 1){      //checking if 1 is the last digit in binary representation of b
            res = multiply_modulo(res, a, m);
        }
        a = multiply_modulo(a, a, m);  
        b >>= 1;        //we get rid of the last digit from binary repr. of b since we did all the essential calculations requiring this digit
    }
    return res;
}
int main(){
    int t;
    long long int N, K, M, res;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> N >> K >> M;
        cout << exp_modulo(K, N, M) << endl;
    }
}