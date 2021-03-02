#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <tuple>
 
using namespace std;
#define State tuple<int, int, int>      // 0 - wall, 1 - pos, 2 - water_level
 
vector<char> Left;
vector<char> Right;
int height, jump;
 
vector<State> Possible_Moves(State current){
    vector<State> res;
    if(get<0>(current)){       //currently on the right wall
        //cout <<"RIGHT\n";
        if(Right[get<1>(current) - 1] != 'X' && (get<2>(current) < (get<1>(current) - 1)) ){
            State new_state;
            get<0>(new_state) = 1;
            get<1>(new_state) = get<1>(current) - 1;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
        }
        if(get<1>(current) + 1 >= height || Right[get<1>(current) + 1] != 'X'){
            State new_state;
            get<0>(new_state) = 1;
            get<1>(new_state) = get<1>(current) + 1;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
        }
        if(get<1>(current) + jump >= height || Left[get<1>(current) + jump] != 'X'){
            State new_state;
            get<0>(new_state) = 0;
            get<1>(new_state) = get<1>(current) + jump;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
        }
    }
    else{       // currently on the left wall
      //  cout << "LEFT\n";
        if(Left[get<1>(current) - 1] != 'X' && (get<2>(current) < (get<1>(current) - 1)) ){
            //cout << "ONE\n";
            State new_state;
            get<0>(new_state) = 0;
            get<1>(new_state) = get<1>(current) - 1;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
           // cout <<"INSIDE: " << get<0>(new_state) << " " << get<1>(new_state) << " " << get<2>(new_state) << endl;
        }
        if(get<1>(current) + 1 >= height || Left[get<1>(current) + 1] != 'X'){
           //cout << "TWO\n";
            State new_state;
            get<0>(new_state) = 0;
            get<1>(new_state) = get<1>(current) + 1;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
            //cout <<"INSIDE: " << get<0>(new_state) << " " << get<1>(new_state) << " " << get<2>(new_state) << endl;
        }
        if(get<1>(current) + jump >= height || Right[get<1>(current) + jump] != 'X'){
           // cout << "THREE\n";
            State new_state;
            get<0>(new_state)= 1;
            get<1>(new_state) = get<1>(current) + jump;
            get<2>(new_state) = get<2>(current) + 1;
            res.push_back(new_state);
        }
    }
    return res;
}
 
void BFS(State state){
    queue<State> states;
    set<State> visited;
    visited.insert(state);
    states.push(state);
    while(!states.empty()){
        State current = states.front();
        states.pop();
        vector<State> new_states = Possible_Moves(current);
        for(int i = 0; i < new_states.size(); i++){
            State new_state = new_states[i];
            if(visited.find(new_state) == visited.end() && get<1>(new_state) > get<2>(new_state)){
                visited.insert(new_state);
                if(get<1>(new_state) >= height){
                    cout << "YES\n";
                    /*cout << get<0>(current) << " " << get<1>(current) << " " << get<2>(current) << endl;
                    cout << get<0>(new_state) << " " << get<1>(new_state) << " " << get<2>(new_state) << endl;*/
                    return;
                }
                states.push(new_state);
            }
        }
    }
    cout << "NO";
    return;
}
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> height >> jump;
    char wall;
    for(int i = 0; i < height; i++){
        cin >> wall;
        Left.push_back(wall);
    }
    for(int i = 0; i < height; i++){
        cin >> wall;
        Right.push_back(wall);
    }
    State state;
    get<0>(state) = 0;
    get<1>(state) = 0;
    get<2>(state) = -1;
    BFS(state);
 
}