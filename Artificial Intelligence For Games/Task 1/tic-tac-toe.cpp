#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <time.h>       
using namespace std;
typedef pair<int, int> action;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{ 
    srand(time(NULL));
    set<action> visited;
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // game loop
    while (1) {
        vector<action> available;
        int opponentRow;
        int opponentCol;
        cin >> opponentRow >> opponentCol; cin.ignore();
        if(opponentCol != -1){
            board[opponentRow][opponentCol] = -1;
        }
        int validActionCount;
        cin >> validActionCount; cin.ignore();
        for (int i = 0; i < validActionCount; i++) {
            int row;
            int col;
            cin >> row >> col; cin.ignore();
            available.push_back(make_pair(row, col));
        }

        action player_action;
        if(((board[0][0] && board[2][2]) || (board[0][2] && board[2][0])) && board[1][1] == 0){
            player_action = make_pair(1, 1);
        }
        else if(board[0][0] && board[0][2] && board[0][1] == 0){
            player_action = make_pair(0, 1);
        }
        else if(board[0][0] && board[2][0] && board[1][0] == 0){
            player_action = make_pair(1, 0);
        }
        else if(board[2][2] && board[0][2] && board[1][2] == 0){
            player_action = make_pair(1, 2);
        }
        else if(board[2][2] && board[2][0] && board[2][1] == 0){
            player_action = make_pair(2, 1);
        }
        else if(board[0][0] == 0){
            player_action = make_pair(0, 0);
        }
        else if(board[2][2] == 0){
            player_action = make_pair(2, 2);
        }
        else if(board[0][2] == 0){
            player_action = make_pair(0, 2);
        }
        else if(board[1][1] == 0){
            make_pair(1, 1);
        }
        else{
            player_action = available[rand() % available.size()];
        }
        board[player_action.first][player_action.second] = 1;
        cout << player_action.first << " " << player_action.second << "\n";
        visited.insert(player_action);
    }
}