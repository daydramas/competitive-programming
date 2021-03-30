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

int n, a[N], b[N], c[N], up[N], ans[N];

int dfs1(int x, int p) {
	int d;
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		d = dfs1(j->x, x) + 1;
		if (d > a[x]) b[x] = a[x], a[x] = d, c[x] = j->x;
		else if (d > b[x]) b[x] = d;
	}
	return a[x];
}

void dfs2(int x, int p) {
	ans[x] = a[x];
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		up[j->x] = up[x] + 1;
		if (c[x] == j->x) up[j->x] = max(up[j->x], b[x] + 1); 
		else up[j->x] = max(up[j->x], a[x] + 1);
		dfs2(j->x, x);
		ans[j->x] = max(ans[j->x], up[j->x]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	dfs1(1, 0); dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}