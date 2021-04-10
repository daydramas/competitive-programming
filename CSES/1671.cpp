#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 200010;

int hh[N], nn[M], tt[M], wt[M], ei = 0;

inline void link(int i, int j, int w) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j, wt[ei] = w;
}

long long dd[N];

void dijkstra(int st) {
	using E = pair<long long, int>;
	memset(dd, 0x3f, sizeof(dd));

	priority_queue<E, vector<E>, greater<E>> q;
	auto add = [&](int x, long long c) -> bool {
		if (dd[x] > c) {
			dd[x] = c;
			q.push({c, x});
			return true;
		}
		return false;
	}; add(st, 0);
	while (!q.empty()) {
		auto [d, x] = q.top(); q.pop();
		if (d > dd[x]) continue;
		for (int j = hh[x]; j; j = nn[j])
			add(tt[j], d + wt[j]);
	}
}

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b, w; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &w);
		link(a, b, w);
	}
	dijkstra(1);
	for (int i = 1; i <= n; ++i)
		printf("%lld ", dd[i]);
	printf("\n");
}