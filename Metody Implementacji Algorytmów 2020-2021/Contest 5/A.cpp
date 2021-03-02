#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;
    vector<int> planks(n);
    for(int i = 0; i < n; i++){
        cin >> planks[i];
    }
    long long int best_l, best_r, best_sum, sum = 0, r = k-1;
    for(int i = 0; i < k; i++){
        sum += planks[i];
    }
    best_l = 0;
    best_r = r;
    best_sum = sum;
    for(int i = 1; i <= (n-k); i++){
        sum -= planks[i-1];
        sum += planks[++r];
        if(sum < best_sum){
            best_l = i;
            best_r = r;
            best_sum = sum;
        }
    }
    cout << best_l+1 << endl;
}