#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> sums(N);
    // sums[0] : T1 + T2, sums[1]: T2 + T3, sum[2]: T3 + T4,..., sums[N-2]: T[N-1] + TN, sums[N-1]: T1 + T3
    for(int i = 0; i < N-1; i++){
        cout << "? " << i+1 << " " << i+2 << endl;
        fflush(stdout);
        cin >> sums[i];
    }
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> sums[N-1];
    // T1 + T2 = sums[0]
    // T2 + T3 = sums[1]
    // T1 + T2 + T3 = sums[N-1] 
    int T1 = sums[N-1] - sums[1];
    vector<int> res(N);
    res[0] = T1;
    for(int i = 1; i < N; i++){
        res[i] = sums[i-1] - res[i-1];
    }
    cout << "! ";
    for(int i = 0; i < N; i++){
        cout << res[i] << " ";
    }
    fflush(stdout);
}
