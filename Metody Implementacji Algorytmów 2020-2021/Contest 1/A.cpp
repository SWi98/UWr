#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> dirs(n);
    vector<int> vals(n);
    bool right_found = false;  
    bool collision_possible = false;
    for(int i = 0; i < n; i++){
        cin >> dirs[i];
        if(!right_found && dirs[i] == 'R'){
            right_found = true;
        }
        else if(right_found && dirs[i] == 'L'){
            collision_possible = true;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    if(!collision_possible){
        cout << -1;
    }
    else{
        int min_val = INT_MAX;
        for(int i = 1; i < n; i++){
            if(dirs[i-1] == 'R' && dirs[i] == 'L'){
                int candidate = ceil((vals[i] - vals[i-1])/2.0);
                if(candidate < min_val){
                    min_val = candidate; 
                }
            }
        }
        cout << min_val;
    }
}
