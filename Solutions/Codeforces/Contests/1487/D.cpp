/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		ll ans = 0;
		ll n;
		cin >> n;
		n *= 2;
		for (ll x = 2; x * x <= n; x++) {
			ll y = x * x;
			if (y & 1)
				ans++;
		}
		cout << ans << '\n';
	}
}