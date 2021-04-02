#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; long long k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		if (k - 1) k = 2 + (k % 2);
		for (int _ = 0; _ < k; ++_) {
			int m = -1e9;
			for (int& x : a) m = max(m, x);
			for (int& x : a) x = m - x;
		}
		for (int& x : a) cout << x << ' ';
		cout << '\n';
	}
}