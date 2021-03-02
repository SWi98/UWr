#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int find_min(vector<int> &t, int n){
    int res = 0;
    for(int i = 0; i <= n; i++){
        if(t[i] < t[res]){
            res = i;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> demand(n);
    vector<int> price(n);
    vector<int> suffix_sum(n, 0);
    for(int i = 0; i < n; i++){
        cin >> demand[i] >> price[i];
    }

    int sum = 0, current_n = n - 1, min_price_index;
    long long int meat_demand;
    while(true){
        min_price_index = find_min(price, current_n);
        meat_demand = 0;
        for(int i = min_price_index; i <= current_n; i++){
            meat_demand += demand[i];
        }
        sum += price[min_price_index] * meat_demand;
        current_n = min_price_index - 1;
        if(current_n < 0){
            break;
        }
    }
    cout << sum;
}