/**
 * problem-name
 * problem-link
*/

#include <iostream>
#include <vector>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n, a[N], x;
	cin >> t;
	while(t--) {
		cin >> n;
		x = 0;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			x += a[i];
		}
		if(x % n) {
			cout << "-1\n";
		} else {
			vector<vector<int>> ans;
			for(int i=2; i<=n; i++) {
				if(a[i] % i) {
					ans.push_back({1, i, i-a[i]%i});
					a[i] += i-a[i]%i;
				}
				ans.push_back({i, 1, a[i]/i});
			}
			for(int i=2; i<=n; i++) {
				ans.push_back({1, i, x/n});
			}
			cout << ans.size() << '\n';
			for(auto x : ans) cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
		}
	}
}