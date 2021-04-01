#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int K = 41;

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

int n, k, k2, a[N], dd[N][K], pp[N][K], kk[N];

void dfs1(int x, int p) {
	dd[x][0] = a[x];
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x != p) {
			dfs1(j->x, x);
			for (int i = 0; i < k2; ++i)
				dd[x][i] ^= dd[j->x][(i - 1 + k2) % k2];
		}
	}
}
void dfs2(int x, int p) {
	for (int i = 0; i < k2; ++i) pp[x][i] ^= dd[x][i];
	for (int i = k; i < k2; ++i) kk[x] ^= pp[x][i];
	for (L *j = aa[x]; j; j = j->next) {
		if (j->x != p) {
			for (int i = 0; i < k2; ++i)
				pp[j->x][(i + 1) % k2] = pp[x][i] ^ dd[j->x][(i - 1 + k2) % k2];
			dfs2(j->x, x);
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	k2 = k << 1;
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y), link(y, x);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d ", (bool) kk[i]);
	printf("\n");
}