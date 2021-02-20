/**
 * Collecting Medicine
 * Created on 2021-02-16
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 105
#define M 1005

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, m, w[N], v[N], dp[M];
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	for (int i = 0; i < n; i++)
		for (int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[m] << '\n';
}