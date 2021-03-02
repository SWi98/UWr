#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    while(N--){
        int votes;
        cin >> votes;
        vector<int> numbers(1001, 0);
        for(int i = 0; i < votes; i++){
            int x;
            cin >> x;
            numbers[x]++;
        }
        int best_indice = 1;
        for(int i = 1; i <= 1000; i++){
            if(numbers[i] > numbers[best_indice]){
                best_indice = i;
            }
        }
        cout << best_indice << endl;
    }
}