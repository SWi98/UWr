#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string colors;
    cin >> colors;
    vector<int> col_amount(6, 0);
    map<char, int> codes;
    string res = "";
    codes['R'] = 0; codes['O'] = 1; codes['Y'] = 2; codes['G'] = 3; codes['B'] = 4; codes['V'] = 5;
    for(int i = 0; i < colors.size(); i++){
        col_amount[codes[colors[i]]]++;
    }
    sort(col_amount.begin(), col_amount.end());
    for(int i = 0; i < 6; i++){
        if(col_amount[i] != 0){
            res += to_string(col_amount[i]);
        }
    }
    if (res == "6"){
        cout << 1;
    }
    else if (res == "51"){
        cout << 1;
    }
    else if (res == "42" || res == "411" || res == "33"){
        cout << 2;
    }
    else if (res == "321"){
        cout << 3;
    }
    else if (res == "3111"){
        cout << 5;
    }
    else if (res == "222"){
        cout << 6;
    }
    else if (res == "2211"){
        cout << 8;
    }
    else if(res == "21111"){
        cout << 15;
    }
    else if(res == "111111"){
        cout << 30;
    }
}