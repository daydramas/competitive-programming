#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, a[N], dp[N][4];

#define ckmax(a, b)	a = max(a, b)

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j)
			dp[i][j] = dp[i - 1][j];
		if (a[i] == 1) {
			ckmax(dp[i][0], dp[i - 1][0] + 1);
			ckmax(dp[i][2], dp[i - 1][2] + 1);
			ckmax(dp[i][2], dp[i - 1][1] + 1);
		} else {
			ckmax(dp[i][1], dp[i - 1][1] + 1);
			ckmax(dp[i][3], dp[i - 1][3] + 1);
			ckmax(dp[i][1], dp[i - 1][0] + 1);
			ckmax(dp[i][3], dp[i - 1][2] + 1);
		}
	}
	cout << max(dp[n][2], dp[n][3]) << '\n';
}