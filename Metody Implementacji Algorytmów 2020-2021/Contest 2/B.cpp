#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std; 
int main(){
    int n, x;
    cin >> n;
    int vec_size = 5000;
    vector<int> t(vec_size, 0);
    for(int i = 0; i < n; i++){
        cin >> x;
        t[x-1]++;
    }
    // int min_changes = 9999999;
    // for(int i = 0; i <= vec_size - n; i++){
    //     int changes = 0;
    //     for(int j = i; j < i + n; j++){
    //         if(t[j] == 0){
    //             changes++;
    //         }
    //     }
    //     if(changes < min_changes){
    //         min_changes = changes;
    //     }
    // }
    // cout << min_changes;
    int changes = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == 0){
            changes++;
        }
    }
    cout << changes;
}