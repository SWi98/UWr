#include <iostream>
#include <vector>
#include <math.h>
using namespace std; 

vector<int> pairs; 
vector<vector<int>> vals;

int main(){
    int n, val;
    cin >> n;
    n *= 2;
    pairs.resize(n, -1);
    vals.resize(n, vector<int>(n, -1));
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            cin >> val;
            vals[i][j] = val;
            vals[j][i] = val;
        }
    }
    int pairs_made = 0;
    int counter = 0;
    while(pairs_made < n/2){ 
        // counter++;
        // if(counter > 100){
        //     break;
        // }
        vector<int> best_vals(n, 0);
        for(int i = 0; i < n; i++){
            int max_val = -100;
            int best_guy;
            if(pairs[i] == -1){
                // cout << "Considered i: " << i+1 << endl;
                for(int j = 0; j < n; j++){
                    if(i != j && pairs[j] == -1){
                        if(vals[i][j] > max_val){
                            best_guy = j;
                            max_val = vals[i][j];
                        }
                    }
                }
                best_vals[i] = best_guy;
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout  << best_vals[i] + 1 << " ";
        // }
        // cout << endl;
        int new_pairs = 0;
        for(int i = 0; i < n; i++){
            if(pairs[i] == -1 && i == best_vals[best_vals[i]]){
                new_pairs++;
                pairs[i] = best_vals[i];
                pairs[best_vals[i]] = best_vals[best_vals[i]];
                //cout << "changind vals of: " << i << " and " << best_vals[i] << endl;
                 vals[i][best_vals[i]] = -2;
                 vals[best_vals[i]][i] = -2;
                //cout << vals[i][best_vals[i]] << endl;
            }
        }
        // cout << "PAIRS: ";
        // for(int i = 0; i < n; i++){
        //     cout << pairs[i] + 1 << " ";
        // }
        // cout << endl;
        pairs_made += new_pairs;
        // cout << "pairs_made: " << pairs_made << endl;
    }
    for(int i = 0; i < n; i++){
        cout << pairs[i] + 1 << " ";
    }
}