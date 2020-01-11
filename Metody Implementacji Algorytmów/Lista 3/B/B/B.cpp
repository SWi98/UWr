#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <tuple>

using namespace std;
#define State tuple<int, int, int>      // 0 - wall, 1 - pos, 2 - water_level

vector<vector<char>> Wall(2);
vector<vector<bool>> Visited(2);
int height, jump;

bool DFS(int wall, int pos, int water_level) {
	if (pos >= height) {
		return true;
	}
	else if (pos <= water_level || Wall[wall][pos] == 'X' || Visited[wall][pos]) {
		return false;
	}
	Visited[wall][pos] = true;
	return DFS(!wall, pos + jump, water_level + 1) || DFS(wall, pos + 1, water_level + 1) || DFS(wall, pos - 1, water_level + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> height >> jump;
	char wall;
	for (int i = 0; i < height; i++) {
		cin >> wall;
		Wall[0].push_back(wall);
		Visited[0].push_back(false);
	}
	for (int i = 0; i < height; i++) {
		cin >> wall;
		Wall[1].push_back(wall);
		Visited[1].push_back(false);
	}
	if (DFS(0, 0, -1)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}