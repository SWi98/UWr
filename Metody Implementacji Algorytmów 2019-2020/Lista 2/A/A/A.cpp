#include <iostream>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
	long double M_PI = 3.1415926535897932384626433832;
	int M, N;
	int x1, y1, x2, y2;
	float R;
	cin >> M >> N >> R >> x1 >> y1 >> x2 >> y2;
	double path, arc, radius;
	if (y1 == 0 || y2 == 0) {
		cout << abs(y1 - y2);
	}
	else {
		path = abs(y1 - y2) / (double)N * R;
		radius = R / (double)N * min(y1, y2);
		arc = M_PI * radius * abs(x1 - x2) / M;
		path += arc;
		double alternate_path = y1 / (double)N * R + y2 / (double)N * R;
		cout << setprecision(7) << min(path, alternate_path);
	}
}