#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 2 * N;

int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}

int n, m, dp[N], pp[N];
bool vv[N];

int DP(int x) {
	if (vv[x]) return dp[x];
	if (x == 1) dp[x] = 1;
	for (int j = hh[x]; j; j = nn[j]) {
		if (DP(tt[j]) + 1 > dp[x]) {
			dp[x] = dp[tt[j]] + 1;
			pp[x] = tt[j];
		}
	}
	return vv[x] = 1, dp[x];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d%d", &a, &b);
		link(b, a);
	}
	memset(dp, -0x3f, sizeof(dp));
	if (DP(n) < 0) {
		puts("IMPOSSIBLE");
	} else {
		printf("%d\n", dp[n]);
		static int a[N];
		int i = dp[n] - 1, x = n;
		while (x) {
			a[i--] = x;
			x = pp[x];
		}
		for (int i = 0; i < dp[n]; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
}