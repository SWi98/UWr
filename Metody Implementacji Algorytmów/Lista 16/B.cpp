#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> res;
    int a_b, b_c, a_c;
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> a_b;
    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> b_c;
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> a_c;
    res.push_back((a_b - b_c + a_c) / 2);
    res.push_back(a_b - res[0]);
    res.push_back(a_c - res[0]);
    int new_val;
    for(int i = 4; i <= n; i++){
        cout << "? " << i-1 << " " << i << endl;
        fflush(stdout);
        cin >> new_val;
        res.push_back(new_val - res[i-2]);
    }
    cout << "! ";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}