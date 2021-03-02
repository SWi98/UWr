#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int V, E;
        cin >> V >> E;
        cout << 2 - V + E << endl;
    }
}