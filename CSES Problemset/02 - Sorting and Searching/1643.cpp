/**
 * CSES Maximum Subarray Sum
 * https://cses.fi/problemset/task/1643
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n;
	static long long ans, mpre, pre, x;
	ans = -1e18, mpre = pre = x = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		pre += x;
		ans = max(ans, pre - mpre);
		mpre = min(mpre, pre);
	}
	cout << ans << '\n';
}