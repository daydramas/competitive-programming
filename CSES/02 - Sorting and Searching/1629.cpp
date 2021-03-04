/**
 * CSES Movie Festival
 * https://cses.fi/problemset/task/1629
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, a[N], b[N];
	vector<int> ord;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		ord.push_back(i);
	}
	sort(begin(ord), end(ord), [&](int i, int j) {
		if (b[i] == b[j])
			return a[i] > b[j];
		return b[i] < b[j];
	});
	int ans = 0, cur = 0;
	for (int i : ord) {
		if (a[i] >= cur)
			++ans, cur = b[i];
	}
	cout << ans << '\n';
}