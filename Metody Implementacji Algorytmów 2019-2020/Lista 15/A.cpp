#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main(){
    int n, t, c;
    cin >> n;
    long long int Q = 0;
    int clock = 1;
    int max_q = 0;
    while(n--){
        cin >> t >> c;
        while(clock != t){
            clock++;
            if(Q){
                Q--;
            }
        }
        if(Q){
            Q--;;
        }
        Q += c;
        if(Q > max_q){
            max_q = Q;
        }
        clock++;
    }
    cout << t + Q << " " << max_q << endl;
}