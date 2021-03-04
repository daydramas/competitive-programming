/*
============================================================================
 Name:		Stones
 Link:		https://atcoder.jp/contests/dp/tasks/dp_k
 Author:	Dong Liu
 Date:		2021-02-13
============================================================================
*/

#include <algorithm>
#include <iostream>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, k, a[N];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	bool dp[k + 1];
	fill(dp, dp + k + 1, false);
	for (int i = 0; i <= k; ++i) {
		if (dp[i])
			continue;
		for (int j = 0; j < n; ++j) {
			if (i + a[j] <= k)
				dp[i + a[j]] = true;
		}
	}
	cout << (dp[k] ? "First" : "Second") << '\n';
}