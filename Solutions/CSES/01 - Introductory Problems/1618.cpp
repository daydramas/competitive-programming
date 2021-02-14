/**
 * CSES Trailing Zeros
 * https://cses.fi/problemset/task/1618
 */

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, pow = 5;
	static long long ans = 0;
	cin >> n;

	while (pow <= n) {
		ans += 1LL * n / pow;
		pow *= 5;
	}
	cout << ans << '\n';
}