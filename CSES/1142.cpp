#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N], p[N], dsu[N];
long long ans = 0;

int find(int x) {
	if (dsu[x] < 0) return x;
	return dsu[x] = find(dsu[x]);
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	dsu[x] += dsu[y], dsu[y] = x;
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], p[i] = i;
	sort(p + 1, p + n + 1, [&](int i, int j) {
		return a[i] > a[j];
	});

	memset(dsu, -1, sizeof(dsu));
	for (int j = 1, i; j <= n; ++j) {
		i = p[j];
		if (a[i + 1] >= a[i])
			merge(i, i + 1);
		if (a[i - 1] >= a[i])
			merge(i, i - 1);
		ans = max(ans, 1LL * a[i] * -dsu[find(i)]);
	}

	cout << ans << '\n';
}