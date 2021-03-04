#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

#define N              15
#define MOD            1000000000
#define f(i, a, b)     for (int i = (a); i < (b); ++i)
#define rf(i, a, b)    for (int i = (b) - 1; i >= a; --i)
#define mem(x, a)      memset(x, a, sizeof(x))
#define as(b)          assert(b)


int main() {

	int n, m;
	int a[N][N], ok[N][1 << N], dp[N][1 << N];
	mem(a, 0); mem(dp, 0); mem(ok, 0);

	scanf("%d%d", &n, &m);
	as(n && m);
	f(i, 0, n) {
		f(j, 0, m) {
			scanf("%d", &a[i][j]);
			as(a[i][j] == 0 || a[i][j] == 1);
		}
		f(j, 0, 1 << m) {
			ok[i][j] = 1;
			f(k, 0, m)
				if (!a[i][k] && (j & 1 << k))
					ok[i][j] = 0;
			if (j & j << 1)
				ok[i][j] = 0;
		}
	}
	f(i, 0, 1 << m)
		dp[0][i] = ok[0][i];

	f(i, 1, n) f(j, 0, 1 << m) if (ok[i][j]) {
		f(k, 0, 1 << m) {
			if (j & k) continue;
			if (!ok[i - 1][k]) continue;
			dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
		}
	}
	int ans = 0;
	f(i, 0, 1 << m) {
		ans = (ans + dp[n - 1][i]) % MOD;
	}
	printf("%d\n", ans);

}