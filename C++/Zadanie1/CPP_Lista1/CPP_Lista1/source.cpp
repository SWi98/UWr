#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<pair<int, string>> rzym = {
	{1000, "M"},
	{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
	{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};


string bin2rzym(int x) {
	string res = "";

	if (x < 0 || x > 3999)
		return "Wrong number";

	int i = 0;

	while (i < rzym.size()) {
		if (x >= rzym[i].first) {
			res.append(rzym[i].second);
			x -= rzym[i].first;
		}
		else
			i++;
	}
	return res;
}

bool check(string s) {
	for (int i = 0; i < s.size(); i++)
		if (!isdigit(s[i])) {
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {

	for (int i = 1; i < argc; i++) {

		try {
			if (stoi(argv[i]) < 1 || stoi(argv[i]) > 3999)
				clog << "Wrong number\n";

			else if (argv[i][0] == '0')
				clog << argv[i] << "starts from 0\n";

			else if (!check(argv[i])) 
				clog << argv[i] << " is not a good number \n";
			else
				cout << argv[i] << " = " << bin2rzym(stoi(argv[i])) << "\n";
		}

		catch (exception &e) {
			clog << argv[i] << " is not a number\n";
		}
	}
}
