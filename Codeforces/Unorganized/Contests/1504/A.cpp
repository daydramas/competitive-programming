#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int j = -1;
		for (int i = 0; i < int(s.length()); ++i)
			if (s[i] != 'a') {
				j = s.length() - i;
				break;
			}
		if (s[s.length() - 1] != 'a') {
			j = 0;
		}
		if (j == -1) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for (int i = 0; i < int(s.length()) + 1; ++i) {
				if (i < j) cout << s[i];
				if (i == j) cout << 'a';
				if (i > j) cout << s[i - 1];
			}
			cout << '\n';
		}

	}
}