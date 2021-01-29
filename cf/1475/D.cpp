/**
 * Cleaning the Phone
 * https://codeforces.com/contest/1475/problem/D
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n, m, a[N], ai, bi;
	static long long mm = 0;
	vector<int> aa, bb;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		aa.clear();
		bb.clear();
		mm = 0;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			mm += a[i];
		}
		for(int i=1; i<=n; i++) {
			int x; cin >> x;
			if(x == 1) aa.push_back(a[i]);
			else bb.push_back(a[i]);
		}
		if(mm < m) {
			cout << "-1" << '\n';
			continue;
		}
		sort(aa.rbegin(), aa.rend());
		sort(bb.rbegin(), bb.rend());
		for(int i=1; i<bb.size(); i++) bb[i] += bb[i-1];
		int ans = 1e9;
		for(int i=0; i<aa.size(); i++) {
			if(i) aa[i] += aa[i-1];
			int x = 0;
			if(aa[i] >= m || bb.empty()) {
				x = i+1;
			} else {
				// cout << "m="<<m<<" | " << aa[i] << "<- x = " << i+1 << " + " << (int(lower_bound(bb.begin(), bb.end(), m-aa[i])-bb.begin())+1) << " * 2 | lwb = "<<*lower_bound(bb.begin(), bb.end(), m-aa[i])<< "\n";
				x = (i+1) + (int(lower_bound(bb.begin(), bb.end(), m-aa[i])-bb.begin())+1)*2;
			}
			if(x<ans) ans = x;
		}
		if (aa.empty()) for(int i=0; i<bb.size(); i++) {
			int x = 1e9;
			if(bb[i] >= m) {
				x = (i+1)*2;
			}
			if(x<ans) ans = x;
		}
		cout << ans << '\n';

	}
}