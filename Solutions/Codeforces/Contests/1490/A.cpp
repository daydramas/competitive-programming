/**
 * CF Dense Array
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int t, n, a[N];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) cin >> a[i];
		int ans = 0;
		for(int i=1; i<n; i++) {
			int x = min(a[i], a[i-1]);
			int y = max(a[i], a[i-1]);
			while(x * 2 < y) {
				x *= 2;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}