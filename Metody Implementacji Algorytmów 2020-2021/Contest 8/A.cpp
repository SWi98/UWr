#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int n, d;
    cin >> n >> d;
    vector<long long int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    long long int res = 0;
    for(int i = 0; i < n-2; i++){
        long long int j = upper_bound(t.begin() + i, t.end(), t[i] + d) - t.begin() - 1;
        res += (j - i) * (j - i - 1) / 2;
    }
    cout << res;
}