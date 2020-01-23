#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string sequence;
    cin >> sequence;
    int diff = 0;
    for(int i = 0; i < n; i++){
        if(sequence[i]=='0'){
            diff++;
        }
        else{
            diff--;
        }
    }
    cout << abs(diff);
}