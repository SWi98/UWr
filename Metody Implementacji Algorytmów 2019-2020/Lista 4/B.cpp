#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> Tree;
vector<int> Tree_vals;
vector<int> Tree_goal_vals;
vector<int> Res;
vector<bool> Visited;

void Write() {
	for (int i = 1; i <= N; i++) {
		cout << i << ". Neighbours: ";
		for (int j = 0; j < Tree[i].size(); j++) {
			cout << Tree[i][j] << " ";
		}
		cout << endl;
	}
}

void WriteVals(){
    for(int i = 1; i <= N; i++){
        cout << i << " has value: " << Tree_vals[i] << endl;
    }
}

void DFS(int node, int depth, bool odd_flipped, bool even_flipped) {
    if(Visited[node]){
        return;
    }
    Visited[node] = true;
    if(depth % 2 == 0){
        if(even_flipped){
            Tree_vals[node] ^= 1;
        }
        if(Tree_vals[node] != Tree_goal_vals[node]){
            Tree_vals[node] ^= 1;
            Res.push_back(node);
            even_flipped = !even_flipped;
        }
    }
    else{
        if(odd_flipped){
            Tree_vals[node] ^= 1;
        }
        if(Tree_vals[node] != Tree_goal_vals[node]){
            Tree_vals[node] ^= 1;
            Res.push_back(node);
            odd_flipped = !odd_flipped;
        }
    }
    for(int j = 0; j < Tree[node].size(); j++){
        DFS(Tree[node][j], depth + 1, odd_flipped, even_flipped);
    }
}

int main() {
	cin >> N;
	Tree.resize(N + 1);
	Tree_vals.resize(N + 1);
	Tree_goal_vals.resize(N + 1);
	Visited.resize(N + 1, false);
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		Tree[x].push_back(y);
		Tree[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		cin >> Tree_vals[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> Tree_goal_vals[i];
	}
	DFS(1, 0, false, false);
    cout << Res.size() << endl;
    for(int i = 0; i < Res.size(); i++){
        cout << Res[i] << endl;
    }
}