#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		while (1) {
			string s = to_string(n);
			int m = 0;
			for (char c : s) m += c - '0';
			if (gcd(n, m) > 1) break;
			n++;
		}
		cout << n << "\n";
	}
}