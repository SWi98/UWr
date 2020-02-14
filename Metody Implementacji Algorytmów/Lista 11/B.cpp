#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

long long int count(vector<long long int> &AorB, int max_index, long long int other_sum){
    long long int res = 0;
    for(int i = 0; i < AorB.size(); i++){
        if (i != max_index){
            res += min(AorB[i], other_sum);
        }
    }
    return res + other_sum;
}


int main(){
    int n, m;
    cin >> m >> n;
    vector<long long int> A;
    vector<long long int> B;
    long long int x;
    long long int current_max = 0;
    int max_index;
    long long int res = 0;
    long long int B_sum = 0;
    long long int A_sum = 0;
    char table = 'A';
    for(int i = 0; i < m; i++){
        cin >> x;
        A.push_back(x);
        if(x > current_max){
            current_max = x;
            max_index = i;
        }
        A_sum += x;
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        B.push_back(x);
        if(x > current_max){
            current_max = x;
            max_index = i;
            table = 'B';
        }
        B_sum += x;
    }
    res = table == 'A' ? count(A, max_index, B_sum) : count(B, max_index, A_sum);
    cout << res << endl;
}