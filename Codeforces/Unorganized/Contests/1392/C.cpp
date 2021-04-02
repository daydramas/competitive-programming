#include <bits/stdc++.h>
using namespace std;

int dsu[200000], kk[200000];

int get(int x) {
	if (dsu[x] < 0) return dsu[x];
	return dsu[x] = get(dsu[x]);
}
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x != y) dsu[x] += dsu[y], dsu[y] = x, kk[x] = max(kk[x], kk[y]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long x, aa = 0, bb = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x; x += aa;
			if (x >= bb) bb = x;
			else aa += bb - x;
		}
		cout << aa << '\n';
	}
}