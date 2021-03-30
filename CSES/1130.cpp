#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

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

int n, dp[N][2];

void dfs(int x, int p) {
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		dfs(j->x, x);
		dp[x][0] += max(dp[j->x][0], dp[j->x][1]);
	}
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		dp[x][1] = max(dp[x][1], 1 + dp[j->x][0] + dp[x][0] - max(dp[j->x][0], dp[j->x][1]));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	dfs(1, 0);
	printf("%d\n", max(dp[1][0], dp[1][1]));
}