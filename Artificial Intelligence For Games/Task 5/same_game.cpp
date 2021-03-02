#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#define _boost ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
using namespace chrono;

vector<vector<int>> BOARD;
int HOLE = -1; 
bool printed; 
void printBoard(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if (BOARD[i][j] == -1){
                cerr << BOARD[i][j] << " ";
            }
            else{
                cerr << BOARD[i][j] << "  ";
            }
        }
        cerr << endl;
    }
}

int removed_cells; 
void floodFill(int row, int col, int color, vector<vector<int>> &BOARD){
    if(row > 14 || row < 0 || col > 14 || col < 0 || BOARD[row][col] != color || BOARD[row][col] == HOLE){
        return;
    }
    else{
        BOARD[row][col] = HOLE;
        removed_cells++;
        floodFill(row-1, col, color, BOARD);
        floodFill(row+1, col, color, BOARD);
        floodFill(row, col+1, color, BOARD);
        floodFill(row, col-1, color, BOARD);
    }
}

void fixBoard(vector<vector<int>> &BOARD){
    //fixing columns
    int gap_distance;
    for(int col = 0; col < 15; col ++){
        gap_distance = 0;
        for(int row = 14; row >= 0; row--){
            if(BOARD[row][col] == HOLE){
                gap_distance++;
            }
            else if(gap_distance > 0){
                BOARD[row + gap_distance][col] = BOARD[row][col];
                BOARD[row][col] = HOLE;
            }
        }
    }
    // checking if first column is empty
    if(BOARD[14][0] == HOLE){
        gap_distance = 1;
        // checking how neighbouring columns on the left is empty
        for(int col = 1; col < 15; col ++){
            if(BOARD[14][col] == HOLE){
                gap_distance++;
            }
            else{
                break;
            }
        }
        for(int row = 0; row < 15; row++){
            for(int col = gap_distance; col < 15; col++){
                BOARD[row][col-gap_distance] = BOARD[row][col];
                BOARD[row][col] = HOLE;
            }
        }
    }
}

int click(int node_row, int node_col, vector<vector<int>> &BOARD){
    removed_cells = 0;
    floodFill(node_row, node_col, BOARD[node_row][node_col], BOARD);
    fixBoard(BOARD);
    return (removed_cells - 2) * (removed_cells - 2);
}

bool isMoveLegal(int row, int col, vector<vector<int>> &BOARD){
    if(BOARD[row][col] == HOLE){
        return false;
    }
    int color = BOARD[row][col];
    return (row > 0 && BOARD[row-1][col] == color) || (row < 14 && BOARD[row+1][col] == color) ||
            (col > 0 && BOARD[row][col-1] == color) || (col < 14 && BOARD[row][col+1] == color);


}

void doRandomMove(){
    int random_row = rand() % 15;
    int random_col = rand() % 15;
    while(!isMoveLegal(random_row, random_col, BOARD)){
        random_row = rand() % 15;
        random_col = rand() % 15;
    }
    cerr << click(random_col, random_row, BOARD) << endl;
    printBoard();
    cout << random_col << " " << 14 - random_row <<  endl;
}

class Move{
    public:
    Move(short int r, short int c, Move* p){
        this->row = r;
        this->col = c;
        this->pred = p;
        this->board = BOARD;
        click(r, c, this->board);
    }
    short int row, col;
    int points;
    vector<vector<int>> board; 
    Move* pred;
};

bool compare(Move* l, Move* r){
    return l->points < r->points;
}

vector<Move*> BFS(){
    priority_queue<Move*, vector<Move*>, decltype(&compare)> q(compare);
    Move* current;
    for(int r = 0; r < 15; r++){
        for(int c = 0; c < 15; c++){
            if(isMoveLegal(r, c, BOARD)){
                q.push(new Move(r, c, nullptr));
            }
        }
    }
    while(!q.empty()){
        Move* current = q.top();
        q.pop();

    }
}

int main(){
    srand(time(NULL));
    BOARD.resize(15, vector<int>(15, 0));
    printed = false;
    // game loop
    while (1) {
        for (int row = 0; row < 15; row++) {
            for (int col = 0; col < 15; col++) {
                //row = 14 - row;
                int color; // Color of the tile
                cin >> color; cin.ignore();
                BOARD[row][col] = color;
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;=
        doRandomMove();
    }
}