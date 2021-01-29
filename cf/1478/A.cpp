/**
 * CF 1478A
 * https://codeforces.com/contest/1478/problem/A
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n, x, a[105]; 
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = 0;
		for(int i=0; i<=n; i++) a[i]=0;
		for(int i=0; i<n; i++) {
			cin >> x;
			a[x]++;
			ans = max(ans, a[x]);
		}
		cout << ans << '\n';
	}
}