/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll sum = 0;
		queue<pi> cur;
		for (int i = 0; i < n; i++) {
			cur.push({a[i], 1});
		}
		bool should_push = 1;
		while (!cur.empty()) {
			pi f = cur.front();
			cur.pop();
			sum += f.first * f.second;
			if(f.first % x != 0) should_push = 0;
			if(f.first % x == 0 && should_push) {
				cur.push({f.first / x, f.second * x});
			} 
		}
		cout << sum << '\n';
		// for (int i = 0; i < n; i++) {
		// 	long long number = 1;
		// 	sum += a[i] * number;2
		// 	while (a[i] % x == 0) {
		// 		number = number * x;
		// 		a[i] = a[i] / x;
		// 		sum += number * a[i];
		// 	}
		// }
		// cout << sum << '\n';
	}
}