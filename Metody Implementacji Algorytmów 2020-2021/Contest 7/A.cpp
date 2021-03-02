#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long int> tab(n);
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    vector<vector<long long int>> operations(m, vector<long long int>(3, 0));
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        operations[i][0] = a-1;
        operations[i][1] = b-1;
        operations[i][2] = c;
    }

    //count how many times each operation has to be called
    vector<long long int> number_of_calls(m+1, 0);
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        a--;
        b--;
        number_of_calls[a]++;
        number_of_calls[b+1]--;
    }
    vector<long long int> calls(m+1, 0);
    long long int bonus = 0;
    for(int i = 0; i < m; i++){
        bonus += number_of_calls[i];
        calls[i] += bonus;
    }
    // cout << "NUMBER OF CALLS:\n";
    // for(int i = 0; i < m; i++){
    //     cout << calls[i] << " ";
    // }
    // cout << "_________________________\n";

    vector<long long int> meta_adds(n+1, 0);
    for(int i = 0; i < m; i++){
        meta_adds[operations[i][0]]  += operations[i][2] * calls[i];
        meta_adds[operations[i][1] + 1]  -= operations[i][2] * calls[i];
    }
    // cout << "ADDITIONS:\n";
    // for(int i = 0; i < n; i++){
    //     cout << meta_adds[i] << " ";
    // }
    // cout << "_________________________\n";

    bonus = 0;
    for(int i = 0; i < n; i++){
        bonus += meta_adds[i];
        tab[i] += bonus;
    }

    for(int i = 0; i < n; i++){
        cout << tab[i] << " ";
    }
    // //count what number has to be added from indice a to b
    // vector<long long int> adds(n+1, 0);
    // for(int i = 0; i < m; i++){
    //     if(number_of_calls[i]){
    //         adds[operations[i][0]] += operations[i][2] * number_of_calls[i];
    //         adds[operations[i][1] + 1] -= operations[i][2] * number_of_calls[i];
    //     }
    // }
    // // cout << "ADDS:\n";
    // // for(int i = 0; i < n; i++){
    // //     cout << adds[i] << " ";
    // // }
    // // cout << endl;
    // int bonus = 0;
    // for(int i = 0; i < n; i++){
    //     bonus += adds[i];
    //     tab[i] += bonus;
    // }
    // //show number_of_calls
    // // cout << "number of calls: ";
    // // for(int i = 0; i < m; i++){
    // //     cout << number_of_calls[i] << " ";
    // // }
    // // cout << endl;
    // //execute the calls
    // // for(int i = 0; i < m; i++){
    // //     if(number_of_calls[i]){
    // //         operations[i][2] *= number_of_calls[i];
    // //         //cout << "CALLING OPERATION NR: " << i << ": " << operations[i][0] << " " << operations[i][1] << " " << operations[i][2] << endl;
    // //         for(int j = operations[i][0]; j <= operations[i][1]; j++){
    // //             tab[j] += operations[i][2];
    // //         }
    // //     }
    // // }
    // for(int i = 0; i < n; i++){
    //     cout << tab[i] << " ";
    // }
}