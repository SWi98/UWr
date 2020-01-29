#include <iostream>
using namespace std;
int main(){
    int n, x, m;
    cin >> n;
    int sum = 0;
    long long int res = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        for(int j = 0; j < m; j++){
            res ^= x;
            x++;
        }
    }
    cout << ((x == 0) ? "bolik" : "tolik") << endl;
}