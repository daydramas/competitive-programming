#include <bits/stdc++.h>
using namespace std;

int lg(long long a, int b) {
	int c = 0;
	while (a % b == 0)
		a /= b, c++;
	return c;
}

const int N = 205;

int n, k;
long long a[N];
int dp[N][5001];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = k; j >= 1; --j) {
			int x = lg(a[i], 2), y = lg(a[i], 5);
			for (int l = y; l <= 5000; ++l) {
				dp[j][l] = max(dp[j][l], dp[j - 1][l - y] + x);
				ans = max(ans, min(dp[j][l], l));
			}
		}
	cout << ans << '\n';
}