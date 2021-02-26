#include <stdio.h>

#define N 9
#define K (N * N)

#define ones __builtin_popcount

int main() {
	int n, k;
	static long long dp[N][K + 1][1 << N];
	static bool ok[1 << N];

	scanf("%d%d", &n, &k);
	for (int i = 0; i < (1 << n); ++i) {
		if (ones(i) <= k && (i & (i << 1)) == 0
						 && (i & (i >> 1)) == 0) {
			dp[0][ones(i)][i] = ok[i] = 1;
		}
	}
	for (int i = 1; i < n; ++i)
		for (int o = 0; o <= k; ++o)
			for (int j = 0; j < (1 << n); ++j) {
				if (!dp[i - 1][o][j])
					continue;
				if (!ok[j])
					continue;
				for (int l = 0; l < (1 << n); ++l) {
					if (o + ones(l) > k)
						continue;
					if (!ok[l])
						continue;
					if (j & l)
						continue;
					if (j & (l << 1))
						continue;
					if (j & (l >> 1))
						continue;
					dp[i][o + ones(l)][l] +=
					    dp[i - 1][o][j];
				}
			}
	long long ans = 0;
	for (int i = 0; i < (1 << n); ++i) 
		ans += dp[n - 1][k][i];
	printf("%lld\n", ans);
}