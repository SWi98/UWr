#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<int> players;
    for(int i = 0; i < m + 1; i++){
        cin >> x;
        players.push_back(x);
    }
    int count = 0;
    int local_count;
    int pl;
    for(int i = 0; i < m; i++){
        pl = players[i] ^ players[m];
        local_count = 0;
        while(pl > 0){
            if(pl % 2 == 1){
                local_count++;
            }
            pl = pl / 2;
        }
        if(local_count <= k){
            count++;
        }
    }
    cout << count << endl;

}