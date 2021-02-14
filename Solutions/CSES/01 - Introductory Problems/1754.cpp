/**
 * CSES Coin Piles
 * https://cses.fi/problemset/task/1754
 */

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		if ((a + b) % 3)
			cout << "NO" << '\n';
		else if (a * 2 < b)
			cout << "NO" << '\n';
		else if (b * 2 < a)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}