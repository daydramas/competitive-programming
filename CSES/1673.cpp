#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
const int M = 5005;

int hh[N], nn[M], tt[M], ei1 = 0;

inline void link1(int i, int j) {
	nn[++ei1] = hh[i], hh[i] = ei1, tt[ei1] = j;
}

bool used[N];

void dfs(int x) {
	if (used[x]) return; used[x] = 1;
	for (int j = hh[x]; j; j = nn[j])
		dfs(tt[j]);
}

struct E {
    int a, b, c;
} e[M];

const long long inf = 0x3f3f3f3f3f3f3f3fLL;

int n, m, ei = 0;
long long dd[N];

void link2(int a, int b, int c) {
	e[ei++] = {a, b, c};
}

bool BellmanFord(int x) {
	memset(dd, 0x3f, sizeof(dd));
	dd[x] = 0; bool upd = 0;
	for (int i = 0; i < n; ++i) {
		upd = 0;
        for (int j = 0, a, b; j < m; ++j)
			if (used[a = e[j].a] && used[b = e[j].b])
				if (dd[a] != inf && dd[a] + e[j].c < dd[b])
					dd[b] = dd[a] + e[j].c, upd = 1;
		if (!upd) break;
	}
	return !upd;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b, c; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		link1(b, a), link2(a, b, -c);
	}
	dfs(n);
	if (BellmanFord(1)) printf("%lld\n", -dd[n]);
	else printf("-1\n");
}