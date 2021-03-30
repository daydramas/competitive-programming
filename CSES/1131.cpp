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

int n, ans = 0;

int dfs(int x, int p) {
	int a = 0, b = 0, c;
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x == p) continue;
		c = dfs(j->x, x) + 1;
		if (c > a) b = a, a = c;
		else if (c > b) b = c;
	}
	ans = max(ans, a + b);
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	dfs(1, 0);
	printf("%d\n", ans);
}