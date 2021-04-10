#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; n+=2;
		vector<int> a(n);
		long long ttl = 0;
		for (int &x : a) cin >> x, ttl += x;
		sort(begin(a), end(a));

		// for last element
		ttl -= a.back(); int x = -1;
		for (int i = 0; i < n; ++i) {
			if (i != n - 1 && a.back() == ttl - a[i]) {
				x = i; break;
			}
		}
		if (x != -1) {
			for (int i = 0; i < n; ++i)
				if (i != x && i != n - 1)
					cout << a[i] << ' ';
			cout << '\n';
		} else if (n > 1) {
			ttl += a.back() - a[n - 2]; x = -1;
			for (int i = 0; i < n; ++i) {
				if (i != n - 2 && a[n - 2] == ttl - a[i]) {
					x = i; break;
				}
			}
			if (x != -1) {
				for (int i = 0; i < n; ++i)
					if (i != x && i != n - 2)
						cout << a[i] << ' ';
				cout << '\n';
			} else {
				cout << "-1\n";
			}
		} else {
			cout << "-1\n";
		}


	}
}