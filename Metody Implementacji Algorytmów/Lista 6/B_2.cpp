#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> numbers(n+1);
    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }
    vector<long long int> sums(n+1, 0);
    vector<long long int> sum;
    copy(numbers.begin(), numbers.end(), back_inserter(sum));
    for(int i = m; i <= n; i++){
        for (int j = i; j > i - m; j--){
            sums[i] += numbers[j];
        }
    }
    /*for(int i = 1; i <= n; i++){
        cout << i << " sums = " << sums[i] << endl;
    }
    cout << endl;*/
    for(int i = 2; i <= n; i++){
        sum[i] += sum[i - 1];
        //cout << i << " sum = " << sum[i] << endl;
    }
    //cout << endl;
    vector<vector<long long int>> DP(n+1, vector<long long int>(k+1, 0));

    for(int i = 1; i <= k; i++){
        DP[i * m][i] = sum[i * m];
        //cout << i * m << " " << i << " = " << DP[i * m][i] << endl;
    }
    //cout << endl;
    for(int i = 1; i <= n; i++){     // filling first row
        DP[i][1] = *max_element(sums.begin() + 1, sums.begin() + i + 1, [](int a, int b){
            return a < b;
        });
        //cout << DP[i][1] << endl;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(j < i * m){
                DP[j][i] = -1;
            }
            else{
                DP[j][i] = max(DP[j-1][i], DP[j-m][i-1] + sums[j]);
            }
        }
    }
    cout << DP[n][k] << endl;
}