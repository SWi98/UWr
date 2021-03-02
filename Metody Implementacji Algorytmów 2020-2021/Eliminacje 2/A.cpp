#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<long long int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int sum = 1;
    for(int i = 1; i < n; i++){
        if(t[i] + t[i-1] <= k){
            sum++;
        }
    }
    cout << sum << endl;
}