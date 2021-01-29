/**
 * Ball in Berland
 * https://codeforces.com/contest/1475/problem/C
*/

#include <iostream>
#include <map>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, a, b, k, x[N], y[N], aa[N], bb[N];
	static long long ans;
	map<int, map<int, int>> m;
	cin >> t;
	while(t--) {
		cin >> a >> b >> k;
		for(int i=1; i<=a; i++) aa[i] = 0;
		for(int i=1; i<=b; i++) bb[i] = 0;
		m.clear();
		for(int i=1; i<=k; i++) {	
			cin >> x[i];
			aa[x[i]]++;
		}
		for(int i=1; i<=k; i++) {
			cin >> y[i];
			bb[y[i]]++;
			m[x[i]][y[i]]++;
		}
		ans = 0;
		for(int i=1; i<=k; i++) {
			ans += k-aa[x[i]]-bb[y[i]]+m[x[i]][y[i]];
		} 
		cout << ans/2 << '\n';
	}
}