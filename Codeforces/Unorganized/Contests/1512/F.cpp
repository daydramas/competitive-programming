#include <bits/stdc++.h>
using namespace std;

#define int long long

int cdiv(int a, int b) {
	if (a < 0)return 0;
	return (a + b - 1) / b;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<int> a(n), b(n - 1);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		int p = 0, d = 0, f = 0;
		while (p < n) {
			// cout << "p = " << p << " | f = " << f << " | d = " << d << '\n';
			if (p == n - 1) {
				f += cdiv(c - d, a[p]);
				break;
			} else {
				int x = cdiv(c - d, a[p]);
				int y = cdiv(b[p] - d, a[p]);
				int z = d + (y * a[p]) - b[p];
				y += cdiv(c - z, a[p + 1]);
				if (x < y) {
					f += x;
					break;
				} else {
					y -= cdiv(c - z, a[p + 1]);
					f += cdiv(b[p] - d, a[p]);
					d = d + (y * a[p]) - b[p];
					p++;
				}
			}
		}
		cout << f << " " << d  << '\n';
	}
}