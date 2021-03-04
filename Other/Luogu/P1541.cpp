/**
 * Turtle Chess
 * Created on 2021-02-21
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 355
#define M 45

template <class T> bool ckmax(T &a, const T &b) {
	return (a < b ? a = b, 1 : 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, m, a[N], c[5], dp[M][M][M][M];
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int j = 1; j <= m; ++j) {
		int x;
		cin >> x;
		c[x]++;
	}
	int best = 0;
	dp[0][0][0][0] = a[1];
	for (int aa = 0; aa <= c[1]; ++aa)
		for (int bb = 0; bb <= c[2]; ++bb)
			for (int cc = 0; cc <= c[3]; ++cc)
				for (int dd = 0; dd <= c[4]; ++dd) {
					int p = 1 + aa * 1 + bb * 2 + cc * 3 +
						dd * 4;
					if (p > n)
						continue;
					if (aa)
						ckmax(dp[aa][bb][cc][dd],
						      dp[aa - 1][bb][cc][dd] +
							  a[p]);
					if (bb)
						ckmax(dp[aa][bb][cc][dd],
						      dp[aa][bb - 1][cc][dd] +
							  a[p]);
					if (cc)
						ckmax(dp[aa][bb][cc][dd],
						      dp[aa][bb][cc - 1][dd] +
							  a[p]);
					if (dd)
						ckmax(dp[aa][bb][cc][dd],
						      dp[aa][bb][cc][dd - 1] +
							  a[p]);
					if (p == n)
						best = max(best,
							   dp[aa][bb][cc][dd]);
				}
	cout << best << '\n';
}