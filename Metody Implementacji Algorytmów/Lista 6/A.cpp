#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> even(n+1, 0);       // number of subsequences ending on 1
    vector<int> odd(n+1, 0);        // number of subsequences ending on 0
    odd[1] = 1;

    for(int i = 2; i <= n; i++){
        even[i] = even[i-1];
        odd[i] = odd[i-1];
        if(i % 2 == 0){     // adding 1 to the end of the sequence
            even[i] += odd[i - 1] + 1;
            even[i] %= 1000000007;
        }
        else{
            odd[i] += even[i - 1] + 1;
            odd[i] %= 1000000007;
        }
    }
    cout << (even[n] + odd[n]) % 1000000007;
}