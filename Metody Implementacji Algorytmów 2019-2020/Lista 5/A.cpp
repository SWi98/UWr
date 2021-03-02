#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<pair<long long int, long long int>, long long int> edge_weight;

void print(){
    for(auto elem : edge_weight){
        cout << "(" << elem.first.first << ", " << elem.first.second << ") = " << elem.second << endl;
    }
}
int main(){
    int q;
    cin >> q;
    int event;
    long long int u, v, w;
    while(q--){
        cin >> event;
        //cout << q << ", event = " << event << endl;
        if(event == 1){ 
            cin >> u >> v >> w;
            while(u != v){
                if(u > v){      // v is predecessor of u
                    edge_weight[make_pair(u, u/2)] += w;
                    u /= 2;
                }
                else{           // u is predecessor of v
                    edge_weight[make_pair(v, v/2)] += w;
                    v /= 2;
                }
            }
        }
        else{
            cin >> u >> v;
            long long int sum = 0;
            while(u != v){
                if(u > v){
                    sum += edge_weight[make_pair(u, u/2)];
                    u /= 2;
                }
                else{
                    sum += edge_weight[make_pair(v, v/2)];
                    v /= 2;
                }
            }
            cout << sum << endl;
        }
    }
}