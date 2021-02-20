/**
 * CSES Restaurant Customers
 * https://cses.fi/problemset/task/1619
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pi = pair<int,int>; 

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, a[N], b[N];
	vector<pi> e;
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i] >> b[i];
		e.push_back({a[i], 1});
		e.push_back({b[i], -1});
	}
	sort(begin(e), end(e));
	int ans = 0, cur = 0;
	for (pi x : e) {
		cur += x.second;
		if(cur > ans) ans = cur;
	}
	cout << ans << '\n';

}