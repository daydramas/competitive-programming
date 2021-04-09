#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, dp[N];

int main() {
	scanf("%d", &n);

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;

	for (int i = 1, j; i <= n; ++i) {
		j = i;
		while (j) {
			dp[i] = min(dp[i], dp[i - (j % 10)] + 1);
			j /= 10;
		}
	}
	printf("%d\n", dp[n]);
}