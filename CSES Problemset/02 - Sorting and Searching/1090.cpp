/*
============================================================================
 Name:		CSES Ferris Wheel
 Link:		https://cses.fi/problemset/task/1090
 Author:	Dong Liu
 Date:		2021-02-13
============================================================================
*/

#include <algorithm>
#include <iostream>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, x, a[N];
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0, lo = 0, hi = n - 1;
	while (lo <= hi) {
		if (a[lo] + a[hi] <= x) {
			++lo, --hi, ++ans;
		} else {
			--hi, ++ans;
		}
	}

	cout << ans << '\n';
}