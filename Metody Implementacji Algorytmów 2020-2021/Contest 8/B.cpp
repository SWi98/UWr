#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double n, t, p;
    cin >> n >> p >> t;
    vector<vector<double>> dp(t+1, vector<double>(n+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= t; i++){
        for(int j = 0; j <= n; j++){
            if(j != 0){
                dp[i][j] += dp[i-1][j-1] * p;
            }
            if(j < n){
                dp[i][j] += dp[i-1][j] * (1-p);
            }
            else{
                dp[i][j] += dp[i-1][j];
            }
        }
    }
    // cout << setprecision(5);
    // for(int i = 0; i <= t; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout  << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    double res = 0;
    for(int j = 0; j <= n; j++){
        res += dp[t][j] * j;
    }

    
	printf("%.15lf", res);

}