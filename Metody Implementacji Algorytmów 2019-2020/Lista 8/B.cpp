#include <iostream>
#include <vector>
#include <string>
using namespace std;

int index_of_max(string& sequence, int start_index){
    int res = start_index;
    for(int i = start_index + 1; i < sequence.size(); i++){
        if(sequence[i] > sequence[res]){
            res = i;
        }
    }
    return res;
}

int main(){
    string sequence;
    string res = "";
    cin >> sequence;
    vector<int> maxes(sequence.size());
    
    maxes[sequence.size() - 1] = sequence.size() - 1;
    char _max = sequence[sequence.size() - 1];
    for(int i = sequence.size() - 2; i >= 0; i--){
        if(sequence[i] >= _max){
            maxes[i] = i;
            _max = sequence[i];
        }
        else{
            maxes[i] = maxes[i+1];
        }
    }

    res.push_back(sequence[maxes[0]]);
    for(int i = 1; i < sequence.size(); i++){
        if(maxes[i] != maxes[i-1]){
            res.push_back(sequence[maxes[i]]);
        }
    }

    cout << res << endl;
}