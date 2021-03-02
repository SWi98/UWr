#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> d1(n);
    vector<int> d2(m);
    vector<int> indices(m);
    for(int i = 0; i < n; i++){
        cin >> d1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> d2[i];
        indices[i] = i;
    }

    sort(d1.begin(), d1.end());
    sort(indices.begin(), indices.end(), [&](int i, int j){return d2[i] < d2[j];});
    int j = 0, previous_counter = 0, counter = 0;
    vector<int> counts(m, 0);
    for(int i = 0; i < m; i++){
        counter = 0;
        while(j < n && d1[j] <= d2[indices[i]]){
            j++;
            counter++;
        }
        counter += previous_counter;
        counts[indices[i]] = counter;
        previous_counter = counter;
    }
    for(int i = 0; i < m; i++){
        cout << counts[i] << " ";
    }
}