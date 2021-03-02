#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void DFS(int a){
    //cout << a << endl;
    visited[a] = true;
    for(int i = 0; i < graph[a].size(); i++){
        if(!visited[graph[a][i]]){
            DFS(graph[a][i]);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n+1, vector<int>(0));
    visited.resize(n+1, false);
    visited[0] = true;
    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(n != m){
        cout << "NO";
        return 0;
    }
    DFS(a);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "FHTAGN!";
}