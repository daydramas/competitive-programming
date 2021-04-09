#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 2 * 200010;

int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}

int n, m, c[N];

void dfs(int x) {
	for (int j = hh[x], y; j; j = nn[j])
		if (c[y = tt[j]] == c[x])
			puts("IMPOSSIBLE"), exit(0);
		else if (c[y] == -1)
			c[y] = 1 - c[x], dfs(y);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d%d", &a, &b);
		link(a, b), link(b, a);
	}
	memset(c, -1, sizeof(c));
	for (int i = 1; i <= n; ++i)
		if (c[i] == -1)
			c[i] = 0, dfs(i);
	for (int i = 1; i <= n; ++i)
		printf("%d ", c[i] + 1);
	printf("\n");
}