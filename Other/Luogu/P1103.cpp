#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	k = n - k;
	static int dp[105][105];
	static pair<int, int> a[105];
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = 1e9;
	for (int i = 1; i <= n; ++i)
		dp[i][1] = 0;
	for (int j = 2; j <= k; ++j)
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k < i; ++k)
				dp[i][j] = min(dp[i][j],
					       dp[k][j - 1] + abs(a[i].second -
								  a[k].second));
	int ans = 1e9;
	for (int i = 1; i <= n; ++i)
		ans = min(ans, dp[i][k]);
	cout << ans << '\n';
}