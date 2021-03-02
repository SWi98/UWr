#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    long long int number;
    cin >> number;
    vector<long long int> triang_num(44720);
    int iter = 0;
    long long int n = iter + 1;
    while(n < 1000000000){
        triang_num[iter] = n;
        iter++;
        n += (iter+1);
    }
    int sum;
    int r = triang_num.size() -1;
    int l = 0;
    while(l <= r){
        // cout << l << " " << r << endl;
        // if(triang_num[l] == 3){
        //     cout << "3 here, second number: " << triang_num[r] << endl;
        // }
        sum = triang_num[l] + triang_num[r];
        if(sum == number){
            cout << "YES";
            return 0;
        }
        else if(sum < number){
            l++;
        }
        else{
            r--;
        }
    }
    cout << "NO";
}