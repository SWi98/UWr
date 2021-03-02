#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int n, x, m;
    cin >> n;
    long long int sum = 0;
    long long int res = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        long long int first = x;
        long long int last = x + m - 1;
        long long int first_xor_last;
        long long values_x-1[] = {x-1, 1, x, 0};
        long long values_last[] = {last, 1, last + 1, 0};
        first = values_x[(x-1)%4];
        last = values_last[last % 4];
        first_xor_last = first ^ last;
        res ^= first_xor_last;
    }
    cout << ((res == 0) ? "bolik" : "tolik") << endl;
}