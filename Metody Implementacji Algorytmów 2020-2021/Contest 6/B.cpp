#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int res(string word, char c){
    if(word.length() == 1){
        //cout << word << " " << (word[0] != c) << endl;
        return word[0] != c;
    }
    int left_different = 0, right_different = 0, left_cost, right_cost;
    for(int i = 0; i < word.length() / 2; i++){
        if(word[i] != c){
            left_different++;
        }
    }
    for(int i = word.length() / 2; i < word.length(); i++){
        if(word[i] != c){
            right_different++;
        }
    }
    left_cost = res(word.substr(0, word.length()/2), char(c+1));
    right_cost = res(word.substr(word.length()/2, word.length()/2), char(c+1));
    //cout << word << " " << left_different << " " << right_different <<  " " << left_cost << " " << right_cost << endl;
    return min(left_different + right_cost, right_different + left_cost);
}


int main(){
    int t, n;
    string x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> x;
        cout << res(x, 'a') << endl;
    }
}