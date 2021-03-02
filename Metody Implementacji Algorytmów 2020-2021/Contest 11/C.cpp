#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    double m, n;
    cin >> m >> n;
    vector<long double> occurences(m+1, 0);
    long double sum = 0;
    for(double i = 1; i <= m; i++){
        //calculating number of throw sequences that has i as the biggest value
        long double current = i * (pow((i/ m), n) - pow((i-1)/m, n));
        // long long int numbers = pow(i, n) - sum;
        // cout << numbers << endl;
        // occurences[i] = numbers;
         sum += current;
    }
    // for(int i = 1; i <=m; i++){
    //     occurences[i] /= sum;
    //     //cout << occurences[i] << " ";
    // }
    // long double res = 0;
    // for(double i = 1; i <= m; i++){
    //     res += i * occurences[i];
    // }
    // cout << "res:" << res << endl;
    // cout << "sum:" << sum << endl;
    // res /= sum;
    cout << sum << endl;

}