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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		long long aa = 0;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			aa += a[i] / x;
			if (a[i] % x != 0)
				aa++;
		}
		long long bb = sum / x;
		if (sum % x != 0)
			bb++;
		cout << min(aa, bb) << ' ' << max(aa, bb) << '\n';
	}
}