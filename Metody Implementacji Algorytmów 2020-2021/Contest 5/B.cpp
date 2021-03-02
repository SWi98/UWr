#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long int> item(N);
    vector<long long int> DP(N, 0);
    vector<long long int> sums(N);
    for(int i = 0; i < N; i++){
        cin >> item[i];
    }
    sums[N-1] = item[N-1];
    for(int i = N - 2; i >= 0; i--){
        sums[i] = item[i] + sums[i+1];
    }
    DP[N-1] = item[N-1];
    for(int i = N - 2; i >=0; i--){
        DP[i] = max(DP[i+1], item[i] + sums[i+1] - DP[i+1]);
    }
    cout << sums[0] - DP[0] << " " << DP[0];
}