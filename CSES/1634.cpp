#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
const int M = 100;

int m, n, a[M], dp[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		cin >> a[i];

	memset(dp, 69, sizeof(dp));
	dp[0] = 0;
	for (int j = 0; j < m; ++j)
		for (int i = a[j]; i <= n; ++i)
			dp[i] = min(dp[i], dp[i - a[j]] + 1);

	cout << (dp[n] == dp[N - 1] ? -1 : dp[n]) << '\n';
}