#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct D {
	int x, p;
} aa[N];

int n, bit[N];

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans = max(ans, bit[i]);
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	while (i < N) {
		bit[i] = max(bit[i], x);
		i += i & (-i);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aa[i].x; aa[i].p = i + 1;
	}
	sort(aa, aa + n, [](const D &i, const D &j) {
		if (i.x == j.x) return i.p > j.p;
		return i.x < j.x;
	});
	for (int j = 0, i; j < n; ++j) {
		i = aa[j].p;
		update(i, query(i - 1) + 1);
	}
	cout << query(N - 1) << '\n';
}