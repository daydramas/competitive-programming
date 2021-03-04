/**
 * CF Permutation Transformation
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int n, a[N], b[N], dep[N];

void dfs(int low, int high, int dist) {
	if (low > high)
		return;
	int m = 0;
	for (int i = low; i <= high; i++)
		if (a[i] > a[m])
			m = i;
	dep[m] = dist;
	if (low == high)
		return;
	dfs(low, m - 1, dist + 1);
	dfs(m + 1, high, dist + 1);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	dfs(1, n, 0);
	for (int i = 1; i <= n; i++)
		cout << dep[i] << ' ';
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}