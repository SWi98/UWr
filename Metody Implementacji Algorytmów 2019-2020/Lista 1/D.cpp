#include <iostream>
#include <vector>
#include <chrono>
#include <tuple>
#include <queue>
using namespace std;

class MyComparator{
    public:
        int Operator(const pair<int, int>& node1, const pair<int, int>& node2){
            return node1.first > node2.second;
        }
};

struct Edge{
    int node; 
    long long int weight;
    Edge(n, w): node(n), weight(w){}
};

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long int> deputies(N);
    for(int i = 0; i < N; i++){
        cin >> deputies[i];
    }
    vector<vector<edge>> Graph(N);
    for(int i = 0; i < N-1; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        u--; v--;
        Graph[u].push_back(v, w);
        Graph[v].push_back(u, w);
    }
}