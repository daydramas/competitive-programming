/**
 * CF Easter Exhibition
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int t, n, x[N], y[N]; 
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
		multiset<pair<int,int>> s, ss;
		for(int i=0;i<n;i++) {
			s.insert({x[i], y[i]});
			ss.insert({y[i], x[i]});
		}
		if(s.size() & 1) {
			cout << 1 << '\n';
			continue;
		}
		vector<pair<int,int>> v, vv;
		for(pair<int,int> xx : s) {
			v.push_back(xx);
		}
		for(pair<int,int> xx : ss) {
			vv.push_back(xx);
		}
		long long ans = 1LL * (v[v.size() / 2].first - v[v.size() / 2 - 1].first + 1)
						* (vv[vv.size() / 2].first - vv[vv.size() / 2 - 1].first + 1);
		cout << ans << '\n';
	}
}