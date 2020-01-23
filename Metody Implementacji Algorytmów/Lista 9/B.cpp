#include <iostream>
using namespace std;
int main(){
    int n, x, m;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        for(int j = 0; j < m; j++){
            sum += x;
            x++;
        }
    }
    cout << ((sum % 2 == 0) ? "bolik" : "tolik") << endl;
}