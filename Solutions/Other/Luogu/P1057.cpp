/**
 * Passing Game
 * Created on 2021-02-20
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 33

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, m, dp[N][N];

	dp[0][0] = 1;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < n; ++j)
			dp[i][j] +=
			    dp[i - 1][(j + n - 1) % n] + dp[i - 1][(j + 1) % n];
	cout << dp[m][0] << '\n';
}