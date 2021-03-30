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

int n, ss[N];
long long dd[N];

int dfs1(int x, int p, int d) {
	ss[x] = 1, dd[1] += d;
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		ss[x] += dfs1(j->x, x, d + 1);
	}
	return ss[x];
}

void dfs2(int x, int p) {
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		dd[j->x] = dd[x] + n - (ss[j->x] << 1);
		dfs2(j->x, x);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y), link(y, x);
	}
	dfs1(1, 0, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%lld ", dd[i]);
	printf("\n");
}