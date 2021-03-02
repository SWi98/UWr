#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int n, t;
bool t_found;

void DFS(int a){
    //cout << "a: " << a << " ,";
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
    bool other_than_zero = false;
    int n, m;
    cin >> n >> m;
    graph.resize(n+m+1, vector<int>(0));
    visited.resize(n+m+1, false);
    int size, language;
    for(int i = 1; i <= n; i++){
        cin >> size;
        if(!other_than_zero && size != 0){
            other_than_zero = true;
        }
        for(int j = 1; j <= size; j++){
            cin >> language;
            graph[i].push_back(language + n);
            graph[language + n].push_back(i);
        }
    }
    //cout << other_than_zero << endl;
    if(!other_than_zero){
        cout << n;
        return 0;
    }
    DFS(1);
    //cout << endl;
    int count = 1;
    for(int i = 1; i <= n; i++){
        //cout << visited[i] << " ";
    }
    //cout << endl;
    //return 0;
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            //cout << "CALL DFS FOR " << i << endl;
            DFS(i);
            count++;
        }
    }
    cout << count-1 << endl;
}