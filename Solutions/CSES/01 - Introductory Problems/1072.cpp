/**
 * CSES Two Knights
 * https://cses.fi/problemset/task/1072/
 */

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << (1LL * (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2)
		     << '\n';
	}
}