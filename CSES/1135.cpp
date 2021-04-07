#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int D = 18;

int hd[N], nx[N * 2], to[N * 2], ei = 0;

inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}

int n, q, d[N], up[N][D];

void dfs(int x, int p) {
	up[x][0] = p;
	for (int j = 1; j < D; ++j)
		up[x][j] = up[up[x][j - 1]][j - 1];
	for (int j = hd[x], y; j; j = nx[j])
		if ((y = to[j]) != p) {
			d[y] = d[x] + 1;
			dfs(y, x);
		}
}

int jump(int x, int k) {
	for (int i = 0; i < D; ++i)
		if (k & (1 << i))
			x = up[x][i];
	return x;
}

int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	x = jump(x, d[x] - d[y]);
	for (int j = D - 1; j >= 0; --j)
		if (up[x][j] != up[y][j])
			x = up[x][j], y = up[y][j];
	if (x != y) x = up[x][0], y = up[y][0];
	return x;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int j = 1, x, y; j < n; ++j) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	d[1] = 0;
	dfs(1, 0);
	
	int x, y;
	while (q--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", d[x] + d[y] - 2 * d[lca(x, y)]);
	}	
}