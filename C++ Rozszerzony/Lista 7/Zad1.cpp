#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

complex<double> EulerGamma(complex<double> z, int n){
    complex<double> res(1.0, 0.0);
    for(double i = 1; i <= n; i++){
        complex<double> num = pow(1 + 1.0/i, z);
        complex<double> den = 1.0 + z/i;
        res *= num/den;
    }
    return res/z;
}

complex<double> EulerGammaInverse(complex<double> z, int n){
    complex<double> res(1.0, 0.0);
    for(double i = 1; i <= n; i++){
        res *= (1.0 + z / i) * exp(-z / i);
    }
    return res * z * exp(0.5772156649 * z);
}

int main(){
    complex<double> test(0.5, 0.5);

    complex<double> EG= EulerGamma(test, 100000);
    cout << EG << endl;
    cout << arg(EG) << endl << endl;

    complex<double> EGI = EulerGammaInverse(test, 100000);
    cout << EGI << endl;
    cout << arg(EGI) << endl << endl;

    cout << EG * EGI<< endl;
    
}