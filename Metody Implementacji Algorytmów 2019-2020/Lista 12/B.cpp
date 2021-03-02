#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
using namespace std; 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>Graph (n+1);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<long long int> count1(n+1, 0);
    vector<long long int> count2(n+1, 0);
    vector<long long int> dist_from_start(n+1, 10000);
    queue<int> Q;
    vector<bool> visited(n+1, false);
    int current_node;

    count1[1] = 1;
    count2[n] = 1;
    Q.push(1);
    dist_from_start[1] = 0;
    while(!Q.empty()){
        current_node = Q.front();
        Q.pop();
        visited[current_node] = true;
        for(int i = 0; i < Graph[current_node].size(); i++){
            int new_dist = dist_from_start[current_node] + 1;
            if(new_dist <= dist_from_start[Graph[current_node][i]]){
                count1[Graph[current_node][i]] += count1[current_node];
                dist_from_start[Graph[current_node][i]] = new_dist;
                if(!visited[Graph[current_node][i]]){
                    Q.push(Graph[current_node][i]);
                    visited[Graph[current_node][i]] = true;
                }
            }
        }
    }
    /*for(int i = 0; i < count1.size(); i++){
        cout << i << " : " << count1[i] <<  " , " << dist_from_start[i] << endl;
    }*/

    while(!Q.empty()){
        Q.pop();
    }
    for(int i = 0; i < visited.size(); i++){
        visited[i] = false;
    }

    Q.push(n);
    while(!Q.empty()){
        current_node = Q.front();
        Q.pop();
        visited[current_node] = true;
        for(int i = 0; i < Graph[current_node].size(); i++){
            if(dist_from_start[Graph[current_node][i]] < dist_from_start[current_node]){
                count2[Graph[current_node][i]] += count2[current_node];
                if(!visited[Graph[current_node][i]]){
                    Q.push(Graph[current_node][i]);
                    visited[Graph[current_node][i]] = true;
                }
            }
        }
    }
    /*cout << endl;
    for(int i = 0; i < count1.size(); i++){
        cout << i << " : " << count2[i] << endl;
    }*/

    long long int max = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1 || i == n){
            if(count1[i] * count2[i] > max){
                max = count1[i] * count2[i];
            }
        }
        else if(count1[i] * count2[i] * 2 > max){
            max = count1[i] * count2[i] * 2;
        }
    }
    double res = (double)max / count1[n];
    cout << setprecision(9) << res << endl;

}