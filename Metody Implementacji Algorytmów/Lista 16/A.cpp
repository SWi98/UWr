#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tab[16] = {2, 3, 4, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int count = 0;
    string resp;
    vector<int> div;
    for(int i = 0; i < 16; i++){
        cout << tab[i] << endl;
        cin >> resp;
        if(count > 1){
            break;
        }
        if(resp == "yes"){
            count++;
            div.push_back(tab[i]);
        }
        fflush(stdout);
    }
    if(count == 1){
        if(div[0] * div[0] <= 100){
        cout << div[0] * div[0] << endl;
        cin >> resp;
        if(resp == "yes"){
            count++;
        }
        fflush(stdout);
        }
    }
    if(count > 1){
        cout << "composite";
    }
    else{
        cout << "prime";
    }
}