/**
 * Added Binary Tree
 * Created on 2021-02-20
 */

#include <bits/stdc++.h>
using namespace std;

#define N 105

template <class T> bool ckmax(T &a, const T &b) {
	return (a < b ? a = b, 1 : 0);
}

int p[N][N];
void dfs(int l, int r) {
	if (l > r)
		return;
	cout << p[l][r] << ' ';
	dfs(l, p[l][r] - 1);
	dfs(p[l][r] + 1, r);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n;
	static long long a[N], dp[N][N];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i <= n; ++i)
		dp[i][i] = a[i], dp[i + 1][i] = 1, p[i][i] = i;
	for (int l = n; l >= 1; --l)
		for (int r = l + 1; r <= n; ++r)
			for (int m = l; m <= r; ++m)
				if (ckmax(dp[l][r],
					  dp[l][m - 1] * dp[m + 1][r] + a[m])) {
					p[l][r] = m;
				}
	cout << dp[1][n] << '\n';
	dfs(1, n);
	cout << '\n';
}