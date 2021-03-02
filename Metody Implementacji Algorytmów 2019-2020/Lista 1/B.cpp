#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <tuple>
#include <stdio.h>
using namespace std;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int iterations;
    cin >> iterations;
    for(int _ = 0; _ < iterations; _++){
        long long int n, m;
        long long int x1, y1, x2, y2;
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        long long int dx = llabs(x1 - x2);
        long long int dy = llabs(y1 - y2);
        long long int vertical = n - max(x1, x2) + min(x1, x2) - 1;
        long long int horizontal = m - max(y1, y2) + min(y1, y2) - 1;
        if(dy == 0){                    // same column
            if(vertical < dx){
                cout << (long long int)(dx - vertical - 1) * m << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(dx == 0){               // same row - case symmetric to 'same column'
            if(horizontal < dy){
                cout <<(long long int)(dy - horizontal - 1) * n << endl;    //if we cannot 
            }
            else{
                cout << 0 << endl;
            }
        }
        else if((vertical + 1) < dx && (horizontal + 1) < dy){
            long long int horizontal_stripes = (dx - vertical - 1) * m;
            long long int vertical_stripes = (dy - horizontal - 1) * n;
            long long int corners = 2 * (vertical + 1) * (horizontal + 1);
            long long int shared_in_stripes = (dx - vertical - 1) * (dy - horizontal - 1);
            cout << (long long int)(vertical_stripes + horizontal_stripes + corners - shared_in_stripes) << endl;
        }
        else if(horizontal + 1 < dy){
            long long int vertical_stripes = (dy - horizontal - 1) * n;
            long long int corners = 2 * dx * (horizontal + 1);
            cout << (long long int)(vertical_stripes + corners) << endl;
        }
        else if(vertical + 1 < dx){
            long long int horizontal_stripes = (dx - vertical - 1) * m;
            long long int corners = 2 * (vertical + 1) * dy;
            cout << (long long int)(horizontal_stripes + corners) << endl;
        }
        else{
            cout << (long long int)(2 * dx * dy) << endl;   // on the same diagonal
        }
    }  
}   

//1
//4 4 2 3 3 3
//1
//3 4 1 3 3 3
//1
//3 4 2 1 2 4