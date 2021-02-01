/**
 * frontmatter
*/

#include <bits/stdc++.h>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	int TC; cin >> TC;
	while(TC--) {
		int n, k;
		cin >> n >> k;
		vector<int> x(n), y(n);
		for(int i=0; i<n; i++) cin >> x[i] >> y[i];
		int ans = -1;
		for(int i=0; i<n; i++) {
			int dist = 0;
			for(int j=0; j<n; j++) {
				dist = max(dist, abs(x[i]-x[j]) + abs(y[i]-y[j]));
			}
			if(dist <= k) { ans = 1; }
		} 
		cout << ans << '\n';

	}
}