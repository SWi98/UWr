#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
const long long int max_n = 1000000000000000000;
void fill(vector<vector<long long int>> &num){
    num[1].push_back(0);
    num[2].push_back(2);
    for(int i = 3; i < 64; i++){
        for(int j = 0; j < num[i-1].size(); j++){
            num[i].push_back((num[i-1][j] << 1) + 1);
            if(j == num[i-1].size() - 1){
                num[i].push_back((num[i-1][j] + 1) << 1);
            }
        }
        sort(num[i].begin(), num[i].end());
        if(num[i][num[i].size() - 1] >= max_n){
            return;
        }
    }
}

void print(vector<vector<long long int>> &num, int n){
    for(int i = 1; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < num[i].size(); j++){
            cout << num[i][j] << " ; ";
        }
        cout << endl;
    }
}

int solve(vector<vector<long long int>> &num,long long int a, long long int b){
    int count = 0;
    for(int i = 1; i < 64; i++){
        for(int j = 0; j < num[i].size(); j++){
            if(num[i][j] > b){
                return count;
            }
            else if(num[i][j] >= a){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<long long int>> good_numbers(64);
    fill(good_numbers);
    long long int a, b;
    cin >> a >> b;
    cout << solve(good_numbers, a, b);
}