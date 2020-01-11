#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> children(n+1);
    vector<int> leaf_children(n+1, 0);
    for(int i = 2; i <= n; i++){
        int parent;
        cin >> parent;
        children[parent].push_back(i);
    }

    /*for(int i = 0; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < children[i].size(); j++){
            cout << children[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < children[i].size(); j++){
            int child = children[i][j];
            if(children[child].size() == 0){
                leaf_children[i]++;
            }
        }
    }

    /*for(int i = 1; i <= n; i++){
        cout << i << " number of his leaf children: " << leaf_children[i] << endl;
    }
    cout << endl;*/
    
    bool print_yes = true;
    for(int i = 1; i <= n; i++){
        if(children[i].size() > 0 && leaf_children[i] < 3){
            cout << "NO";
            print_yes = false;
            break;
        }
    }
    if(print_yes){
        cout << "YES";
    }


}