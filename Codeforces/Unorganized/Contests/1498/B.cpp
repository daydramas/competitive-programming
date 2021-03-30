#include <bits/stdc++.h>
using namespace std;

int p2[31], c[31];

void curse(int i, int v) {
	if (i < 0 || v == 0) return;
	int num = min(c[i], v / p2[i]);
	c[i] -= num; v -= p2[i] * num;
	curse(i - 1, v);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	p2[0] = 1;
	for (int i = 1; i <= 30; ++i)
		p2[i] = p2[i - 1] * 2;
	while (t--) {
		int n, w;
		cin >> n >> w;
		memset(c, 0, sizeof(c));
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			int y = 0;
			while (x % 2 == 0) x /= 2, y++;
			c[y]++;
		}
		int ans = 0;
		for (int i = 30; i >= 0; --i) {
			while (c[i]) {
				curse(i, w);
				ans++;
			}
		}
		cout << ans << '\n';
	}
}