#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		vector<int> ch(n + 1);
		int k = r - l + 1;
		bool ok = true;
		for (; k; k--) {
			int i = 1;
			int kk = k, ss = 0;
			for (; i <= n && kk > 1; ++i)
				if (!ch[i]) {
					kk--;
					ss += i;
				}
			int m = -1;
			for (; i <= n; ++i)
				if (!ch[i] && ss + i >= s) {
					m = i; break;
				}
			if (m == -1) {
				ok = false;
				break;
			}
			ch[m] = 1;
			s -= m; 
		}
		if (!ok || s != 0) { cout << "-1\n"; }
		else if (ok) {
			vector<int> q;
			for (int i = 1; i <= n; ++i)
				if (!ch[i]) q.push_back(i);
			for (int i = 1; i < l; ++i) {
				cout << q.back() << ' ';
				q.pop_back();
			}
			for (int i = 1; i <= n; ++i)
				if (ch[i]) cout << i << ' ';
			for (int i : q)cout << i << ' ';
			cout << '\n';
		}
	}

}