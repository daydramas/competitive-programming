#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		sort(begin(a), end(a));
		if (a[0] == a.back()) cout << n << '\n';
		else cout << 1 << '\n';
	}
}