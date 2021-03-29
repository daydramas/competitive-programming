#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
const int M = 1000000007;

int n, dp[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	dp[0] = 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= 6; ++j)
			dp[j + i] = (dp[j + i] + dp[i]) % M;
	cout << dp[n] << '\n';
}