#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int DFS(int start, int end, vector<vector<vector<int>>>& Graph, vector<bool> &visited, int color, int current){
    visited[current] = true;
    if(current == end){
        return 1;
    }
    for(int i = 0; i < Graph[current].size(); i++){
        if(find(Graph[current][i].begin(), Graph[current][i].end(), color) != Graph[current][i].end()){
            if(!visited[i]){
                if(DFS(start, end, Graph, visited, color, i)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, m, q;
    cin >> n >> m;
    vector<vector<vector<int>>> Graph(n, vector<vector<int>>(n));
    int a, b, color;
    set<int> colors; 
    for(int i = 0; i < m; i++){
         cin >> a >> b >> color;
         Graph[a-1][b-1].push_back(color - 1);
         Graph[b-1][a-1].push_back(color - 1);
         colors.insert(color - 1);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        int res = 0;
        for(int i : colors){
            vector<bool> vis(n, false);
            res += DFS(a - 1, b - 1, Graph, vis, i, a - 1);
             
        }
        cout << res << endl;
    }

}