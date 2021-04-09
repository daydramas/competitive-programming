#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, q, dp[N][N];
char s[N][N];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; ++j) {
			if (s[i][j] == '*')
				dp[i][j]++;
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}	
	for (int i = 0, x, y, X, Y; i < q; ++i) {
		scanf("%d%d%d%d", &x, &y, &X, &Y);
		printf("%d\n", dp[X][Y] - dp[X][y - 1] - dp[x - 1][Y] + dp[x - 1][y - 1]);
	}
}