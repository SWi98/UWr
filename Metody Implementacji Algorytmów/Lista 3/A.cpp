#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int RES, MAX_CATS;
vector<vector<int>> TREE;
vector<int> IS_CAT;
vector<int> CATS_UNTILL;

void BFS() {
	queue<int> Q;
	set<int> visited;
	Q.push(1);
	visited.insert(1);
	while (!Q.empty()) {
		int current = Q.front();
		if (TREE[current].size() == 1 && (visited.find(TREE[current][0]) != visited.end())) {
			RES++;
		}
        //cout << current << "; jego sasiedzi: ";
		Q.pop();
		for (int i = 0; i < TREE[current].size(); i++) {
			int son = TREE[current][i];
            //cout << son << ": ";
			if (visited.find(son) == visited.end()) {
				visited.insert(son);
				if (IS_CAT[son]) {
					CATS_UNTILL[son] = CATS_UNTILL[current] + 1;
                   // cout << CATS_UNTILL[son] << " ";
                }
				else {
					CATS_UNTILL[son] = 0;
				}
				if (CATS_UNTILL[son] <= MAX_CATS) {
					Q.push(son);
				}
                else{
                    //cout << "\nZŁY SYN: " << son << endl;
                }
               // cout << ";; ";
			}
		}
        cout << endl;
	}
}

int main() {
	RES = 0;
	int vertices_num;
	cin >> vertices_num >> MAX_CATS;
	vector<int> something;
	TREE.push_back(something);
	TREE.resize(vertices_num + 1);
	IS_CAT.resize(vertices_num + 1);
	CATS_UNTILL.resize(vertices_num + 1);
	for (int i = 1; i <= vertices_num; i++) {
		cin >> IS_CAT[i];
	}
	for (int i = 1; i < vertices_num; i++) {
		int x, y;
		cin >> x >> y;
		TREE[x].push_back(y);
		TREE[y].push_back(x);
	}
    CATS_UNTILL[1] = IS_CAT[1];
	BFS();
	cout << RES;
}