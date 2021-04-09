#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 2 * 200010;

int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}

int dd[N];

int get(int x) {
	return dd[x] < 0 ? x : dd[x] = get(dd[x]);
}

bool merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return 0;
	dd[x] += dd[y], dd[y] = x;
	return 1;
}

int n, m, pa[N], ans[N];

void dfs(int x) {
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != pa[x])
			pa[y] = x, dfs(y);
}

int main() {
	memset(dd, -1, sizeof(dd));

	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d%d", &a, &b);
		if (!merge(a, b)) {
			dfs(a);
			int j = 0;
			while (b) {
				ans[j++] = b;
				b = pa[b];
			}
			ans[j++] = ans[0];
			printf("%d\n", j);
			for (int k = 0; k < j; ++k)
				printf("%d ", ans[k]);
			printf("\n");
			exit(0);
		}
		link(a, b), link(b, a);
	}
	printf("IMPOSSIBLE\n");
}