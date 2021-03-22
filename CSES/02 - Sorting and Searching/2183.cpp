/**
 * CSES Missing Coin Sum
 * https://cses.fi/problemset/task/2183
 * Created on 2021-03-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	static int a[N];

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[1] != 1) {
		puts("1");
	} else {
		long long pref = 1;
		for (int i = 2; i <= n; ++i) {
			if (pref < a[i] - 1) {
				cout << pref + 1 << '\n';
				return 0;
			}
			pref += a[i];
		}
	}
}