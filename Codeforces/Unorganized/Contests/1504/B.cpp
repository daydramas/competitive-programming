#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a; cin >> a;
		string b; cin >> b;
		vector<int> c0(n), c1(n), c(n);
		for (int i = 0; i < n; ++i) {
			if (i != 0) c0[i] = c0[i - 1], c1[i] = c1[i - 1];
			(a[i] == '1' ? ++c1[i] : ++c0[i]);
		}
		int op = 0;
		for (int i = 0; i < n; ++i) {
			// if (op % 2) {
			// 	a[i] = (a[i] == '0' ? '1' : '0');
			// }
			if (a[i] != b[i]) {
				if (c1[i] == c0[i]) {
					c[i]++;
					op++;
				}
			}
		}
		bool ok = 1;
		for (int i = n - 2; i >= 0; --i)
			c[i] += c[i + 1];
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i] && (c[i] % 2 == 1)) ok = 0;
			if (a[i] != b[i] && (c[i] % 2 == 0)) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}