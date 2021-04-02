#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int bit[N];

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}

struct E {
	int y, i;
};
vector<E> qq[N];

int n, q, c[N], oo[N], ans[N];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int i = 0, x, y; i < q; i++) {
		scanf("%d%d", &x, &y);
		qq[x].push_back({y, i});
	}
	for (int i = n; i >= 1; --i) {
		if (oo[c[i]])
			update(oo[c[i]], -1);
		update(oo[c[i]] = i, 1);
		for (const E& e : qq[i]) {
			ans[e.i] = query(e.y);
		}
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
}