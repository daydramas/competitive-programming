/**
 * CSES Stick Lengths
 * https://cses.fi/problemset/task/1074
 * Created on 2021-03-10
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
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int median = a[n / 2];
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += abs(median - a[i]);
	cout << ans << '\n';
}