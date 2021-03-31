#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int INF = 0x3f3f3f3f;

int n, L[N], R[N];
long long dp[N][2];

int main() {
	memset(L, 0x3f, sizeof(L));
	memset(R, -0x3f, sizeof(R));

	scanf("%d", &n);
	for (int i = 0, x, c; i < n; ++i) {
		scanf("%d%d", &x, &c);
		L[c] = min(L[c], x);
		R[c] = max(R[c], x);
	}
	L[0] = R[0] = 0;
	memset(dp, 0x3f3f, sizeof(dp));
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		if (L[i] == INF) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			L[i] = L[i - 1];
			R[i] = R[i - 1];
			continue;
		}
		dp[i][0] = min(dp[i - 1][0] + abs(R[i] - L[i - 1]) + R[i] - L[i],
					   dp[i - 1][1] + abs(R[i] - R[i - 1]) + R[i] - L[i]);
		dp[i][1] = min(dp[i - 1][0] + abs(L[i] - L[i - 1]) + R[i] - L[i],
					   dp[i - 1][1] + abs(L[i] - R[i - 1]) + R[i] - L[i]);
	}
	printf("%lld\n", min(dp[n][0] + abs(L[n]), dp[n][1] + abs(R[n])));
}