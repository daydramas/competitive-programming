#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		static int n;
		static int x[100000];
		map<int, int> m;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
			++m[x[i]];
		int ans = 0;
		for (auto x : m) {
			if (x.second > 1) {
				m[x.first + 1]++;
				m[x.first]--;
			}
		}
		for (auto x : m) {
			if (x.second) ans++;
		}
		cout << ans << '\n';
	}
}