/**
 * CSES Number Spiral
 * https://cses.fi/problemset/task/1071
 */

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n;
	static long long x, y;

	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (x < y) {
			if (y & 1)
				cout << (y * y - x + 1) << '\n';
			else
				cout << ((y - 1) * (y - 1) + x) << '\n';
		} else {
			if (x & 1)
				cout << ((x - 1) * (x - 1) + y) << '\n';
			else
				cout << (x * x - y + 1) << '\n';
		}
	}
}