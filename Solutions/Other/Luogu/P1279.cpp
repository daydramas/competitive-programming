/**
 * String Distance
 * Created on 2021-02-20
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 2005

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a, b;
	int k;
	cin >> a >> b >> k;
	static int dp[N][N];
	int n = a.length();
	int m = b.length();
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = k * i;
	for (int j = 1; j <= m; ++j)
		dp[0][j] = k * j;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + k;
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] +
						     abs(a[i - 1] - b[j - 1]));
		}
	cout << dp[n][m] << '\n';
}