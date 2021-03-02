#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <tuple>

using namespace std;
#define State tuple<int, int, int>      // 0 - wall, 1 - pos, 2 - water_level

vector<char> Left;
vector<char> Right;
int height, jump;
string Wall[2];

vector<State> Possible_Moves(int wall, int pos, int water_level) {
	vector<State> res;
	State one(!wall, pos + jump, water_level + 1);
	State two(wall, pos - 1, water_level + 1);
	State three(wall, pos + 1, water_level + 1);
	res.push_back(one); res.push_back(two); res.push_back(three);
	return res;
}

void BFS(State state) {
	queue<State> states;
	set<State> visited;
	visited.insert(state);
	states.push(state);
	while (!states.empty()) {
		State current = states.front();
		states.pop();
		vector<State> new_states = Possible_Moves(get<0>(current), get<1>(current), get<2>(current));
		for (int i = 0; i < new_states.size(); i++) {
			State new_state = new_states[i];
			if (visited.find(new_state) == visited.end() && get<1>(new_state) > get<2>(new_state) && Wall[get<0>(new_state)] != "X") {
				visited.insert(new_state);
				if (get<1>(new_state) >= height) {
					cout << "YES\n";
					return;
				}
				states.push(new_state);
			}
		}
	}
	cout << "NO";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> height >> jump >> Wall[0] >> Wall[1];
	State state;
	get<0>(state) = 0;
	get<1>(state) = 0;
	get<2>(state) = -1;
	BFS(state);

}