/**
 * CF Max Median
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, k, a[N], mn[N];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int low = 1, high = n;
	auto pass = [&](int median) -> bool {
		int prefix = 0;
		mn[0] = 0;
		for (int i = 1; i <= n; i++) {
			prefix += (a[i] >= median ? 1 : -1);
			mn[i] = min(mn[i - 1], prefix);
			if (i >= k && prefix > mn[i - k])
				return 1;
		}
		return 0;
	};
	while (low < high) {
		int mid = (low + high + 1) / 2;
		if (pass(mid)) low = mid;
		else high = mid - 1;
	}
	cout << low << '\n';
}