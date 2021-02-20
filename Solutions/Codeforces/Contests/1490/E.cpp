/**
 * CF Accidental Victory
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int t;
	cin >> t;
	while (t--) {
		static int n, a[N];
		map<long long, int> pre;
		map<long long, bool, greater<long long>> ok;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pre[a[i]]++;
		}
		long long pp = 0;
		for (auto &x : pre) {
			pp += x.second;
			x.second = pp;
			ok[x.second] = 0;
		}
		ok[ok.begin()->first] = 1;
		for (auto &x : ok) {
			auto it = ok.lower_bound(pre[x.first]);
			if (it != ok.end() && it->second)
				x.second = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (ok[a[i]])
				cout << i << ' ';
		}
		cout << '\n';
	}
}
