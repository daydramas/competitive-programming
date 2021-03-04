/**
 * T - Charm Bracelet
*/

#include <iostream>
using namespace std;

#define N	3402
#define M	12885

template <class T> bool ckmax(T& a, const T& b) { 
	return b > a ? a = b, 1 : 0; 
}

int main() {

	static int n, m, w, d, dp[M];
	
	cin >> n >> m;

	dp[0] = 0;
	for(int i=0; i<n; i++) {
		cin >> w >> d;
		for(int j=m; j>=w; j--) {
			ckmax(dp[j], dp[j-w] + d);
		}
	}
	int ans = 0;
	for(int i=0; i<=m; i++) ckmax(ans, dp[i]);
	cout << ans << '\n';
}