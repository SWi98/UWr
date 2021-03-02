#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    int no_walls = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
            if(board[r][c] == '*'){
                no_walls++;
            }
        }
    }

    vector<long long int> row_walls(n, 0);
    vector<long long int> col_walls(m, 0);
    for(int r = 0; r < n; r++){
        int walls_in_row = 0;
        for(int c = 0; c < m; c++){
            if(board[r][c] == '*'){
                walls_in_row++;
            }
        }
        row_walls[r] = walls_in_row;
    }
    for(int c = 0; c < m; c++){
        int walls_in_col = 0;
        for(int r = 0; r < n; r++){
            if(board[r][c] == '*'){
                walls_in_col++;
            }
        }
        col_walls[c] = walls_in_col;
    }

    long long int intersection_walls;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            intersection_walls = row_walls[r] + col_walls[c];
            if(board[r][c] == '*'){
                intersection_walls--;
            }
            if(intersection_walls == no_walls){
                cout << "YES\n" << r+1 << " " << c+1 << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}