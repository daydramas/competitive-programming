#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int M = 18;

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

int n, m, pp[N][M], dd[N], cc[N];

void dfs(int x, int p) {
	pp[x][0] = p, dd[x] = dd[p] + 1;
	for (int i = 1; i < M; ++i)
		pp[x][i] = pp[pp[x][i - 1]][i - 1];
	for (L *y = aa[x]; y; y = y->next)
		if (y->x != p)
			dfs(y->x, x);
}

void dfs2(int x, int p) {
	for (L *y = aa[x]; y; y = y->next)
		if (y->x != p) {
			dfs2(y->x, x);
			cc[x] += cc[y->x];
		}

}

int lca(int a, int b) {
	if (dd[a] < dd[b]) swap(a, b);
	int d = dd[a] - dd[b];
	for (int i = 0; i < M; ++i)
		if ((1 << i) & d)
			a = pp[a][i];
	assert(dd[a] == dd[b]);
	for (int i = M - 1; i >= 0; --i)
		if (pp[a][i] != pp[b][i])
			a = pp[a][i], b = pp[b][i];
	if (a != b)
		a = pp[a][0], b = pp[b][0];
	assert(a == b);
	return a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		link(x, y), link(y, x);
	}
	dfs(1, 0);
	for (int i = 0, x, y, z; i < m; ++i) {
		cin >> x >> y; z = lca(x, y);
		cc[x]++, cc[y]++, cc[z]--;
		cc[pp[z][0]]--;
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		cout << cc[i] << ' ';
	cout << '\n';
}