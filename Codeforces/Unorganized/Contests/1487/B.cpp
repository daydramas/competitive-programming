/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

#define int long long

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n % 2 == 0) {
			k--;
			k %= n;
			cout << 1 + k << '\n';
		} else {
			k = k % (n / 2 * n);
			if (k > 0)
				k--;
			else
				k = (n / 2 * n) - 1;
			int x = n / 2;
			int y = (k % n + k / x) % n + 1;
			// int y = k / x + (k % n);
			// int z = 0;
			// while(y >= n && x > 1) {
			// 	y = y / x + (y % n);
			// }
			// z = (1 + y) % n;
			// if(z == 0) z = n;
			// cout << z << '\n';
			cout << y << '\n';
		}
	}
}