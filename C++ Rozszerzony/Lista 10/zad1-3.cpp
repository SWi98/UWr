#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Lucas{
    public:
    Lucas(){
        a = 2;
        b = 1;
    }
    T operator ()(int n){
        a = 2;
        b = 1;
        if(n == 0){
            return a;
        }
        else if (n == 1){
            return b;
        }
        else{
            for(int i = 2; i <= n; i++){
                b = a + b;
                a = b - a;
            }
            return b;
        }
    }
    private:
    T a;
    T b;
};

template<typename T>
class Newton{
    public:
    T operator ()(int n, int k){
        long long int n_fact;
        long long int k_fact;
        long long int subtr_fact;
        long long int acc = 1;
        if(n - k == 0){
            subtr_fact = 1;
        }
        for(int i = 1; i <= n; i++){
            acc *= i;
            if (i == n){
                n_fact = acc;
            }
            if (i == k){
                k_fact = acc;
            }
            if (i == n - k){
                subtr_fact = acc;
            }
        }
        T res = n_fact / ((k_fact) * (subtr_fact));
        return res;
    }
};

template<typename T>
class GCD{
    public:
    T operator ()(T a, T b){
        return compute(a, b);
    }
    private:
    T compute(T a, T b){
        if (a % b == 0){
            return b;
        }
        else{
            return compute(b, a % b);
        }
    }
};


int main(){
    Lucas<int> lucas;
    for(int i = 0; i < 10; i++){
        cout << lucas(i) << endl;
    }
    cout << endl;

    Newton<int> newton;
    cout << newton(10, 2) << endl;
    cout << newton(2, 2) << endl;
    cout << newton(5, 3) << endl;
    cout << newton(8, 7) << endl;
    cout << endl;

    GCD<int> gcd;
    cout << gcd(60, 190) << endl;
    cout << gcd(27, 2700) << endl;
    cout << gcd(5, 7) << endl;
    cout << gcd(712, 123) << endl;
    cout << gcd(46, 82) << endl;

}