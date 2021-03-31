#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

struct L {
	int x;
	L *next;
} *aa[N];

void link(int i, int j) {
	L *l = new L();
	l->x = j;
	l->next = aa[i];
	aa[i] = l;
};

int n, m, dp[N], pp[N];
bool vv[N];

int DP(int x) {
	if (vv[x]) return dp[x];
	if (x == 1) dp[x] = 1;
	for (L *j = aa[x]; j; j = j->next) {
		if (DP(j->x) + 1 > dp[x]) {
			dp[x] = dp[j->x] + 1;
			pp[x] = j->x;
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