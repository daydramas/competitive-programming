#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 10010;

int a[N], b[N];

long long dp[M];

int main() {
	int h, n;
	scanf("%d%d", &h, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", a + i, b + i);
	memset(dp, 0x3f3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			dp[min(h, i + a[j])] = min(dp[min(h, i + a[j])], dp[i] + b[j]);
	printf("%lld\n", dp[h]);
}