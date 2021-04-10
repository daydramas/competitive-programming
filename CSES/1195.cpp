#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 200010;

int hh[N], nn[M], tt[M], ei = 0;
long long wt[M];

inline void link(int i, int j, long long w) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j, wt[ei] = w;
}

long long dd[N][2];

void Dijkstra(int st) {
	using E = pair<long long, pair<int, int>>;
	memset(dd, 0x3f, sizeof(dd));

	priority_queue<E, vector<E>, greater<E>> q;
	auto add = [&](int x, int t, long long c) -> bool {
		if (dd[x][t] > c) {
			dd[x][t] = c;
			q.push({c, {x, t}});
			return true;
		}
		return false;
	}; add(st, 0, 0);
	while (!q.empty()) {
		auto [d, f] = q.top(); q.pop();
		auto [x, t] = f;
		if (d > dd[x][t]) continue;
		for (int j = hh[x]; j; j = nn[j]) {
			add(tt[j], t, d + wt[j]);
			if (!t) add(tt[j], 1, d + (wt[j] / 2));
		}
	}
}

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	long long c;
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d%d%lld", &a, &b, &c);
		link(a, b, c);
	}
	Dijkstra(1);
	printf("%lld\n", dd[n][1]);
}