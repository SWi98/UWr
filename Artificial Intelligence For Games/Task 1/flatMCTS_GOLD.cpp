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
#define _boost ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
using namespace chrono;
typedef pair<short int, short int> action;
typedef pair<short int, short int> position;

vector<action> AVAILABLE;
vector<vector<short int>> BOARD;
vector<vector<short int>> META_BOARDS;
vector<vector<short int>> metaBoards;
vector<vector<short int>> board;
bool FIRST_MOVE;

short int opponentRow;
short int opponentCol;
void printBoard(vector<vector<short int>> &board)
{
    cerr << "\n";
    for (vector<short int> row : board)
    {
        for (short int x : row)
        {
            if (x == -1)
            {
                cerr << x << " ";
            }
            else
            {
                cerr << " " << x << " ";
            }
        }
        cerr << "\n";
    }
}

void printMetaBoards(vector<vector<short int>> &metaBoard)
{
    cerr << "\n";
    for (short int i = 0; i < 3; i++)
    {
        for (short int j = 0; j < 3; j++)
        {
            if (metaBoard[i][j] == -1)
            {
                cerr << "-1 ";
            }
            else
            {
                cerr << " " << metaBoard[i][j] << " ";
            }
        }
        cerr << "\n";
    }
}

//Returns meta board position in which position pos is located
action findMetaBoard(position pos)
{
    return {floor((float)pos.first / 3), floor((float)pos.second / 3)};
}

//Returns cells that are empty in the given meta board
void getAvailableActionsInMetaBoard(position metaBoardPosition, vector<action> &available)
{
    short int x = metaBoardPosition.first * 3, y = metaBoardPosition.second * 3;
    short int xCord = x + 0, yCord = y + 0;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 0; yCord = y + 1;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 0; yCord = y + 2;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 1; yCord = y + 0;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 1; yCord = y + 1;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 1; yCord = y + 2;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 2; yCord = y + 0;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 2; yCord = y + 1;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});

    xCord = x + 2; yCord = y + 2;
    if (board[xCord][yCord] == 0) available.push_back({xCord, yCord});
    
}

void doAction(action &_action, bool enemyTurn)
{
    if (enemyTurn)
    {
        board[_action.first][_action.second] = -1;
    }
    else
    {
        board[_action.first][_action.second] = 1;
    }
}

// -1: enemy won, 0: still playing, 1: player won, 2: draw. bigBoard = false means that we are checking the state of a small board.
short int check3x3MetaBoardsState()
{
    if (metaBoards[0][0] != 0 && metaBoards[0][0] == metaBoards[0][1] && metaBoards[0][1] == metaBoards[0][2] && metaBoards[0][0] != 2)
    {
        return metaBoards[0][0];
    }
    else if (metaBoards[1][0] != 0 && metaBoards[1][0] == metaBoards[1][1] && metaBoards[1][0] == metaBoards[1][2] && metaBoards[1][0] != 2)
    {
        return metaBoards[1][0];
    }
    else if (metaBoards[2][0] != 0 && metaBoards[2][0] == metaBoards[2][1] && metaBoards[2][1] == metaBoards[2][2] && metaBoards[2][0] != 2)
    {
        return metaBoards[2][0];
    }
    else if (metaBoards[0][0] != 0 && metaBoards[0][0] == metaBoards[1][0] && metaBoards[1][0] == metaBoards[2][0] &&  metaBoards[0][0] != 2)
    {
        return metaBoards[0][0];
    }
    else if (metaBoards[0][1] != 0 && metaBoards[0][1] == metaBoards[1][1] && metaBoards[1][1] == metaBoards[2][1] &&  metaBoards[0][1] != 2)
    {
        return metaBoards[0][1];
    }
    else if (metaBoards[0][2] != 0 && metaBoards[0][2] == metaBoards[1][2] && metaBoards[1][2] == metaBoards[2][2] && metaBoards[0][2] != 2)
    {
        return metaBoards[0][2];
    }
    else if (metaBoards[0][0] != 0 && metaBoards[0][0] == metaBoards[1][1] && metaBoards[1][1] == metaBoards[2][2] &&  metaBoards[0][0] != 2)
    {
        return metaBoards[0][0];
    }
    else if (metaBoards[0][2] != 0 && metaBoards[0][2] == metaBoards[1][1] && metaBoards[1][1] == metaBoards[2][0] && metaBoards[0][2] != 2)
    {
        return metaBoards[0][2];
    }
    else
    {   
        if(metaBoards[0][0] == 0){return 0;}
        if(metaBoards[0][1] == 0){return 0;}
        if(metaBoards[0][2] == 0){return 0;}
        if(metaBoards[1][0] == 0){return 0;}
        if(metaBoards[1][1] == 0){return 0;}
        if(metaBoards[1][2] == 0){return 0;}
        if(metaBoards[2][0] == 0){return 0;}
        if(metaBoards[2][1] == 0){return 0;}
        if(metaBoards[2][2] == 0){return 0;}
        short int sum = 0;
        for (short int i = 0; i < 3; i++)
        {
            for (short int j = 0; j < 3; j++)
            {
                if (metaBoards[i][j] != 2)
                {
                    sum += metaBoards[i][j];
                }
            }
        }
        if (sum > 0)
        {
            return 1;
        }
        else if (sum < 0)
        {
            return -1;
        }
        return 2;
    }
}

// -1: enemy won, 0: still playing, 1: player won, 2: draw
short int checkMetaBoardState(position metaBoardPos, vector<vector<short int>> &board)
{
    //cerr << "metaBoardPos: " << metaBoardPos.first << ", " << metaBoardPos.second << endl;
    short int x = metaBoardPos.first * 3;
    short int y = metaBoardPos.second * 3;

    if (board[x][y] != 0 && board[x][y] == board[x][y+1] && board[x][y+1] == board[x][y+2] && board[x][x] != 2)
    {
        return board[x][y];
    }
    else if (board[x+1][y] != 0 && board[x+1][y] == board[x+1][y+1] && board[x+1][y] == board[x+1][y+2] && board[x+1][y] != 2)
    {
        return board[x+1][y];
    }
    else if (board[x+2][y] != 0 && board[x+2][y] == board[x+2][y+1] && board[x+2][y+1] == board[x+2][y+2] && board[x+2][y] != 2)
    {
        return board[x+2][y];
    }
    else if (board[x][y] != 0 && board[x][y] == board[x+1][y] && board[x+1][y] == board[x+2][y] &&  board[x][y] != 2)
    {
        return board[x][y];
    }
    else if (board[x][y+1] != 0 && board[x][y+1] == board[x+1][y+1] && board[x+1][y+1] == board[x+2][y+1] &&  board[x][y+1] != 2)
    {
        return board[x][y+1];
    }
    else if (board[x][y+2] != 0 && board[x][y+2] == board[x+1][y+2] && board[x+1][y+2] == board[x+2][y+2] && board[x][y+2] != 2)
    {
        return board[x][y+2];
    }
    else if (board[x][y] != 0 && board[x][y] == board[x+1][y+1] && board[x+1][y+1] == board[x+2][y+2] &&  board[x][y] != 2)
    {
        return board[x][y];
    }
    else if (board[x][y+2] != 0 && board[x][y+2] == board[x+1][y+1] && board[x+1][y+1] == board[x+2][y] && board[x][y+2] != 2)
    {
        return board[x][y+2];
    }
    else
    {   
        if(board[x][y] == 0){return 0;}
        if(board[x][y+1] == 0){return 0;}
        if(board[x][y+2] == 0){return 0;}
        if(board[x+1][y] == 0){return 0;}
        if(board[x+1][y+1] == 0){return 0;}
        if(board[x+1][y+2] == 0){return 0;}
        if(board[x+2][y] == 0){return 0;}
        if(board[x+2][y+1] == 0){return 0;}
        if(board[x+2][y+2] == 0){return 0;}
        return 2;
    }
}

float doSimulation(action _action)
{
    bool enemyTurn = false;
    vector<action> available;
    while (1)
    {
        if (enemyTurn)
        {
            board[_action.first][_action.second] = -1;
        }
        else
        {
            board[_action.first][_action.second] = 1;
        }
        //finding on which of the 9 meta boards action took place
        position metaBoardPos = {floor((float)_action.first / 3), floor((float)_action.second / 3)};
        //checking state of the meta board after the action
        short int metaBoardState = checkMetaBoardState(metaBoardPos, board);
        //updating the metaBoards structure with new state of the meta board
        metaBoards[metaBoardPos.first][metaBoardPos.second] = metaBoardState;
        //if state of meta board has changed, we have to check if it changes the state of the whole game
        if (metaBoardState != 0)
        {
            int res = check3x3MetaBoardsState();
            if(res != 0){
                return res;
            }
        }

        enemyTurn = !enemyTurn;
        //available = generateActions(board, metaBoards, _action);
        position actionCellInMetaBoard = {_action.first % 3, _action.second % 3};
        available.resize(0);
        //If this meta board is not won by anybody or there isn't a draw in there, then available actions will come only from that meta board
        if (metaBoards[actionCellInMetaBoard.first][actionCellInMetaBoard.second] == 0)
        {
            getAvailableActionsInMetaBoard(actionCellInMetaBoard, available);
        }
        else
        {
            if(metaBoards[0][0] == 0){
                getAvailableActionsInMetaBoard({0, 0}, available);
            }
            if(metaBoards[0][1] == 0){
                getAvailableActionsInMetaBoard({0, 1}, available);
            }
            if(metaBoards[0][2] == 0){
                getAvailableActionsInMetaBoard({0, 2}, available);
            }
            if(metaBoards[1][0] == 0){
                getAvailableActionsInMetaBoard({1, 0}, available);
            }
            if(metaBoards[1][1] == 0){
                getAvailableActionsInMetaBoard({1, 1}, available);
            }
            if(metaBoards[1][2] == 0){
                getAvailableActionsInMetaBoard({1, 2}, available);
            }
            if(metaBoards[2][0] == 0){
                getAvailableActionsInMetaBoard({2, 0}, available);
            }
            if(metaBoards[2][1] == 0){
                getAvailableActionsInMetaBoard({2, 1}, available);
            }
            if(metaBoards[2][2] == 0){
                getAvailableActionsInMetaBoard({2, 2}, available);
            }
        }
        _action = available[rand() % available.size()];
    }
}

//works on AVAILABLE, BOARD, META_BOARD
action findBest(std::chrono::high_resolution_clock::time_point t1)
{
    short int N = AVAILABLE.size();
    vector<float> actionsValues(N, 0);
    vector<short int> howManyCalls(N, 0);
    short int simulations = 0;
    std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
    double treshold;
    if(FIRST_MOVE){
        treshold = 999.5;
        FIRST_MOVE = false;
    }
    else{
        treshold = 99;
    }
    BOARD = board;
    META_BOARDS = metaBoards;
    while (fp_ms.count() < treshold)
    {
        short int randomIndice = rand() % AVAILABLE.size();
        short int newVal = doSimulation(AVAILABLE[randomIndice]);
        if(newVal == 2){
            newVal = 0;
        }
        howManyCalls[randomIndice]++;
        actionsValues[randomIndice] += newVal;
        board = BOARD;
        metaBoards = META_BOARDS;
        fp_ms = std::chrono::high_resolution_clock::now() - t1;
        simulations++;
    }

    float max = actionsValues[0] / howManyCalls[0];
    short int maxIndice = 0;
    for (short int i = 1; i < N; i++)
    {
        if (actionsValues[i] / howManyCalls[i] > max)
        {
            max = actionsValues[i] / howManyCalls[i];
            maxIndice = i;
        }
    }

    cerr << "time: " << fp_ms.count() << " simulations done: " << simulations << " best mean : " << max << endl;
    return AVAILABLE[maxIndice];
}

int main()
{
    FIRST_MOVE = true;
    srand(time(NULL));
    board.resize(9, vector<short int>(9, 0));
    metaBoards.resize(3, vector<short int>(3, 0));
    bool firstMove = true;
    // game loop
    while (1)
    {
        AVAILABLE.resize(0);
        cin >> opponentRow >> opponentCol;
        cin.ignore();

        // if opponent has moved (he doesn't move if we start the game, then coordinates of his action are (-1, -1)
        if (opponentCol != -1)
        {
            //updating the BOARD structure
            board[opponentRow][opponentCol] = -1;

            //updating the META_BOARD structure
            action enemyAction = {opponentRow, opponentCol};
            position metaBoardPos = {floor((float)enemyAction.first / 3), floor((float)enemyAction.second / 3)};
            short int metaBoardState = checkMetaBoardState(metaBoardPos, board);
            metaBoards[metaBoardPos.first][metaBoardPos.second] = metaBoardState;
        }
        short int validActionCount;
        cin >> validActionCount;
        cin.ignore();
        for (short int i = 0; i < validActionCount; i++)
        {
            short int row;
            short int col;
            cin >> row >> col;
            cin.ignore();
            AVAILABLE.push_back({row, col});
        }
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        action playerAction = findBest(t1);
        board[playerAction.first][playerAction.second] = 1;
        cout << playerAction.first << " " << playerAction.second << "\n";
    }
}
// 1-2 