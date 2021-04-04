#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		int ab = 0, bb = 0;
		string a, b;
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') { // smae
				if (!ab || !bb) a += '(', b += '(', ab++, bb++;
				else a += ')', b += ')', ab--, bb--;
			} else { // dif	
				if (!ab) a += '(', b += ')', ab++, bb--;
				else if (!bb) a += ')', b += '(', ab--, bb++;
				else if (ab >= bb) a += ')', b += '(', ab--, bb++;
				else a += ')', b += '(', ab--, bb++;
			}
			if (ab < 0 || bb < 0) ok = 0;
		}
		if (ab != 0 || bb != 0) ok = 0;
		if (ok) {
			cout << "YES" << '\n';
			cout << a << '\n' << b << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}