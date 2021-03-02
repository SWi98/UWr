#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> numbers(n + 1);
        vector<int> good(2*n + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> numbers[i+1];
        }
        for(int i = 1; i <=  n; i++){
            good[2 * i - 1] = numbers[i];
        }
        int counter = 1;
        for(int i = 1; i <= n; i++){
            // chce znalezc good[2*i]
            int current = good[2 * i - 1];
            auto z = find(good.begin(), good.end(), current + counter);
            if(z == good.end()){
                good[2 * i] = current + counter;
                counter = 1;
            }
            else{
                i--;
                counter++;
            }
        }
        bool good2 = true;
        vector<bool> goods(2 * n + 1, false);
        for(int i = 1; i <= 2 * n; i++){
            if(good[i] > 2 * n){
                good2 = false;
                break;
            }
            goods[good[i]] = true;
        }
        if(good2){
            for(int i = 1; i <= 2 * n; i++){
                if(!goods[i]){
                    good2 = false;
                    cout <<"TUTAJ : zły indeks: " << i << endl;
                    break;
                }
            }
        }
        if(good2){
            for(int i = 1; i <= 2 * n; i++){
                cout << good[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}