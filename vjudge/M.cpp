/**
 * M - Coins
*/

#include <iostream>
#include <bitset>
using namespace std;

#define N	105
#define M	(1<<17)
#define dd	bitset<M>

int main() {

	static int n, m, a[N], c[N];
	static int ans = 0;

	dd dp;

	while(1) {
		cin >> n >> m;
		if(n == 0) break;
		for(int i=0; i<n; i++) cin >> a[i];
		for(int i=0; i<n; i++) cin >> c[i];

		dp.reset();
		dp[0] = 1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<=10; j++) {
				if(c[i] >= (1<<j)) {
					int x = a[i] * (1<<j);
					dp |= dp << x;
					c[i] -= (1<<j);
				}
			}
			if(c[i] > 0) {
				int x = a[i] * c[i];
				dp |= dp << x;
				c[i] -= a[i];
			}
		}
		ans = 0;
		for(int i=1; i<=m; i++) {
			if(dp[i]) ans++;
		}
		cout << ans << '\n';
	}
}