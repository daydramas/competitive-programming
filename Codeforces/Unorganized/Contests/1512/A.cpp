#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		map<int, vector<int>> m;
		int n; cin >> n;

		int i = 1;
		while (n--) {
			int x; cin >> x;
			m[x].push_back(i);
			i++;
		}
		int ans = -1;
		for (auto& x : m) {
			if (x.second.size() == 1)ans = x.second[0];
		}
		cout << ans << '\n';
	}
}