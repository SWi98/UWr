#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int bishop_type = 0; // 0 - black bishop, 1 - white bishop
    if(r1 == r2 && c1 == c2){
        cout << "0 0 0";
    }
    else{
        // rook
        if(r1 == r2 || c1 == c2){
            cout << 1 << " ";
        }
        else{
            cout << 2 << " ";
        }
        // bishop
        if(((r1 % 2 == 0 && c1 % 2 == 1) && (r2 % 2 == 0 && c2 % 2 == 1)) || ((r1 % 2 == 1 && c1 % 2 == 1) && (r2 % 2 == 1 && c2 % 2 == 1))
        || ((r1 % 2 == 0 && c1 % 2 == 1) && (r2 % 2 == 1 && c2 % 2 == 0)) || ((r1 % 2 == 1 && c1 % 2 == 1) && (r2 % 2 == 0 && c2 % 2 == 0))
        || ((r1 % 2 == 1 && c1 % 2 == 0) && (r2 % 2 == 0 && c2 % 2 == 1)) || ((r1 % 2 == 0 && c1 % 2 == 0) && (r2 % 2 == 1 && c2 % 2 == 1))
        || ((r1 % 2 == 1 && c1 % 2 == 0) && (r2 % 2 == 1 && c2 % 2 == 0)) || ((r1 % 2 == 0 && c1 % 2 == 0) && (r2 % 2 == 0 && c2 % 2 == 0))){
            bishop_type = 1;
            if(abs(r1 - r2) == abs(c1 - c2)){
                cout << 1 << " ";
            }
            else{
                cout << 2 << " ";
            }
        }
        else{
            cout << 0 << " ";
        }
        // king
        cout << max(abs(r1 - r2), abs(c1 - c2)) << endl;
    }
}