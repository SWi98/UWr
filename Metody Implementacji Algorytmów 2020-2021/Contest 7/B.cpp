#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <list>
#include <numeric>
using namespace std;

vector<int> argsort(vector<long long int> &array) {
    vector<int> indices(array.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
              [&array](int left, int right) -> bool {
                  // sort indices according to corresponding array element
                  return array[left] < array[right];
              });

    return indices;
}

int main(){
    long long int n, q;
    cin >> n >> q;
    vector<long long int> itab(n);
    for(long long int i = 0; i < n; i++){
        cin >> itab[i];
    }
    vector<long long int> meta_additions(n+1, 0);
    long long int a,b;
    for(long long int i = 0; i < q; i++){
        cin >> a >> b;
        a--;b--;
        meta_additions[a]++;
        meta_additions[b+1]--;
    }
    vector<long long int> additions(n, 0);
    long long int bonus = 0;
    for(long long int i = 0; i < n; i++){
        bonus += meta_additions[i];
        additions[i] += bonus;
    }

    // cout << "MULTIPLIER OF EACH INDEX:\n";
    // for(int i = 0; i< n; i++){
    //     cout << additions[i] << " ";
    // }
    // cout << "\n_____________________\n";

    vector<int> adds_argsorted = argsort(additions);

    // cout << "MULTIPLIERS ARGSORT:\n";
    // for(int i = 0; i < n; i++){
    //     cout << adds_argsorted[i] << " ";
    // }
    // cout << "\n_____________________\n";

    vector<long long int> init_sorted = itab;
    sort(init_sorted.begin(), init_sorted.end());
    // cout << "INITIAL ARRAY SORT:\n";
    // for(int i = 0; i < n; i++){
    //     cout << init_sorted[i] << " ";
    // }
    // cout << "\n_____________________\n";

    vector<int> good_tab(n);
    for(int i = 0; i < n; i++){
        // cout << "adds_argsorted[" << i << "] = " << adds_argsorted[i] << endl;
        // cout << "init_sorted[adds_argsorted[" << i << "] = " << init_sorted[adds_argsorted[i]] << endl;
        good_tab[adds_argsorted[i]] = init_sorted[i];
    }

    // cout << "GOOD ARRAY:\n";
    // for(int i = 0; i < n; i++){
    //     cout << good_tab[i] << " ";
    // }
    // cout << "\n_____________________\n";

    long long int sum = 0;
    for(int i = 0; i < n; i++){
        sum += good_tab[i] * additions[i];
    }
    cout << sum;

}