#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int M = 2 * N;

int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}

int ss[N], pp[N], head[N], pos[N], pi = 0;

int dfs(int x, int p) {
	ss[x] = 1, pp[x] = p;
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != p)
			ss[x] += dfs(y, x);
	return ss[x];
}

void hld(int x, int p, int h) {
	head[x] = h, pos[x] = pi++;
	int cc = -1, vv = 0;
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != p && vv < ss[y])
			vv = ss[y], cc = y;
	if (~cc)
		hld(cc, x, h);
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != p && y != cc)
			hld(y, x, y);
}

int n, v[N], tr[N * 2];

void spull(int i) {
	tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
}

void supdate(int i, int x) {
	tr[i += n] = x;
	for (i >>= 1; i; i >>= 1)
		spull(i);
}

int squery(int l, int r) {
	int ret = 0;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, tr[l++]);
		if (r & 1) ret = max(ret, tr[--r]);
	}
	return ret;
}

int query(int a, int b) {
	int rr = 0;
	while (head[a] != head[b]) {
		if (pos[a] > pos[b]) swap(a, b);
		rr = max(rr, squery(pos[head[b]], pos[b]));
		b = pp[head[b]];
	}
	if (pos[a] > pos[b]) swap(a, b);
	rr = max(rr, squery(pos[a], pos[b]));
	return rr;
}

void init() {
	dfs(0, -1);
	hld(0, -1, 0);
	for (int i = 0; i < n; ++i)
		tr[pos[i] + n] = v[i];
	for (int i = n - 1; i >= 1; --i)
		spull(i);
}

int q;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", v + i);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y); --x, --y;
		link(x, y), link(y, x);
	}
	init();
	int t, a, b;
	while (q--) {
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1) supdate(pos[--a], b);
		else printf("%d ", query(--a, --b));
	}
	printf("\n");
}