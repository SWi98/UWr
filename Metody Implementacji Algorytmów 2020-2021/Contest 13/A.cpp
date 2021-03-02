#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int n, t;
bool t_found;

void DFS(int a){
    //cout << a << endl;
    if(a == t){
        t_found = true;
        return;
    }
    visited[a] = true;
    for(int i = 0; i < graph[a].size(); i++){
        if(!visited[graph[a][i]]){
            DFS(graph[a][i]);
        }
    }
}

int main(){
    t_found = false;
    cin >> n >> t;
    graph.resize(n+1, vector<int>(0));
    visited.resize(n+1, false);
    visited[0] = true;
    int a;
    for(int i = 1; i <= n-1; i++){
        cin >> a;
        graph[i].push_back(a + i);
    }
    DFS(1);
    if(t_found){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}